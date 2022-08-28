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

const int N = 150010, M = 1000001, X = M + 10;

int n;
int a[N];
int pr[M], f[M], st[M];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

vector<pair<int, int>> ed;

bool test(int s, int t) {
  auto it = lower_bound(ed.begin(), ed.end(), make_pair(s, t));
  if (it == ed.end()) return false;
  return *it == make_pair(s, t);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    f[a[i]] = a[i];
  }
  for (int x = 2; x <= M; ++x) {
    if (pr[x]) continue;
    int tmp = 0;
    for (int i = x; i <= M; i += x) {
      pr[i] = x;
      if (f[i]) {
        if (tmp) f[find(i)] = tmp;
        tmp = find(i);
      }
    }
    st[x] = tmp;
  }

  for (int i = 1; i <= n; ++i) {
    vector<int> cur; cur.push_back(find(a[i]));
    int val = a[i] + 1;
    while (val != 1) {
      int p = pr[val];
      if (st[p]) cur.push_back(find(st[p]));
      val /= p;
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    for (int x : cur) for (int y : cur) if (x < y) ed.emplace_back(x, y);
  }
  sort(ed.begin(), ed.end());

  while (q--) {
    int s, t; cin >> s >> t;
    s = find(a[s]); t = find(a[t]);
    if (s > t) swap(s, t);
    if (s == t) cout << "0\n";
    else if (test(s, t)) {
      cout << "1\n";
    } else cout << "2\n";
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}