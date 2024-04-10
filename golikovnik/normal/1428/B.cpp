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
  string s;
  cin >> s;
  bool h1 = count(s.begin(), s.end(), '>') > 0;
  bool h2 = count(s.begin(), s.end(), '<') > 0;
  if (!h1 || !h2) {
    cout << n << '\n';
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto c1 = s[(i - 1 + n) % n];
    auto c2 = s[i];
    if (c1 == '-' || c2 == '-') {
      ans++;
    }
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