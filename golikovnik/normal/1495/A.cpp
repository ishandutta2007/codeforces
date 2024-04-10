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
  int n;
  cin >> n;
  vector<int> xs, ys;
  for (int i = 0; i < 2 * n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x) {
      xs.push_back(abs(x));
    } else {
      ys.push_back(abs(y));
    }
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += sqrt(i64(xs[i]) * xs[i] + i64(ys[i]) * ys[i]);
  }
  cout << setprecision(20) << fixed << ans << '\n';
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