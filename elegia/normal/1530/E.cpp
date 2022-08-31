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

string solve() {
  string s; cin >> s;
  {
    char c = s[0];
    if (count(s.begin(), s.end(), c) == s.length()) return s;
  }
  vector<int> cnt(26);
  for (char c : s) ++cnt[c - 'a'];
  for (int i = 0; i != 26; ++i) if (cnt[i] == 1) {
    string ans = string(1, 'a' + i);
    --cnt[i];
    for (int j = 0; j != 26; ++j) while (cnt[j]--)
      ans.push_back(j + 'a');
    return ans;
  }
  auto tmp = cnt;
  int k = 0; while (!cnt[k]) ++k;
  {
    cnt[k] -= 2; string ans(2, 'a' + k);
    for (int i = k + 1; i != 26; ++i) while (cnt[i]--) {
      ans.push_back('a' + i);
      if (cnt[k]-- > 0) {
        ans.push_back('a' + k);
      }
    }
    if (cnt[k] <= 0) return ans;
    cnt = tmp;
  }
  int j = k + 1; while (!cnt[j]) ++j;
  --cnt[k]; string ans(1, k + 'a');
  --cnt[j]; ans.push_back(j + 'a');
  if (tmp[k] + tmp[j] == s.length()) {
    while (cnt[j]--) ans.push_back(j + 'a');
    while (cnt[k]--) ans.push_back(k + 'a');
    return ans;
  }
  while (cnt[k]--) ans.push_back(k + 'a');
  int ano = j + 1;
  while (!cnt[ano]) ++ano;
  --cnt[ano]; ans.push_back(ano + 'a');
  for (int i = j; i != 26; ++i) while (cnt[i]--)
    ans.push_back(i + 'a');
  return ans;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) cout << solve() << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}