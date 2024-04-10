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

  int n;
  cin >> n;
  i64 ans = 0;

  map<int, int> have;
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      ans += have[x];
      have[x]++;
    } else {
      ans += have[x];
      ans += have[y];
      ans -= cnt[minmax(x, y)];
      have[x]++;
      have[y]++;
    }
    cnt[minmax(x, y)]++;
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}