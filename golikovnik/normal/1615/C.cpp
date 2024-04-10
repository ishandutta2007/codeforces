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
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
    b[i] = t[i] - '0';
  }
  int ans = INT_MAX;
  for (int pall : {0, 1}) {
    vector<int> me(n);
    int xme = 0;
    for (int i = 0; i < n; ++i) {
      me[i] = a[i] ^ b[i] ^ pall;
      xme ^= me[i];
    }
    if (xme != pall) {
      continue;
    }
    int cnt[2]{};
    int all = 0;
    for (int i = 0; i < n; ++i) {
      if (me[i] == 1) {
        cnt[a[i]]++;
        all++;
      }
    }
    if (cnt[0] == cnt[1] || cnt[0] == cnt[1] - 1) {
      smin(ans, all);
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
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