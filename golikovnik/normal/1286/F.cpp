#include <bits/stdc++.h>

using namespace std;

using uint = unsigned;
using i64 = int64_t;
using ui64 = uint64_t;

uint const N = 1u << 20u;

i64 sum[N];
uint ppc[N], bit[N], dp[N];
bitset<N> ok;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint n;
  cin >> n;
  vector<i64> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  uint const MASK = 1u << n;
  {
    uint bt = 0;
    for (uint i = 1; i < MASK; ++i) {
      if (i == 1u << (bt + 1)) {
        ++bt;
      }
      bit[i] = bt;
      sum[i] = a[bt] + sum[i ^ (1u << bt)];
      ppc[i] = 1 + ppc[i ^ (1u << bt)];
    }
  }
  for (uint m = 1; m < MASK; ++m) {
    auto k = ppc[m];
    if (((sum[m] - k) & 1) == 0) {
      continue;
    }
    for (uint s = (m - 1u) & m; s; s = (s - 1u) & m) {
      auto diff = sum[m] - 2 * sum[s];
      if (diff < 0) {
        diff = -diff;
      }
      if (diff < k) {
        ok[m] = true;
        break;
      }
    }
  }
  auto relax = [](uint& x, uint y) {
    if (y < x) {
      x = y;
    }
  };
  for (uint i = 1; i < MASK; ++i) {
    if (ppc[i] == 1) {
      dp[i] = bool(a[bit[i]]);
      continue;
    }
    dp[i] = ppc[i] - ok[i];
    for (uint s = (i - 1u) & i; s; s = (s - 1u) & i) {
      relax(dp[i], dp[s] + dp[i & ~s]);
    }
  }
  cout << dp[MASK - 1] << '\n';
  return 0;
}