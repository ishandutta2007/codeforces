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

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
  }
  sort(a.begin(), a.end());
  i64 ans = 0;

  multiset<int, greater<>> have;
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && a[j].first == a[i].first) {
      have.insert(a[j].second);
      sum += a[j++].second;
    }
    auto take = (j == n ? (int) have.size() : a[j].first - a[i].first);
    sum -= *have.begin();
    have.erase(have.begin());
    --take;
    set_min(take, (int) have.size());
    for (int it = 0; it < take; ++it) {
      ans += 1ll * (it + 1) * *have.begin();
      sum -= *have.begin();
      have.erase(have.begin());
    }
    if (j != n) {
      ans += sum * (a[j].first - a[i].first);
    }
    i = j - 1;
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}