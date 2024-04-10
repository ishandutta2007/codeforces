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
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch; cin >> ch;
      if (ch == 'B') {
        a.emplace_back(i, j);
      }
    }
  }

  int ansr = -1, ansc = -1;
  auto check = [&](int dist) {
    int maxsum = n + m + 10;
    int minsum = -n - m - 10;
    int maxdiff = n + m + 10;
    int mindiff = -n - m - 10;
    for (auto[r, c] : a) {
      smin(maxsum, r + c + dist);
      smax(minsum, r + c - dist);
      smin(maxdiff, r - c + dist);
      smax(mindiff, r - c - dist);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i + j >= minsum && i + j <= maxsum && i - j >= mindiff && i - j <= maxdiff) {
          ansr = i;
          ansc = j;
          return true;
        }
      }
    }
    return false;
  };

  int left = -1;
  int right = n + m + 5;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    (check(mid) ? right : left) = mid;
  }
  debug(right);
  assert(check(right));
  cout << ansr + 1 << ' ' << ansc + 1  << '\n';
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