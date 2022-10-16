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
  set<int> alive;
  for (int i = 0; i < n; ++i) alive.insert(i);
  map<int, int> segments;
  ordered_set<int> lefts, rights;

  auto insertSegment = [&](int l, int r) {
    auto it = segments.lower_bound(l);
    if (it != segments.end() && it->second <= r) {
      return;
    }
    it = segments.upper_bound(l);
    while (it != segments.begin()) {
      --it;
      if (it->second < r) {
        break;
      }
      lefts.erase(it->first);
      rights.erase(it->second);
      it = segments.erase(it);
    }
    lefts.insert(l);
    rights.insert(r);
    segments[l] = r;
  };

  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, x; cin >> l >> r >> x; --l;
      if (x == 0) {
        auto it = alive.lower_bound(l);
        while (it != alive.end() && *it < r) {
          it = alive.erase(it);
        }
      } else {
        insertSegment(l, r);
      }
    } else {
      int i; cin >> i; --i;
      auto it = alive.find(i);
      if (it == alive.end()) {
        cout << "NO\n";
      } else {
        int pv = it == alive.begin() ? -1 : *prev(it);
        int nx = it == prev(alive.end()) ? n : *next(it);
        int x = lefts.order_of_key(pv+1);
        int y = rights.order_of_key(i+1);
        int from = max(x, y);
        if (from < int(lefts.size()) && *lefts.find_by_order(from) <= i && *rights.find_by_order(from) <= nx) {
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
      }
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}