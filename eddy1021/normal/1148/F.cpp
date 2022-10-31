#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
constexpr int K = 62;
typedef long long LL;
typedef unsigned long long LLU;
LL n, val[N];
LLU mask[N];
inline int sgn(LL x) {
  return (x > 0) - (x < 0);
}
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%llu", &val[i], &mask[i]);
  }
  LL init = accumulate(val, val + n, 0LL);
  LLU ans = 0;
  for (int i = 0; i < K; ++i) {
    LL v[2] = {};
    for (int j = 0; j < n; ++j) {
      if (mask[j] < (1LLU << (i + 1))) {
        for (LL b = 0; b < 2; ++b) {
          v[b] += __builtin_parityll(mask[j] & (ans | (b << i))) ? -val[j] : val[j];
        }
      }
    }
    if (sgn(v[1] - v[0]) * sgn(init) == -1) {
      ans |= (1LLU << i);
    }
  }
  printf("%llu\n", ans);
}