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

  int n;
  ll g, r;
  cin >> n >> g >> r;

  auto mod = [g, r](ll x) {
    x %= g + r;
    if (x < 0) {
      x += g + r;
    }
    return x;
  };

  vector<ll> a(n + 1);
  for (auto& x : a) cin >> x;
  vector<ll> pref(n + 2);
  for (int i = 0; i <= n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }

  static int const INF = int(1e6);

  struct node {
    int val = INF;
    int left = -1;
    int right = -1;
 };

  vector<ll> dp(n + 2);
  dp[n] = a[n];

  vector<node> tree;
  tree.push_back({n});
  auto createNode = [&] {
    tree.push_back({});
    return int(tree.size()) - 1;
  };

  auto setRange = [&](int ql, int qr, int val) {
    auto rec = [&](auto&& self, int v, int L, int R) -> void {
      if (ql >= R || L >= qr) {
        return;
      }
      if (ql <= L && R <= qr) {
        tree[v].val = val;
        return;
      }
      auto mid = L + (R - L) / 2;
      if (tree[v].left < 0) {
        tree[v].left = createNode();        
      }
      self(self, tree[v].left, L, mid);
      if (tree[v].right < 0) {
        tree[v].right = createNode();
      }
      self(self, tree[v].right, mid, R);
    };
    rec(rec, 0, 0, r + g);
  };
  auto query = [&](int at) {
    int v = 0;
    int ans = INT_MAX;
    int L = 0;
    int R = r + g;
    while (true) {
      auto nd = tree[v];
      smin(ans, nd.val);
      auto mid = L + (R - L) / 2;
      if (tree[v].left >= 0 && at < mid) {
        v = tree[v].left;
        R = mid;
        continue;
      }
      if (tree[v].right >= 0 && at >= mid) {
        v = tree[v].right;
        L = mid;
        continue;
      }
      break;
    }
    return ans;
  };

  for (int i = n - 1; i >= 0; --i) {
    int mn = mod(g - pref[i + 1]);
    int mx = mod(r + g - pref[i + 1]);
    if (mn < mx) {
      setRange(mn, mx, i);
    } else {
      setRange(mn, r + g, i);
      setRange(0, mx, i);
    }

    int point = mod(-pref[i]);
    int id = query(point);
    if (id == n) {
      dp[i] = pref[n + 1] - pref[i];
    } else {
      ll val = pref[id + 1] - pref[i];
      assert(mod(val) >= g);
      val += r + g - mod(val);
      dp[i] = val + dp[id + 1];
    }
  }

  int q; cin >> q;
  while (q--) {
    ll t; cin >> t;
    int id = query(mod(t));
    if (id == n) {
      cout << t + pref[n + 1] << '\n';
    } else {
      ll val = t + pref[id + 1];
      assert(mod(val) >= g);
      val += r + g - mod(val);
      cout << val + dp[id + 1] << '\n';
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}