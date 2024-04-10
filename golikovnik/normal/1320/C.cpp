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

  int n, m, p;
  cin >> n >> m >> p;
  vector<pair<int, int>> weapon(n), armor(m);
  int min_a = INT_MAX, min_b = INT_MAX;
  for (auto&[x, y] : weapon) cin >> x >> y, set_min(min_a, y);
  for (auto&[x, y] : armor) cin >> x >> y, set_min(min_b, y);
  vector<tuple<int, int, int>> monsters(p);
  for (auto&[x, y, z] : monsters) cin >> x >> y >> z;

  auto fix = [&](auto& vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end(), [](auto& x, auto& y) {
      return x.first == y.first;
    }), vec.end());
  };
  fix(weapon);
  fix(armor);
  n = (int) weapon.size();
  m = (int) armor.size();
  for (int i = n - 2; i >= 0; --i) set_min(weapon[i].second, weapon[i + 1]
  .second);
  for (int i = m - 2; i >= 0; --i) set_min(armor[i].second, armor[i + 1]
  .second);

  int const N = (int) 1e6 + 20;
  i64 const INF = (i64) 1e16;

  vector<i64> armor_cost(N);
  int nxt_i = 0;
  for (int i = 0; i < N; ++i) {
    if (nxt_i != m && armor[nxt_i].first == i) {
      ++nxt_i;
    }
    if (nxt_i == m) {
      armor_cost[i] = INF;
    } else {
      armor_cost[i] = armor[nxt_i].second;
    }
  }
  struct node {
    i64 get;
    i64 add;
  };
  vector<node> tree(4 * N);
  auto apply = [&](int v, i64 delta) {
    tree[v].get += delta;
    tree[v].add += delta;
  };
  auto push = [&](int v) {
    apply(2 * v, tree[v].add);
    apply(2 * v + 1, tree[v].add);
    tree[v].add = 0;
  };
  auto join = [&](node const& x, node const& y) {
    return node{max(x.get, y.get), 0};
  };
  auto pull = [&](int v) {
    tree[v] = join(tree[2 * v], tree[2 * v + 1]);
  };
  function<void(int, int, int)> build = [&](int v, int l, int r) {
    if (l + 1 == r) {
      tree[v] = {-armor_cost[l], 0};
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid, r);
    pull(v);
  };
  build(1, 0, N);
  function<void(int, int, int, int, int, i64)> add =
          [&](int v, int l, int r, int ql, int qr, i64 delta) {
    if (l >= qr || ql >= r) return;
    if (ql <= l && r <= qr) {
      apply(v, delta);
      return;
    }
    int mid = (l + r) / 2;
    push(v);
    add(2 * v, l, mid, ql, qr, delta);
    add(2 * v + 1, mid, r, ql, qr, delta);
    pull(v);
  };
  sort(monsters.begin(), monsters.end());
  int ptr = 0;
  i64 ans = -min_a - min_b;
  for (auto& [x, y, z] : monsters) {
    while (ptr < n && weapon[ptr].first <= x) {
      ++ptr;
    }
    if (ptr == n) break;
    add(1, 0, N, y, N, z);
    push(1);
    set_max(ans, tree[1].get - weapon[ptr].second);
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}