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

  string s;
  cin >> s;
  vector<i64> cnt(26);
  i64 ans = 0;
  map<pair<int, int>, i64> cnt_pair;
  for (char ch : s) {
    for (char pr = 'a'; pr <= 'z'; ++pr) {
      cnt_pair[{pr, ch}] += cnt[pr - 'a'];
    }
    ++cnt[ch - 'a'];
  }
  for (auto x : cnt) {
    set_max(ans, x);
  }
  for (auto[x, y] : cnt_pair) {
    set_max(ans, y);
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}