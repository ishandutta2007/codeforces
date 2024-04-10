#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {

  //   const int N = 100;
  //   for (int a = 1; a <= N; ++a) {
  //     for (int b = a; b <= N; ++b) {
  //       int count = 0;
  //       for (int x = 0; x < a * b; ++x) {
  //         count += x % a % b == x % b % a;
  //       }
  //       if (b % a != 0) {
  //         printf("%d %d %d\n", a, b, count);
  //       }
  //     }
  //   }
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, q;
    scanf("%d%d%d", &a, &b, &q);
    if (a > b) {
      std::swap(a, b);
    }
    std::vector<int> er;
    if (b % a != 0) {
      for (int r = 0; r < a * b; ++r) {
        if (r % a % b == r % b % a) {
          er.push_back(r);
        }
      }
    }
    for (int i = 0; i < q; ++i) {
      long long l, r;
      scanf("%lld%lld", &l, &r);
      long long result = 0;
      if (b % a != 0) {
        l--;
        result = r - l;
        for (int x : er) {
          if (x <= r) {
            result -= (r - x) / (a * b) + 1;
          }
          if (x <= l) {
            result += (l - x) / (a * b) + 1;
          }
        }
      }
      printf("%lld%c", result, " \n"[i + 1 == q]);
    }
  }
}