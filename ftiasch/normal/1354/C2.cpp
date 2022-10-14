#include <bits/stdc++.h>

const double PI = acos(-1.);

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    double r = 0.5 / sin(PI / (2 * n));
    double low = 0.;
    double high = r;
    for (int _ = 0; _ < 100; ++_) {
      double x = 0.5 * (low + high);

      double a0 = acos(std::min(x / r, 1.0));
      double theta = PI / n;
      bool check = true;
      for (int i = 0; i < n && check; ++i) {
        double a = a0 + theta * i;
        check &= std::abs(cos(a) * r) <= x;
        check &= std::abs(sin(a) * r) <= x;
      }
      if (check) {
        high = x;
      } else {
        low = x;
      }
    }
    printf("%.9f\n", low + high);
  }
}