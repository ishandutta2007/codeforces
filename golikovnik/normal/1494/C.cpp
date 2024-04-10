//  Copyright 2021 Nikita Golikov

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

int solve(vector<int> a, vector<int> b) {
  int n = int(a.size());
  int m = int(b.size());
  int total = 0;
  for (int pos : b) {
    total += binary_search(a.begin(), a.end(), pos);
  }

  auto countP = [&](int r) {
    return int(upper_bound(b.begin(), b.end(), r) - b.begin());
  };
  auto countB = [&](int l, int r) {
    return countP(r) - countP(l - 1);
  };

  int ans = total;
  for (int i = 0; i < m; ++i) {
    total -= binary_search(a.begin(), a.end(), b[i]);
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    int len = int(it - a.begin());
    smax(ans, total + countB(b[i] - len + 1, b[i]));
  }
  return ans;
}

void solve(int) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(2), b(2);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x < 0].push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    b[x < 0].push_back(x);
  }
  int ans = solve(a[0], b[0]);
  reverse(a[1].begin(), a[1].end());
  reverse(b[1].begin(), b[1].end());
  for (auto& x : a[1]) x = -x;
  for (auto& x : b[1]) x = -x;
  cout << ans + solve(a[1], b[1]) << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}