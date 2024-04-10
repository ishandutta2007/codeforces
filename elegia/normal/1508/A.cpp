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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s(3);
    cin >> s;
    vector<int> cnt(3);
    for (int i = 0; i != 3; ++i) cnt[i] = count(s[i].begin(), s[i].end(), '0');
    auto build = [&](const string& a, const string& b, char c) {
      string ret;
      int i = 0, j = 0;
      while (i != n * 2 || j != n * 2) {
        if (i == n * 2) ret.push_back(b[j++]);
        else if (j == n * 2) ret.push_back(a[i++]);
        else if (a[i] == b[j]) {
          ret.push_back(a[i++]); ++j;
        } else if (a[i] != c) ret.push_back(a[i++]);
        else ret.push_back(b[j++]);
      }
      return ret;
    };
    string ans;
    for (int i = 0; i != 3; ++i) {
      for (int j = 0; j != 3; ++j)
        if (i != j) {
          if (min(cnt[i], cnt[j]) >= n) ans = build(s[i], s[j], '0');
          else if (min(2 * n - cnt[i], 2 * n - cnt[j]) >= n) ans = build(s[i], s[j], '1');
          if (!ans.empty()) break;
        }
      if (!ans.empty()) break;
    }
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}