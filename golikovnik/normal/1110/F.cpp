//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <typename A, typename B, typename Cmp>
bool set_min(A& x, B const& y, Cmp&& cmp) {
  if (cmp(y, x)) {
    x = y;
    return true;
  }
  return false;
}

template <typename A, typename B>
bool set_min(A& x, B const& y) {
  return set_min(x, y, less<>{});
}

template <typename A, typename B>
bool set_max(A& x, B const& y) {
  return set_min(x, y, greater<>{});
}

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 1; i < n; ++i) {
    int p, w;
    cin >> p >> w;
    graph[p - 1].emplace_back(i, w);
  }
  vector<int> tin(n), tout(n);
  int timer = 0;
  vector<i64> d(n);
  function<void(int)> dfs = [&](int v) {
    tin[v] = timer++;
    for (auto[u, w] : graph[v]) {
      d[u] = d[v] + w;
      dfs(u);
    }
    tout[v] = timer;
  };
  dfs(0);
  int pw = 1;
  while (pw < n) pw <<= 1;
  i64 const INF = (i64) 1e17;
  vector<i64> rmq(2 * pw, INF), add(2 * pw);
  for (int i = 0; i < n; ++i) {
    if (graph[i].empty()) {
      rmq[pw + tin[i]] = d[i];
    }
  }
  for (int i = pw - 1; i; --i) {
    rmq[i] = min(rmq[2 * i], rmq[2 * i + 1]);
  }
  auto apply = [&](int v, i64 delta) {
    rmq[v] += delta;
    add[v] += delta;
  };
  auto push = [&](int v) {
    apply(2 * v, add[v]);
    apply(2 * v + 1, add[v]);
    add[v] = 0;
  };
  auto pull = [&](int v) {
    rmq[v] = min(rmq[2 * v], rmq[2 * v + 1]);
  };
  function<i64(int, int, int, int, int)> query =
          [&](int v, int l, int r, int ql, int qr) {
    if (l >= qr || ql >= r) return INF;
    if (ql <= l && r <= qr) return rmq[v];
    push(v);
    int m = (l + r) / 2;
    return min(query(2 * v, l, m, ql, qr),
            query(2 * v + 1, m, r, ql, qr));
  };
  function<void(int, int, int, int, int, i64)> add_seg =
          [&](int v, int l, int r, int ql, int qr, i64 delta) {
    if (l >= qr || ql >= r) return;
    if (ql <= l && r <= qr) {
      apply(v, delta);
      return;
    }
    push(v);
    int m = (l + r) / 2;
    add_seg(2 * v, l, m, ql, qr, delta);
    add_seg(2 * v + 1, m, r, ql, qr, delta);
    pull(v);
  };
  struct qr {
    int l, r, i;
  };
  vector<vector<qr>> qs(n);
  for (int i = 0; i < q; ++i) {
    int v, l, r;
    cin >> v >> l >> r;
    --v, --l;
    qs[v].push_back({l, r, i});
  }
  vector<i64> ans(q);
  function<void(int)> dfs2 = [&](int v) {
    for (auto[l, r, i] : qs[v]) {
      ans[i] = query(1, 0, pw, l, r);
    }
    for (auto[u, w] : graph[v]) {
      add_seg(1, 0, pw, tin[u], tout[u], -w);
      add_seg(1, 0, pw, 0, tin[u], w);
      add_seg(1, 0, pw, tout[u], n, w);
      dfs2(u);
      add_seg(1, 0, pw, tin[u], tout[u], w);
      add_seg(1, 0, pw, 0, tin[u], -w);
      add_seg(1, 0, pw, tout[u], n, -w);
    }
  };
  dfs2(0);
  for (auto x : ans) cout << x << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}