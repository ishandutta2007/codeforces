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
  int n, m;
  cin >> n >> m;
  if (m < n) {
    cout << "No\n";
    return;
  }
  if (n % 2 == 1) {
    cout << "Yes\n";
    for (int i = 0; i < n - 1; ++i) {
      cout << 1 << ' ';
    }
    cout << m - (n - 1) << '\n';
    return;
  }
  if (m % 2 == 0) {
    cout << "Yes\n";
    for (int i = 0; i < n - 2; ++i) {
      cout << 1 << ' ';
    }
    cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
    return;
  }
  cout << "No\n";
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
  for (int tt_ = 1; tt_ <= _tests; ++tt_) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}