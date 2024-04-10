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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<i64> cubes;
  for (int i = 1; i64(i) * i * i <= i64(1.1e12); ++i) {
    cubes.insert(i64(i) * i * i);
  }
  int t;
  cin >> t;
  while (t--) {
    i64 x;
    cin >> x;
    bool ok = false;
    for (auto c : cubes) {
      if (c > x) break;
      if (cubes.count(x - c)) ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}