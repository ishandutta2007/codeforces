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

void solve(int) {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  for (auto& x : c) cin >> x;
  cout << a[0] << ' ';
  int last = a[0];
  for (int i = 1; i < n; ++i) {
    int b1 = last;
    int b2 = -1;
    if (i == n - 1) {
      b2 = a[0];
    }
    if (a[i] != b1 && a[i] != b2) {
      cout << a[i] << ' ';
      last = a[i];
    } else if (b[i] != b1 && b[i] != b2) {
      cout << b[i] << ' ';
      last = b[i];
    } else {
      assert(c[i] != b1 && c[i] != b2);
      cout << c[i] << ' ';
      last = c[i];
    }
  }
  cout << '\n';
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