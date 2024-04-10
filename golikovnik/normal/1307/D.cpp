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

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename K, typename V> using hash_map = gp_hash_table<K, V>;

template <typename T> using hash_set = gp_hash_table<T, null_type>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (auto& x : a) {
    cin >> x;
    --x;
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  auto bfs = [&](int s) {
    vector<int> d(n, -1);
    d[s] = 0;
    vector<int> q(n);
    q[0] = s;
    int qt = 1;
    for (int qh = 0; qh < qt; ++qh) {
      auto v = q[qh];
      for (auto u : graph[v]) {
        if (d[u] < 0) {
          d[u] = d[v] + 1;
          q[qt++] = u;
        }
      }
    }
    return d;
  };
  auto d = bfs(0);
  auto dr = bfs(n - 1);
  vector<int> A, B;
  for (int v : a) {
    A.push_back(d[v]);
    B.push_back(dr[v]);
  }
  vector<int> order(k);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return A[i] < A[j];
  });
  vector<int> as(k), bs(k);
  for (int i = 0; i < k; ++i) {
    as[i] = A[order[i]];
    bs[i] = B[order[i]];
  }

  int pw = 1;
  while (pw < k) {
    pw *= 2;
  }
  vector<int> rmq(2 * pw, (int) -1e8);
  for (int i = 0; i < k; ++i) {
    rmq[pw + i] = bs[i];
  }
  for (int i = pw - 1; i > 0; --i) {
    rmq[i] = max(rmq[2 * i], rmq[2 * i + 1]);
  }

  auto query = [&](int l, int r) {
    int ans = (int) -1e8;
    for (l += pw, r += pw; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        set_max(ans, rmq[l++]);
      }
      if (r & 1) {
        set_max(ans, rmq[--r]);
      }
    }
    return ans;
  };

  auto get = [&](int from, int ban) {
    if (ban < from) {
      return query(from, pw);
    }
    return max(query(from, ban), query(ban + 1, pw));
  };

  int left = -1;
  int right = n + 2;
  while (left + 1 < right) {
    int middle = (left + right) / 2;
    bool ok = false;
    for (int i = 0; i < k; ++i) {
      auto need_a = middle - bs[i];
      auto j = lower_bound(as.begin(), as.end(), need_a) - as.begin();
      if (j == k) {
        continue;
      }
      if (get(j, i) >= middle - as[i]) {
        ok = true;
        break;
      }
    }
    (ok ? left : right) = middle;
  }
  int ans = 1 + left;
  cout << min(ans, d[n - 1]) << '\n';
#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}