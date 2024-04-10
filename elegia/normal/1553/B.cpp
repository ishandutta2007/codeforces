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

  int T; cin >> T;
  while (T--) {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> pre(m, vector<int>(n)), suf(m, vector<int>(n));
    for (int i = 0; i != m; ++i) {
      for (int j = 0; j != n; ++j) {
        pre[i][j] = s[j] == t[i];
        if (i > 0) {
          if (j == 0) pre[i][j] = false;
          pre[i][j] &= pre[i - 1][j - 1];
        }
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = 0; j != n; ++j) {
        suf[i][j] = s[j] == t[i];
        if (i < m - 1) {
          if (j == 0) suf[i][j] = false;
          suf[i][j] &= suf[i + 1][j - 1];
        }
      }
    }
    bool fl = false;
    for (int i = 0; i != m; ++i) {
      for (int j = 0; j != n; ++j)
        if (pre[i][j] && suf[i][j]) {
          fl = true;
          break;
        }
      if (fl) break;
    }
    cout << (fl ? "YES\n" : "NO\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}