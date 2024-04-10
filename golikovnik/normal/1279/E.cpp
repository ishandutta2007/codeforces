#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ui64 const INF = (ui64) 2e18;
  auto add = [INF](ui64 a, ui64 b) {
    return min(a + b, INF);
  };
  auto mul = [INF](ui64 a, ui64 b) -> ui64 {
    if (!b) {
      return 0;
    }
    if (a > INF / b) {
      return INF;
    }
    return min(INF, a * b);
  };

  int const N = 51;
  vector<ui64> fact(N);
  fact[0] = 1;
  for (int i = 0; i + 1 < N; ++i) {
    fact[i + 1] = mul(fact[i], i + 1);
  }
  auto get_ncycles = [&](int k) {
    return k < 2 ? 1 : fact[k - 2];
  };
  vector<ui64> dp(N);
  dp[0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int cyc = 1; cyc <= i; ++cyc) {
      dp[i] = add(dp[i], mul(get_ncycles(cyc), dp[i - cyc]));
    }
  }
  auto fetch_cycle = [&](int n, ui64 left) -> vector<int> {
    vector<bool> used(n);
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int v) {
      return p[v] == v ? v : p[v] = find(p[v]);
    };
    auto cyc = [&](int v, int u) {
      return find(u) == v;
    };
    auto unite = [&](int v, int u) {
      p[v] = u;
    };
    vector<int> ans(n);
    auto put = [&](int pos, int who) {
      ans[pos] = who;
      unite(pos, who);
      used[who] = true;
    };
    put(0, n - 1);
    for (int i = 1; i < n; ++i) {
      for (int who = 0; who < n; ++who) {
        if (used[who]) {
          continue;
        }
        if (i == n - 1) {
          put(i, who);
          break;
        }
        if (cyc(i, who)) {
          continue;
        }
        auto k = fact[n - i - 2];
        if (k > left) {
          put(i, who);
          break;
        } else {
          left -= k;
        }
      }
    }
    return ans;
  };
  function<vector<int>(int, ui64)> rec = [&](int n, ui64 left)
          -> vector<int> {
    if (!n) {
      return {};
    }
    for (int k = 1; k <= n; ++k) {
      auto cnt = get_ncycles(k);
      auto suff = dp[n - k];
      auto ways = mul(cnt, suff);
      if (ways > left) {
        auto id = left / suff;
        left -= id * suff;
        auto cyc = fetch_cycle(k, id);
        auto rest = rec(n - k, left);
        for (auto& x : rest) {
          x += k;
        }
        cyc.insert(cyc.end(), rest.begin(), rest.end());
        return cyc;
      }
      left -= ways;
    }
    throw;
  };
  int t;
  cin >> t;
  while (t--) {
    ui64 n, k;
    cin >> n >> k;
    --k;
    if (dp[n] <= k) {
      cout << "-1\n";
      continue;
    }
    for (auto x : rec(n, k)) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}