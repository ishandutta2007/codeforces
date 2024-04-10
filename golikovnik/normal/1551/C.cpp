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

void solve(int) {
  int n; cin >> n;
  vector<array<int, 5>> a(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (char ch : s) ++a[i][ch - 'a'];
  }
  int ans = 0; 
  for (int ch = 0; ch < 5; ++ch) {
    vector<int> vals;
    for (int i = 0; i < n; ++i) {
      int b = 0;
      for (int j = 0; j < 5; ++j) {
        if (j == ch) b += a[i][j]; else b -= a[i][j];
      }
      vals.push_back(b);
    }
    sort(vals.rbegin(), vals.rend());
    int c = 0;
    int tot = 0;
    for (auto x : vals) {
      tot += x;
      if (tot <= 0) break;
      c++;
    }
    smax(ans, c);
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