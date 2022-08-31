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

template <class T>
void chkMax(T& x, const T& y) {
  if (x < y) x = y;
}

template <class T>
void chkMin(T& x, const T& y) {
  if (x > y) x = y;
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
    int n, m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    map<int, int> cnt;
    for (int x : a) ++cnt[x];
    vector<vector<int>> dif(n + 1);
    for (auto [x, c] : cnt) dif[c].push_back(x);
    vector<int> ec;
    for (int i = 1; i <= n; ++i) if (!dif[i].empty()) ec.push_back(i);
    set<pair<int, int>> st;
    for (int i = 0; i != m; ++i) {
      int x, y; cin >> x >> y;
      st.insert(make_pair(x, y));
      st.insert(make_pair(y, x));
    }
    ll best = 0;
    for (int c : ec) {
      for (int x : dif[c]) {
        for (int d : ec) {
          if (dif[d].size() < dif[c].size()) continue;
          int i = dif[d].size() - 1;
          while (i >= 0) {
            if (st.count(make_pair(x, dif[d][i])) || dif[d][i] == x) {
              --i;
              continue;
            }
            best = max(best, (c + d) * (ll) (x + dif[d][i]));
            break;
          }
        }
      }
    }
    cout << best << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}