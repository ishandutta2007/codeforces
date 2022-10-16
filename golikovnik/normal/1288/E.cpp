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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> mn(n);
  iota(mn.begin(), mn.end(), 0);
  auto mx = mn;
  vector<int> pos(n, -1);
  vector<int> fenw(m);
  auto add = [&](int at, int d) {
    for (; at < m; at |= at + 1) {
      fenw[at] += d;
    }
  };
  auto pref = [&](int r) {
    int ans = 0;
    for (; --r >= 0; r &= (r + 1)) {
      ans += fenw[r];
    }
    return ans;
  };
  auto get = [&](int from, int to) {
    return pref(to) - pref(from);
  };
  ordered_set<int> st;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    mn[x] = 0;
    auto j = pos[x];
    if (~j) {
      set_max(mx[x], get(j + 1, i));
      add(j, -1);
      add(i, 1);
    } else {
      set_max(mx[x], x + (int) st.size() - st.order_of_key(x));
      add(i, 1);
      st.insert(x);
    }
    pos[x] = i;
  }
  for (int i = 0; i < n; ++i) {
    auto j = pos[i];
    if (~j) {
      set_max(mx[i], get(j + 1, m));
    } else {
      set_max(mx[i], i + (int) st.size() - st.order_of_key(i));
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << mn[i] + 1 << ' ' << mx[i] + 1 << '\n';
  }
#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
            chrono::high_resolution_clock::now() - _clock_start
          ).count() << "ms.\n";
#endif
  return 0;
}