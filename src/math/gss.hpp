#ifndef __nobb__math__gss__hpp
#define __nobb__math__gss__hpp

#include "gss.h"

template <typename type, typename std :: enable_if <gss :: valid <type> :: value> :: type *> double gss :: min(const type & f, double a, double b)
{
  static const double ratio = (sqrt(5.) + 1.) / 2.;

  double c = b - (b - a) / ratio;
  double d = a + (b - a) / ratio;

  while(fabs(c - d) > epsilon)
  {
    if(f(c) < f(d))
      b = d;
    else
      a = c;

      c = b - (b - a) / ratio;
      d = a + (b - a) / ratio;
  }

  return (b + a) / 2.;
}

template <typename type, typename std :: enable_if <gss :: valid <type> :: value> :: type *> double gss :: max(const type & f, double a, double b)
{
  static const double ratio = (sqrt(5.) + 1.) / 2.;

  double c = b - (b - a) / ratio;
  double d = a + (b - a) / ratio;

  while(fabs(c - d) > epsilon)
  {
    if(f(c) > f(d))
      b = d;
    else
      a = c;

      c = b - (b - a) / ratio;
      d = a + (b - a) / ratio;
  }

  return (b + a) / 2.;
}

#endif
