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

const int K = 19;
const int INF = 1e8;

bool vis[2 << K];
int ans[1 << K], myn[1 << K];

void solve(int o, int k, int l) {
  if (k == 0) {
    ans[l] = INF;
    myn[l] = vis[o] ? 0 : INF;
    return;
  }
  solve(o << 1, k - 1, l);
  solve(o << 1 | 1, k - 1, l + (1 << (k - 1)));
  vis[o] = vis[o << 1] | vis[o << 1 | 1];
  for (int i = 0; i != 1 << (k - 1); ++i)
    ans[l + i] = ans[l + i + (1 << (k - 1))] = min(ans[l + i], ans[l + i + (1 << (k - 1))]);
  if (vis[o << 1] && vis[o << 1 | 1]) {
    for (int i = 0; i != 1 << (k - 1); ++i) {
      int y = myn[l + i + (1 << (k - 1))], x = myn[l + (1 << (k - 1)) - 1 - i] ^ ((1 << (k - 1)) - 1);
      ans[l + i] = min(ans[l + i], y - x + (1 << (k - 1)));
      y = myn[l + i]; x = myn[l + (1 << k) - 1 - i] ^ ((1 << (k - 1)) - 1);
      ans[l + i + (1 << (k - 1))] = min(ans[l + i + (1 << (k - 1))], y - x + (1 << (k - 1)));
    }
  }
  for (int i = 0; i != 1 << (k - 1); ++i) {
    myn[l + i] = min(myn[l + i], myn[l + i + (1 << (k - 1))] + (1 << (k - 1)));
    myn[l + i + (1 << (k - 1))] = min(myn[l + i + (1 << (k - 1))], myn[l + i] + (1 << (k - 1)));
  }
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  while (n--) {
    int ai; cin >> ai;
    ai += 1 << k;
    vis[ai] = true;
  }
  solve(1, k, 0);
  for (int i = 0; i != 1 << k; ++i) cout << ans[i] << " \n"[i == (1 << k) - 1];
  
#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}