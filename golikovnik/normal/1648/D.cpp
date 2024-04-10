//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector a(3, vector<ll>(n+1));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      int x; cin >> x; a[i][j + 1] = x;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j + 1] += a[i][j];
    }
  }

  auto Sum = [&](int i, int l, int r) {
    return a[i][r] - a[i][l];
  };

  vector<ll> f(n), g(n);
  for (int i = 0; i < n; ++i) {
    f[i] = Sum(0, 0, i+1) - Sum(1, 0, i);
    g[i] = Sum(1, 0, i+1) + Sum(2, i, n);
  }

  ll ans = LLONG_MIN;

  vector<vector<pair<int, ll>>> segments(n);
  for (int i = 0; i < q; ++i) {
    int l, r, w;
    cin >> l >> r >> w;
    segments[r - 1].emplace_back(l - 1, w);
  }

  static ll const INF = ll(1e17);
  struct node {
    ll maxF = -INF;
    ll maxG = -INF;
    ll res = -INF;
    ll dp = -INF;
    ll resDP = -INF;

    node operator+(node const& other) const {
      node ans{};
      ans.maxF = max(maxF, other.maxF);
      ans.maxG = max(maxG, other.maxG);
      ans.res = max({res, other.res, maxF + other.maxG});
      ans.dp = max(dp, other.dp);
      ans.resDP = max({resDP, other.resDP, dp + other.maxG});
      return ans;
    }
  };
  int pw = 1;
  while (pw <= n) pw *= 2;
  vector<node> tree(2 * pw);
  for (int i = 0; i < n; ++i) {
    tree[pw + i].maxF = f[i];
    tree[pw + i + 1].maxG = g[i];
  }
  for (int i = pw - 1; i > 0; --i) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  auto Query = [&](int ql, int qr) {
    node resL{};
    node resR{};
    for (ql += pw, qr += pw; ql < qr; ql /= 2, qr /= 2) {
      if (ql & 1) {
        resL = resL + tree[ql++];
      }
      if (qr & 1) {
        resR = tree[--qr] + resR;
      }
    }
    return resL + resR;
  };

  auto UpdDP = [&](int i, ll val) {
    for (smax(tree[i += pw].dp, val); i /= 2; ) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  };

  for (int r = 0; r < n; ++r) {
    for (auto[l, w] : segments[r]) {
      smax(ans, Query(l, r + 2).res - w);
      smax(ans, Query(max(0, l - 1), r + 2).resDP - w);
    }
    for (auto[l, w] : segments[r]) {
      UpdDP(r, max(Query(l, r + 1).maxF, Query(max(0, l - 1), r + 1).dp) - w);
    }
  }

  cout << ans << '\n';

  // for (int i = 0; i < n; ++i) {
  //   vector<ll> fenw(n+1, INF);

  //   auto Upd = [&](int x, ll w) {
  //     x = n - x;
  //     for (; x <= n; x |= x + 1) {
  //       smin(fenw[x], w);
  //     }
  //   };
  //   auto Get = [&](int x) {
  //     x = n - x;
  //     ll res = INF;
  //     for (; x >= 0; x = (x & (x + 1)) - 1) {
  //       smin(res, fenw[x]);
  //     }
  //     return res;
  //   };

  //   for (int j = 0; j <= i; ++j) {
  //     Upd(j, 0);
  //   }

  //   for (int l = 0; l < n; ++l) {
  //     for (auto[r, w] : segments[l]) {
  //       Upd(r+1, Get(l) + w);
  //     }
  //   }

  //   for (int j = i; j < n; ++j) {
  //     smax(ans, f[i] + g[j] - Get(j+1));
  //   }
  // }

  // cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}