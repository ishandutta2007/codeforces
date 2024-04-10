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
  int n, m, k;
  cin >> n >> m >> k;
  bool tr = false;
  if (n % 2 == 1) {
    swap(n, m);
    k = n * m / 2 - k;
    tr = true;
  }
  int can = n * (m / 2);
  if (k > can || k % 2 == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector ans(n, string(m, '?'));
  for (int r = 0; r < n; r += 2) {
    for (int i = 0; i + 1 < m; i += 2) {
      if (k > 0) {
        auto x = 'e' + 2 * (r / 2 % 2) + 4 * (i / 2 % 2);
        ans[r][i] = x; ans[r][i + 1] = x;
        ans[r + 1][i] = x + 1; ans[r + 1][i + 1] = x + 1;
        k -= 2;
      } else {
        auto x = 'a' + 2 * (r / 2 % 2);
        ans[r][i] = x; ans[r + 1][i] = x;
        ans[r][i + 1] = x + 1; ans[r + 1][i + 1] = x + 1;
      }
    }
    if (m % 2 == 1) {
      ans[r].back() = 'y' + (r / 2 % 2);
      ans[r + 1].back() = 'y' + (r / 2 % 2);
    }
  }
  if (tr) {
    vector nans(m, string(n, '?'));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        nans[i][j] = ans[j][i];
      }
    }
    ans = nans;
  }
  for (auto x : ans) cout << x << '\n';
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