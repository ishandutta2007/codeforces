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
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector corners{pair{1, 1}, pair{1, m}, pair{n, 1}, pair{n, m}};
  i64 ans = -1;
  int optI = -1;
  int optJ = -1;

  auto dist = [](i64 x, i64 y, i64 z, i64 w) {
    return i64(llabs(x - z) + llabs(y - w));
  };

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < i; ++j) {
      i64 d = LLONG_MAX;
      int i0 = i;
      int j0 = j;
      for (int rot = 0; rot < 2; ++rot, swap(i0, j0)) {
        auto[x0, y0] = corners[i0];
        auto[x1, y1] = corners[j0];
        smin(d, dist(r, c, x0, y0) + dist(x0, y0, x1, y1) + dist(x1, y1, r, c));
      }
      if (smax(ans, d)) {
        optI = i;
        optJ = j;
      }
    }
  }
  cout << corners[optI].first << ' ' << corners[optI].second << ' ' << corners[optJ].first << ' ' << corners[optJ].second << '\n';
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