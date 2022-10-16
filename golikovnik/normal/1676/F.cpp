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
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; ++cnt[x];
  }
  vector occs(cnt.begin(), cnt.end());
  tuple<int, int, int> ans{-1, -1, -1};

  int no = int(occs.size());
  for (int i = 0; i < no; ++i) {
    if (occs[i].second < k) {
      continue;
    }
    int j = i;
    while (j + 1 < no && occs[j + 1].first == occs[j].first + 1 && occs[j + 1].second >= k) {
      ++j;
    }
    smax(ans, make_tuple(j - i + 1, occs[i].first, occs[j].first));
    i = j;
  }

  if (get<0>(ans) == -1) {
    cout << -1 << '\n';
  } else {
    cout << get<1>(ans) << ' ' << get<2>(ans) << '\n';
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