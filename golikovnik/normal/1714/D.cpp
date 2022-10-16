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
  string s; cin >> s;
  int n = int(s.size());
  int k; cin >> k;
  vector<tuple<int, int, int>> maxRight(n, make_tuple(-1, -1, -1));
  for (int i = 0; i < k; ++i) {
    string t; cin >> t;
    int m = int(t.size());
    for (int j = 0; j + m <= n; ++j) {
      if (s.substr(j, m) == t) {
        smax(maxRight[j], make_tuple(j + m, j, i));
      }
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    smax(maxRight[i + 1], maxRight[i]);
  }
  vector<pair<int, int>> ans;
  int st = 0;
  while (st < n) {
    auto[r, fr, i] = maxRight[st];
    if (r <= st) {
      cout << -1 << '\n';
      return;
    }
    ans.emplace_back(make_pair(i, fr));
    st = r;
  }
  cout << ans.size() << '\n';
  for (auto[i, p] : ans) {
    cout << i + 1 << ' ' << p + 1 << '\n';
  }
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