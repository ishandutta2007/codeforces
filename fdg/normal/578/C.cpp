#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

int arr[200002];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  double l = -2e+10, r = 2e+10;
  // for (int it = 0; it < 100; ++it) {
  //   double m = (l + r) / 2;

  //   double L = -2e+12, R = -L;
    
  //   {
  //     double ms = 0, cs = 0, pos = -1;
  //     for (int i = 0; i < n; ++i) {
  //       cs += arr[i];

  //       L = max(L, (cs - ms - m) / (i - pos));
  //       R = min(R, (cs - ms + m) / (i - pos));
      
  //       if (cs > ms) {
  //         ms = cs;
  //         pos = i;
  //       }
  //     }
  //   }

  //   {
  //     double ms = 0, cs = 0, pos = -1;
  //     for (int i = 0; i < n; ++i) {
  //       cs += arr[i];

  //       L = max(L, (cs - ms - m) / (i - pos));
  //       R = min(R, (cs - ms + m) / (i - pos));
      
  //       if (cs < ms) {
  //         ms = cs;
  //         pos = i;
  //       }
  //     }
  //   }

  //   if (L <= R) r = m;
  //   else l = m;
  // }

  double ans = 1e+12;

  for (int it = 0; it < 200; ++it) {
    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;

    double val1 = 0;    
    {
      double ms = 0, cs = 0;
      for (int i = 0; i < n; ++i) {
        cs += arr[i] - m1;

        val1 = max(val1, fabs(cs - ms));

        if (cs > ms) {
          ms = cs;
        }
      }
    }
    {
      double ms = 0, cs = 0;
      for (int i = 0; i < n; ++i) {
        cs += arr[i] - m1;

        val1 = max(val1, fabs(cs - ms));

        if (cs < ms) {
          ms = cs;
        }
      }
    }

    double val2 = 0;
    {
      double ms = 0, cs = 0;
      for (int i = 0; i < n; ++i) {
        cs += arr[i] - m2;

        val2 = max(val2, fabs(cs - ms));

        if (cs > ms) {
          ms = cs;
        }
      }
    }
    {
      double ms = 0, cs = 0;
      for (int i = 0; i < n; ++i) {
        cs += arr[i] - m2;

        val2 = max(val2, fabs(cs - ms));

        if (cs < ms) {
          ms = cs;
        }
      }
    }
    

    if (val1 < val2) r = m2;
    else l = m1;

    ans = min(ans, min(val1, val2));
  }
  printf("%.10lf\n", ans);
  return 0;
}