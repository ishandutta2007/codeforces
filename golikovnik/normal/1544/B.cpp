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

void solve(int) {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<string> result;
  vector<pair<int, int>> points{{0, 1}, {1, 0}, {n - 2, 0}, {n - 1, 1},
                                {0, m - 2}, {1, m - 1}, {n - 1, m - 2}, {n - 2, m - 1}};
  for (int msk = 0; msk < (1 << 8); ++msk) {
    vector<string> cur(n, string(m, '0'));
    int res = 0;
    auto tryPut = [&](int i, int j, bool check = true) {
      if (check && find(points.begin(), points.end(), pair{i, j}) != points.end()) return;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int ii = i + dx;
          int jj = j + dy;
          if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
          if (cur[ii][jj] == '1') return;
        }
      }
      assert(cur[i][j] == '0');
      cur[i][j] = '1';
      ++res;
    };
    for (int i = 0; i < 8; ++i) {
      if (msk >> i & 1) {
        tryPut(points[i].first, points[i].second, false);
      }
    }
    for (int j = 0; j < m; ++j) tryPut(0, j);
    for (int i = 0; i < n; ++i) tryPut(i, m - 1);
    for (int j = m - 1; j >= 0; --j) tryPut(n - 1, j);
    for (int i = n - 1; i >= 0; --i) tryPut(i, 0);
    if (smax(ans, res)) result = cur;
  }
  for (auto const& s : result) cout << s << '\n';
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