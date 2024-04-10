//  Copyright 2022 Nikita Golikov

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
  int n; cin >> n;
  vector<int> a(n);
  bool have = false;
  for (int& x : a) {
    cin >> x;
    if (x % 10 == 0 || x % 10 == 5) {
      have = true;
    }
  }
  if (have) {
    int w = -1;
    for (int x : a) {
      x += x % 10;
      if (w < 0) {
        w = x;
      } else if (x != w) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
  vector<int> cnt(20);
  for (int x : a) {
    x += x % 10;
    for (int it = 0; it < 4; ++it) {
      ++cnt[x % 20];
      x += x % 10;
    }
  }
  cout << (*max_element(cnt.begin(), cnt.end()) == n ? "YES" : "NO") << '\n';
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