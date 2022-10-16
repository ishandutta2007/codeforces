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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  int ans = 0;
  while (a.back()) {
    bool change = false;
    int diff = 1;
    int last = a[0];
    change |= a[0] > 0;
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
      if (diff == k) {
        a[i] -= last;
        change |= last != 0;
      } else {
        diff += a[i] != last;
        last = a[i];
        change |= a[i] != 0;
        a[i] = 0;
      }
    }
    if (!change) {
      cout << -1 << '\n';
      return;
    }
    ++ans;
  }
  cout << ans << '\n';
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