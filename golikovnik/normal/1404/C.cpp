//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    r = n - r - 1;
    qs[r].emplace_back(l, i);
  }
  ordered_set<pair<int, int>> st;
  int t = 0;
  vector<pair<int, int>> segs;
  vector<int> fenw(n);
  vector<int> ans(q);
  auto add = [&](int at) {
    while (at < n) {
      ++fenw[at];
      at |= at + 1;
    }
  };
  auto pref = [&](int upto) {
    int r = 0;
    while (upto >= 0) {
      r += fenw[upto];
      upto = (upto & (upto + 1)) - 1;
    }
    return r;
  };
  for (int i = 0; i < n; ++i) {
    int x = i + 1 - a[i];
    if (x >= 0) {
      if (x == 0) {
        st.insert({i, t++});
        segs.emplace_back(i, i);
        add(i);
      } else {
        if ((int) st.size() >= x) {
          auto j = st.find_by_order((int) st.size() - x)->first;
          segs.emplace_back(j, i);
          add(j);
          st.insert({j, t++});
        }
      }
    }
    for (auto[l, id] : qs[i]) {
      ans[id] = pref(n - 1) - pref(l - 1);
    }
  }
  for (int x : ans) cout << x << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}