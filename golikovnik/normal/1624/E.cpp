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
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (auto& s : a) cin >> s;

  map<string, pair<int, int>> mp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int len : {2, 3}) {
        if (j + len <= m) {
          mp[a[i].substr(j, len)] = make_pair(i, j);
        }
      }
    }
  }

  vector<pair<int, pair<int, int>>> dp(m + 1, pair{-1, pair{-1, -1}});
  dp[0] = make_pair(0, pair{-1, -1});
  for (int i = 0; i < m; ++i) {
    if (get<0>(dp[i]) < 0) {
      continue;
    }

    for (int len : {2, 3}) {
      if (i + len <= m) {
        auto need = a[n].substr(i, len);
        if (mp.count(need)) {
          dp[i + len] = make_pair(i, mp[need]);
        }
      }
    }
  }

  if (dp[m].first < 0) {
    cout << -1 << '\n';
    return;
  }
  vector<tuple<int, int, int>> segments;
  int cur = m;
  while (cur > 0) {
    auto[from, pp] = dp[cur];
    auto[who, where] = pp;
    assert(who >= 0);
    segments.emplace_back(where + 1, where + (cur - from), who + 1);
    cur = from;
  }
  reverse(segments.begin(), segments.end());
  cout << segments.size() << '\n';
  for (auto[l, r, w] : segments) {
    cout << l << ' ' << r << ' ' << w << '\n';
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