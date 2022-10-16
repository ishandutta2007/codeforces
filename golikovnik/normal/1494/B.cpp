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
  int n, u, r, d, l;
  cin >> n >> u >> r >> d >> l;
  for (int mask = 0; mask < (1 << 4); ++mask) {
    int haveU = 0;
    int haveR = 0;
    int haveD = 0;
    int haveL = 0;
    if (mask & 1) haveU++, haveL++;
    if (mask >> 1 & 1) haveU++, haveR++;
    if (mask >> 2 & 1) haveR++, haveD++;
    if (mask >> 3 & 1) haveD++, haveL++;
    vector deltas{r - haveR, l - haveL, u - haveU, d - haveD};
    bool ok = true;
    for (int x : deltas) ok &= x >= 0 && x <= n - 2;
    if (ok) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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