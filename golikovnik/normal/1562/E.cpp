//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

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
  int n; string s; cin >> n >> s;

  vector lcp(n + 1, vector<int>(n + 1));
  for (int j = n - 1; j >= 0; --j) {
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == s[j]) {
        lcp[i][j] = 1 + lcp[i + 1][j + 1];
      }
    }
  }

  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = n - i;
    for (int j = 0; j < i; ++j) {
      int l = lcp[i][j];
      if (s[j + l] < s[i + l]) {
        smax(dp[i], dp[j] + (n - i - l));
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}