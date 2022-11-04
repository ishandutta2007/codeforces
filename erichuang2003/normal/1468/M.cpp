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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 200010;

int d[N], cnt[N];
vector<int> a[N], b[N];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; ++i) {
      int k;
      cin >> k;
      a[i].resize(k);
      cin >> a[i];
      for (int v : a[i]) d[++m] = v;
    }
    sort(d + 1, d + m + 1);
    for (int i = 1; i <= m; ++i) b[i].clear();
    for (int i = 1; i <= n; ++i)
      for (int &v : a[i])
        b[v = lower_bound(d + 1, d + m + 1, v) - d].push_back(i);
    int B = sqrt(m);
    fill(cnt + 1, cnt + m + 1, 0);
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i)
      if (a[i].size() >= B) {
        for (int j : a[i]) cnt[j] = i;
        for (int j = 1; j <= n; ++j)
          if (i != j) {
            int cn = 0;
            for (int v : a[j])
              if (cnt[v]) ++cn;
            if (cn >= 2) {
              x = i;
              y = j;
              break;
            }
          }
        if (x) break;
        for (int j : a[i]) cnt[j] = 0;
      }
    if (!x) {
      for (int i = 1; i <= m; ++i) {
        for (int j : b[i]) {
          if (a[j].size() >= B) continue;
          for (int k : a[j])
            if (k != i) {
              if (cnt[k]) {
                x = j;
                y = cnt[k];
                break;
              }
              cnt[k] = j;
            }
          if (x) break;
        }
        if (x) break;
        for (int j : b[i]) {
          if (a[j].size() >= B) continue;
          for (int k : a[j])
            if (k != i) {
              cnt[k] = 0;
            }
        }
      }
    }
    if (x) cout << x << ' ' << y << '\n';
    else cout << "-1\n";
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}