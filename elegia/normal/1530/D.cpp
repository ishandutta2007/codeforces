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
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    for (int& x : a) --x;
    auto tmp = a;
    vector<int> cnt(n);
    for (int i = 0; i != n; ++i) ++cnt[a[i]];
    vector<int> vis(n);
    for (int i = 0; i != n; ++i) if (!cnt[i]) {
      int x = i, s = x;
      vis[x] = 1;
      while (!vis[a[x]]) {
        x = a[x];
        vis[x] = 1;
      }
      a[x] = s;
    }
    vector<int> bad;
    for (int i = 0; i != n; ++i) if (a[i] == i)
      bad.push_back(i);
    if (!bad.empty()) {
      if (bad.size() == 1) {
        int x = bad[0], y = 0;
        while (x == y || a[y] == tmp[y]) ++y;
        a[x] = a[y];
        a[y] = x;
      } else {
        for (int i = 0; i != bad.size(); ++i)
          a[bad[(i + 1) % bad.size()]] = bad[i];
      }
    }
    int ans = 0;
    for (int i = 0; i != n; ++i) {
      if (a[i] == tmp[i]) ++ans;
      ++a[i];
    }
    cout << ans << '\n' << a << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}