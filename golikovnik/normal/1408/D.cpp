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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(m);
  for (auto& [x, y] : a) cin >> x >> y;
  for (auto& [x, y] : b) cin >> x >> y;
  vector<pair<int, int>> constraints;
  constraints.reserve(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      constraints.emplace_back(max(0, b[j].first - a[i].first + 1), max(0, b[j]
      .second -
      a[i]
      .second + 1));
    }
  }
  sort(constraints.rbegin(), constraints.rend());
  int ans = INT_MAX;
  int y_max = 0;
  for (auto[x, y] : constraints) {
    smin(ans, x + y_max);
    smax(y_max, y);
  }
  cout << min(ans, y_max) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}