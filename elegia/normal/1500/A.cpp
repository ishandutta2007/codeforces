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

const int N = 200010;

pair<int, int> way[5000010];
int a[N], cnt[5000010];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; ++i) v.emplace_back(a[i], i);
  sort(v.begin(), v.end());
  vector<int> ind;
  ind.push_back(v[0].second);
  for (int i = 1; i != n; ++i) if (v[i].first != v[i - 1].first) ind.push_back(v[i].second);
  sort(ind.begin(), ind.end());
  for (int i : ind)
    for (int j : ind) {
      if (j >= i) break;
      int t = a[i] + a[j];
      if (way[t].first) {
        cout << "YES\n";
        cout << way[t].first << ' ' << way[t].second << ' ' << i << ' ' << j << '\n';
        return 0;
      }
      way[t] = make_pair(i, j);
    }
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  vector<int> fa;
  auto getf = [&](int x, int k) {
    vector<int> vec;
    for (int i = 1; i <= n; ++i) if (a[i] == x) vec.push_back(i);
    vec.resize(k);
    return vec;
  };
  for (int i = 1; i <= 5000000; ++i) {
    if (cnt[i] >= 2) fa.push_back(i);
    if (cnt[i] >= 4) {
      cout << "YES\n" << getf(i, 4) << '\n';
      return 0;
    }
  }
  if (fa.size() >= 2) {
    auto a = getf(fa[0], 2), b = getf(fa[1], 2);
    cout << "YES\n" << a[0] << ' ' << b[0] << ' ' << a[1] << ' ' << b[1] << '\n';
    return 0;
  }
  for (int val : fa)
    if (way[val * 2].first) {
      cout << "YES\n" << getf(val, 2) << ' ' << way[val * 2].first << ' ' << way[val * 2].second << '\n';
      return 0;
    }
  cout << "NO\n";

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}