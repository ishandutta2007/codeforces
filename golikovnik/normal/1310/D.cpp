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

  int n, k;
  cin >> n >> k;
  vector<vector<int>> w(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
    }
  }

  int ans = INT_MAX;

  int const need = k / 2;
  vector<int> vs(need);

  int const need_guys = min(n, need + 1);

  vector<vector<vector<pair<int, int>>>> best(n,
                                              vector<vector<pair<int, int>>>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vector<pair<int, int>> cur(n);
      for (int v = 0; v < n; ++v) {
        cur[v] = {w[i][v] + w[v][j], v};
      }
      nth_element(cur.begin(), cur.begin() + need_guys - 1, cur.end());
      cur.resize(need_guys);
      sort(cur.begin(), cur.end());
      best[i][j] = cur;
    }
  }

  vector<int> used(n);
  used[0] = true;

  function<void(int)> rec = [&](int ptr) {
    if (ptr == need) {
      int cur = 0;
      for (int i = 0; i < need; ++i) {
        auto x = vs[i];
        auto y = vs[(i + 1) % need];
        int r = -1;
        for (auto[x, mid] : best[x][y]) {
          if (!used[mid]) {
            r = x;
            break;
          }
        }
        if (r < 0) {
          cur = INT_MAX;
          break;
        }
        cur += r;
      }
      set_min(ans, cur);
      return;
    }
    for (int v = 0; v < n; ++v) {
      auto was = used[v];
      vs[ptr] = v;
      used[v] = true;
      rec(ptr + 1);
      used[v] = was;
    }
  };
  rec(1);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}