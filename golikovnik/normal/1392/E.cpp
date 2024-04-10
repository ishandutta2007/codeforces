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
//  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);

  int n;
  cin >> n;
  i64 const ONE = 1;
  vector<vector<i64>> a(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      auto d = i + j;
      auto pos = i - max(0, d - n + 1);
      if (d % 2 ^ pos % 2) {
        a[i][j] = (ONE << (d - 1));
      }
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  int d = 2 * n - 1;
  int q;
  cin >> q;
  auto right = [&](int x, int y) {
    if (y + 1 == n) return false;
    return bool(a[x][y + 1]);
  };
  while (q--) {
    i64 k;
    cin >> k;
    int x = 0;
    int y = 0;
    cout << x + 1 << ' ' << y + 1 << endl;
    for (int i = 0; i < d - 1; ++i) {
      auto bit = k >> i & 1;
      auto R = (y + 1 != n) && ((bit && right(x, y)) || (!bit && !right(x, y)));
      if (R) {
        y++;
      } else {
        x++;
      }
      cout << x + 1 << ' ' << y + 1 << endl;
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}