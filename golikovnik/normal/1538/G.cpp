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
  i64 n, m, a, b;
  cin >> n >> m >> a >> b;

  if (a == b) {
    cout << min(n / a, m / a) << '\n';
    return;
  }
  if (a > b) swap(a, b);
  i64 left = 0;
  i64 right = i64(1.1e9);
  while (left + 1 < right) {
    i64 z = (left + right) / 2;
    bool can = false;
    if (m - a * z >= 0) {
      i64 R = (m - a * z) / (b - a);
      smin(R, z);
      if (b * z - n <= (b - a) * R) {
        can = true;
      }
    }
    if (can) {
      left = z;
    } else {
      right = z;
    }
  }
  cout << left << '\n';
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