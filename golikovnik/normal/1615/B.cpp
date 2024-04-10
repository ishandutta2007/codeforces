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

int const N = 2e5 + 30;
int const BIT = 20;

int pref[BIT][N + 1];

void solveTest() {
  int l, r;
  cin >> l >> r;
  int ans = INT_MAX;
  for (int b = 0; b < BIT; ++b) {
    int cnt = pref[b][r + 1] - pref[b][l];
    if (cnt > 0) {
      smin(ans, r - l + 1 - cnt);
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

  for (int b = 0; b < BIT; ++b) {
    for (int i = 0; i < N; ++i) {
      pref[b][i + 1] = pref[b][i] + (i >> b & 1);
    }    
  }

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}