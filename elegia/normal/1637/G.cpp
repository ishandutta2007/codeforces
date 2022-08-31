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
    vector<pair<int, int>> ans;
    vector<int> cnt;
    auto _test = [&](int x, int y) {
      ans.emplace_back(x, y);
      --cnt[x]; --cnt[y]; ++cnt[x + y]; ++cnt[abs(x - y)];
    };
    function<void(int, int)> solve = [&](int n, int mul) {
      auto test = [&](int x, int y) { _test(x * mul, y * mul); };
      if (n <= 2) return;
      int len = 1; while (len < n) len *= 2;
      if (len == n) return solve(n - 1, mul);
      int x = n - len / 2;
      for (int i = 1; i <= x; ++i) test(len / 2 + i, len / 2 - i);
      solve(x, mul * 2); solve(len / 2 - 1 - x, mul);
    };
    int n; cin >> n;
    if (n == 2) {
      cout << "-1\n";
      continue;
    }
    cnt.resize(n * 2); fill(cnt.begin() + 1, cnt.begin() + n + 1, 1);
    solve(n, 1);
    int pos = 0; while (cnt[pos] < 2) ++pos;
    _test(pos, pos);
    for (int i = 1; i < n; ++i)
      while (cnt[i]) {
        _test(i, 0);
        _test(i, i);
      }
    int len = 1; while (len < n) len *= 2; _test(len, 0);
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}