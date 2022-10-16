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
  int n, x;
  cin >> n >> x;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    int y; cin >> y;
    int d = 0;
    while (y % x == 0) {
      y /= x;
      d++;
    }
    mp[y].push_back(d);
  }
  int ans = 0;
  for (auto& it : mp) {
    auto vec = it.second;
    int const MX = 30;
    vector<int> cnt(MX);
    for (int x : vec) cnt[x]++;
    for (int i = 0; i + 1 < MX; ++i) {
      int z = min(cnt[i], cnt[i+1]);
      cnt[i] -= z;
      cnt[i+1] -= z;
    }
    ans += accumulate(cnt.begin(), cnt.end(), 0);
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