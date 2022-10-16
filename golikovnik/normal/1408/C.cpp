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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  auto b = a;
  reverse(b.begin(), b.end());
  for (auto& x : b) x = l - x;
  double left = 0;
  double right = 1e10;
  auto calc = [&](auto& arr, double need) {
    double pos = 0;
    int speed = 1;
    for (int i = 0; i < n; ++i) {
      double dist = arr[i] - pos;
      double need_time = dist / speed;
      if (need < need_time) {
        return pos + need * speed;
      }
      need -= need_time;
      pos = arr[i];
      speed++;
    }
    return pos + need * speed;
  };
  for (int it = 0; it < 500; ++it) {
    auto middle = (left + right) / 2;
    auto p1 = calc(a, middle);
    auto p2 = calc(b, middle);
    p2 = l - p2;
    if (p1 < p2) {
      left = middle;
    } else {
      right = middle;
    }
  }
  cout << setprecision(20) << (left + right) / 2 << '\n';
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