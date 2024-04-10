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

void solveTest() {
  int n, k; cin >> n >> k;
  vector<int> cnt(26);
  for (int i = 0; i < n; ++i) {
    char ch; cin >> ch; ++cnt[ch - 'a'];
  }

  int pairs = 0;
  for (int x : cnt) pairs += x / 2;
  int ans = pairs / k * 2;
  pairs = 0;
  int odds = 0;
  for (int x : cnt) {
    if (x % 2 == 1) {
      odds++;
      pairs += x / 2;
    } else {
      pairs += x / 2;
    }
  }
  while (pairs > 0 && odds < k) {
    pairs -= 1;
    odds += 2;
  }
  cout << max(ans, pairs / k * 2 + 1) << '\n';
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
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}