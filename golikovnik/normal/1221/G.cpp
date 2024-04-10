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

  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<ll> maskNxt(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    maskNxt[u] |= 1ll << v;
    maskNxt[v] |= 1ll << u;
  }

  int left = n / 2;
  int right = n - left;
  vector<char> goodLeft(1 << left), goodRight(1 << right);

  auto calc = [&](auto& out, int l, int r) {
    int len = r - l;
    for (int msk = 0; msk < (1 << len); ++msk) {
      bool good = true;
      for (int v = 0; v < len; ++v) {
        if (msk >> v & 1) {
          if ((maskNxt[l + v] >> l) & msk) {
            good = false; break;  
          }
        }
      }
      out[msk] = good;
    }
  };

  calc(goodLeft, 0, left);
  calc(goodRight, left, n);
  ll maskLeft = (1ll << left) - 1;
  ll maskRight = ((1ll << right) - 1) << left;

  vector<ll> submask(1 << right);
  for (int msk = 0; msk < (1 << right); ++msk) {
    submask[msk] = goodRight[msk];
  }
  for (int b = 0; b < right; ++b) {
    for (int msk = 0; msk < (1 << right); ++msk) {
      if (msk >> b & 1) {
        submask[msk] += submask[msk ^ (1 << b)];
      }
    }
  }

  vector<ll> adjMask(1 << left);

  {
    int bit = 0;
    for (int msk = 1; msk < (1 << left); ++msk) {
      if (msk == (1 << (bit + 1))) {
        ++bit;
      }
      adjMask[msk] =
        adjMask[msk ^ (1 << bit)]
        | (maskNxt[bit] >> left);
    }
  }

  vector<int> used(n);
  vector<ll> ans(8);
  ans[0] = 1;

  int c00 = 1;
  int c01 = 2;
  int c11 = 4;

  int nv = 0;
  bool bipartite = true;
  vector<int> comp;

  auto calcIS = [&] {
    ll maskAll = 0;
    for (int v : comp) {
      maskAll |= 1ll << v;
    }
    ll maskL = maskAll & maskLeft;
    ll maskR = (maskAll & maskRight) >> left;
    ll res = 0;
    for (int msk = 0; msk < (1 << left); ++msk) {
      if ((msk & maskL) != msk) {
        continue;
      }
      if (!goodLeft[msk]) {
        continue;
      }
      ll banned = adjMask[maskL & msk];
      ll good = (((1ll << right) - 1) ^ banned) & maskR;
      res += submask[good];
      // debug(msk);
      // debug(maskL);
      // debug(maskR);
      // debug(banned);
      // debug(good);
      // debug(submask[good]);
    }
    return res;
  };

  auto dfs = [&](auto&& self, int v, int c) -> void {
    used[v] = c;
    comp.push_back(v);
    ++nv;
    for (int u : graph[v]) {
      if (!used[u]) {
        self(self, u, 3 - c);
      } else if (used[u] != 3 - c) {
        bipartite = false;
      }
    }
  };

  for (int root = 0; root < n; ++root) {
    if (used[root]) {
      continue;
    }

    nv = 0;
    bipartite = true;
    comp.clear();
    dfs(dfs, root, 1);
    if (nv == 1) {
      for (auto& x : ans) x *= 2;
      continue;
    }

    vector<ll> cur(8);

    cur[c00] = 1;
    cur[c11] = 1;
    cur[c01] = 2 * bipartite;
    auto nis = calcIS() - 1;
    nis -= cur[c01];

    // cerr << nv << ' ' << bipartite << ' ' << nis << '\n';

    cur[c00 | c01] = nis;
    cur[c11 | c01] = nis;
    cur[7] = (1ll << nv) -
      accumulate(cur.begin(), cur.begin() + 7, 0ll);

    vector<ll> nans(8);
    for (int x = 0; x < 8; ++x) {
      for (int y = 0; y < 8; ++y) {
        nans[x | y] += ans[x] * cur[y];
      }
    }

    ans = nans;
  }

  cout << ans[7] << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}