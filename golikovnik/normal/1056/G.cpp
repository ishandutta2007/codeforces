//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

  int n, m;
  cin >> n >> m;

  auto go = [&](int s, i64 t) -> int {
    if (s < m) {
      return (s + t) % n;
    }
    return ((s - t) % n + n) % n;
  };

  int s;
  i64 t;
  cin >> s >> t;
  --s;

  vector<i64> last(n, -1);
  while (t) {
    if (last[s] >= 0) {
      auto len = last[s] - t;
      assert(len > 0);
      t %= len;
    }
    if (!t) break;
    last[s] = t;
    for (int it = 0; it < n && t > 0; ++it) {
      s = go(s, t--);
    }
  }

  cout << s + 1 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}