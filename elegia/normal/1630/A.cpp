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
    int N, k; cin >> N >> k;
    int n = __builtin_ctz(N);
    if (k != N - 1) {
      vector<int> vis(N / 2);
      if (k) {
        cout << k << ' ' << N - 1 << '\n';
        cout << N - 1 - k << ' ' << 0 << '\n';
        vis[0] = 1;
        if ((k >> (n - 1)) & 1) k ^= N - 1;
        vis[k] = 1;
      }
      for (int i = 0; i != N / 2; ++i) if (!vis[i])
        cout << i << ' ' << N - 1 - i << '\n';
    } else if (n == 2) {
      cout << "-1\n";
    } else {
      int U = N - 1, x = 1 << (n - 1), y = 1 << (n - 2);
      vector<int> vis(N / 2);
      cout << (x ^ y) << ' ' << (U ^ y) << '\n';
      cout << (U ^ x ^ y) << ' ' << (y) << '\n';
      cout << (U) << ' ' << (U ^ x) << '\n';
      cout << (x) << ' ' << (0) << '\n';
      vis[U ^ x] = vis[0] = vis[y] = vis[U ^ x ^ y] = 1;
      for (int i = 0; i != N / 2; ++i) if (!vis[i])
          cout << i << ' ' << N - 1 - i << '\n';
    }
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}