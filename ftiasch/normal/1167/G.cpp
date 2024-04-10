#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;
const int D = 7000;

double fast_atan2[D + 1];
int a[N];

int main() {
  //   int d = 7000;
  //   while (atan2(1, d) * 2 >= atan2(1, 3500)) {
  //     d++;
  //   }
  //   printf("%d\n", d); // 7000
  //   for (int d = 1; d <= D; ++d) {
  //     int n = 2 * d;
  //     while (atan2(1, n) * 2 >= atan2(1, d)) {
  //       n++;
  //     }
  //     std::cout << n - 2 * d << std::endl;
  //   }
  for (int d = 0; d <= D; ++d) {
    fast_atan2[d] = atan2(1, d);
  }
  int n, q;
  scanf("%d%*d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  int index = 0;
  while (q--) {
    int x;
    scanf("%d", &x);
    while (index < n && a[index] < x) {
      index++;
    }
    int mind = INT_MAX;
    if (index) {
      mind = std::min(mind, x - (a[index - 1] + 1));
    }
    if (index < n) {
      mind = std::min(mind, a[index] - x);
    }
    double result = fast_atan2[mind];
    int left = index - 1;
    int right = index;
    while (left >= 0 && right < n) {
      int ld = x - (a[left] + 1);
      int rd = a[right] - x;
      if (std::max(ld, rd) > 2 * mind) {
        break;
      }
      if (std::abs(ld - rd) <= 1) {
        result = std::max(result, 2 * fast_atan2[std::max(ld, rd)]);
        break;
      }
      if (ld < rd) {
          left --;
      } else {
          right ++;
      }
    }
    printf("%.15f\n", result);
  }
}