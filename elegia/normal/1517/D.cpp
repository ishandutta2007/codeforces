/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> ans(n, vector<int>(m)), x(n, vector<int>(m - 1)), y(n - 1, vector<int>(m));
  cin >> x >> y;
  if (k % 2) {
    ans.assign(n, vector<int>(m, -1));
    for (int i = 0; i != n; ++i) {
      cout << ans[i] << '\n';
    }
  } else {
    k /= 2;
    while (k--) {
      vector<vector<int>> dp(n, vector<int>(m, numeric_limits<int>::max()));
      for (int i = 0; i != n; ++i)
        for (int j = 0; j != m - 1; ++j) {
          dp[i][j] = min(dp[i][j], ans[i][j + 1] + x[i][j]);
          dp[i][j + 1] = min(dp[i][j + 1], ans[i][j] + x[i][j]);
        }
      for (int i = 0; i != n - 1; ++i)
        for (int j = 0; j != m; ++j) {
          dp[i][j] = min(dp[i][j], ans[i + 1][j] + y[i][j]);
          dp[i + 1][j] = min(dp[i + 1][j], ans[i][j] + y[i][j]);
        }
      swap(ans, dp);
    }
    for (int i = 0; i != n; ++i) {
      for (int& v : ans[i]) v *= 2;
      cout << ans[i] << '\n';
    }
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}