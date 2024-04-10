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
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (auto& x : p) cin >> x, --x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[p[i]] = i;
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[(a[i] - i + n) % n]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] * 3 >= n) {
      auto na = a;
      if (i > 0) {
        rotate(na.begin(), na.end() - i, na.end());
      }
      int cyc = 0;
      vector<bool> used(n);
      for (int j = 0; j < n; ++j) {
        if (used[j]) continue;
        cyc++;
        while (!used[j]) {
          used[j] = true;
          j = na[j];
        }
      }
      if (n - cyc <= m) {
        ans.push_back(i);
      }
    }
  }
  cout << ans.size() << ' ';
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
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