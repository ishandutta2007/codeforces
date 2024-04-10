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
  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  int ps = 0;
  int pt = 0;
  int last = -1;
  int lastops = 0;
  string ans;

  auto takes = [&] {
    if (last != 0) {
      last = 0;
      lastops = 0;
    }
    ++lastops;
    ans.push_back(s[ps++]);
  };
  auto taket = [&] {
    if (last != 1) {
      last = 1;
      lastops = 0;
    }
    ++lastops;
    ans.push_back(t[pt++]);
  };

  while (ps < n && pt < m) {
    bool cans = ps < n && (last != 0 || lastops != k);
    bool cant = pt < m && (last != 1 || lastops != k);
    if (cans && !cant) {
      takes();
    } else if (cant && !cans) {
      taket();
    } else {
      if (s[ps] < t[pt]) {
        takes();
      } else {
        taket();
      }
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