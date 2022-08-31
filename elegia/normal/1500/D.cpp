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

const int N = 1510;

int n, q;

int a[N][N];
int ans[N];
bool pol[N * N];
pair<int, int> x[N][N][11], y[N][N][11];
int sx[N][N], sy[N][N];

typedef pair<int, int> pii;

int uniq(pii *arr, int sz, pii *otp) {
  int res = 0;
  for (int i = 0; i != sz; ++i) {
    if (!pol[arr[i].second]) otp[res++] = arr[i];
    pol[arr[i].second] = true;
    if (res == q) break;
  }
  for (int i = 0; i != sz; ++i) pol[arr[i].second] = false;
  return res;
}

pii tmp[N];
pii pmt[N];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  ++q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      {
        int cs = sx[i - 1][j - 1] + sx[i][j - 1];
        merge(x[i - 1][j - 1], x[i - 1][j - 1] + sx[i - 1][j - 1],
              x[i][j - 1], x[i][j - 1] + sx[i][j - 1], tmp + 1);
        for (int k = 1; k <= cs; ++k) ++tmp[k].first;
        tmp[0].first = 0;
        tmp[0].second = a[i][j];
        sx[i][j] = uniq(tmp, cs + 1, x[i][j]);
      }
      {
        int cs = sy[i - 1][j - 1] + sy[i - 1][j];
        merge(y[i - 1][j - 1], y[i - 1][j - 1] + sy[i - 1][j - 1],
              y[i - 1][j], y[i - 1][j] + sy[i - 1][j], tmp + 1);
        for (int k = 1; k <= cs; ++k) ++tmp[k].first;
        tmp[0].first = 0;
        tmp[0].second = a[i][j];
        sy[i][j] = uniq(tmp, cs + 1, y[i][j]);
      }
      merge(x[i][j], x[i][j] + sx[i][j], y[i][j], y[i][j] + sy[i][j], tmp);
      if (uniq(tmp, sx[i][j] + sy[i][j], pmt) == q) {
        ++ans[min({pmt[q - 1].first, i, j})];
      } else ++ans[min(i, j)];
    }
  }

  for (int i = n; i; --i) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}