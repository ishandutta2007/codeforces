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

void GG() {
  cout << "-1\n";
  exit(0);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> m >> n;
  vector<vector<int>> a(n, vector<int>(m)), b = a;
  for (int i = 0; i != m; ++i) for (int j = 0; j != n; ++j) cin >> a[j][i];
  for (int i = 0; i != m; ++i) for (int j = 0; j != n; ++j) cin >> b[j][i];

  vector<vector<int>> s(n, vector<int>(m)), eq = s;
  for (int i = 0; i != n; ++i) {
    for (int j = 1; j != m; ++j)
      if (b[i][j] >= b[i][j - 1]) s[i][j] = s[i][j - 1];
      else s[i][j] = j;
    for (int j = 1; j != m; ++j)
      if (b[i][j] == b[i][j - 1]) eq[i][j] = eq[i][j - 1];
      else eq[i][j] = j;
  }

  vector<int> seq;

  set<int> div;
  vector<int> ds(m + 1);
  div.insert(0); div.insert(m);
  ds[0] = ds[m] = 1;
  vector<int> cur(n), vis(n);
  auto apply = [&](int i, int l, int r, int sgn) {
    cur[i] += sgn * (s[i][r] > l);
  };
  auto push = [&](int i) {
    if (cur[i] == 0 && !vis[i]) {
      seq.push_back(i);
      vis[i] = true;
    }
  };
  for (int i = 0; i != n; ++i) {
    apply(i, 0, m - 1, 1);
    push(i);
  }
  int ql = 0;
  while (ql < seq.size()) {
    int i = seq[ql++];
    for (int j = 1; j != m; ++j)
      if (b[i][j - 1] != b[i][j] && !ds[j]) {
        ds[j] = 1;
        auto it = div.insert(j).first;
        int l = *prev(it), r = *next(it);
        for (int k = 0; k != n; ++k)
          if (!vis[k]) {
            apply(k, l, j - 1, 1);
            apply(k, j, r - 1, 1);
            apply(k, l, r - 1, -1);
            push(k);
          }
      }
  }
  reverse(seq.begin(), seq.end());

  vector<int> p(m);
  iota(p.begin(), p.end(), 0);
  for (int i : seq) {
    vector<int> cur(m);
    for (int j = 0; j != m; ++j) cur[p[j]] = a[i][j];
    vector<int> q(m), cnt(m);
    for (int x : cur) ++cnt[x - 1];
    for (int j = 1; j != m; ++j) cnt[j] += cnt[j - 1];
    for (int j = m - 1; j >= 0; --j) q[j] = --cnt[cur[j] - 1];
    for (int j = 0; j != m; ++j) p[j] = q[p[j]];
  }
  for (int i = 0; i != n; ++i) {
    vector<int> cur(m);
    for (int j = 0; j != m; ++j) cur[p[j]] = a[i][j];
    swap(a[i], cur);
  }
  if (a == b) {
    cout << seq.size() << '\n';
    for (int& x : seq) ++x;
    cout << seq << '\n';
  } else GG();

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}