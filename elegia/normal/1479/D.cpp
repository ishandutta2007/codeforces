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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int N = 300010, B = 12288, L = 20;
using bit_t = ull;

int ctz(unsigned x) { return __builtin_ctz(x); }
int ctz(ull x) { return __builtin_ctzll(x); }

const int BIT = sizeof(bit_t) * 4;

template <size_t N>
struct Bitset {
  bit_t a[N / BIT + 1];

  Bitset() {}
  Bitset(const Bitset& bs) { memcpy(a, bs.a, sizeof(a)); }

  void sx(const Bitset& x, const Bitset& y) {
    for (int i = 0; i != N / BIT + 1; ++i) a[i] = x.a[i] ^ y.a[i];
  }

  void flip(int k) { a[k / BIT] ^= bit_t(1) << (k % BIT); }
  int fir(int l) const {
    int li = l / BIT;
    for (int j = l % BIT; j != BIT; ++j) if ((a[li] >> j) & 1) return j + li * BIT;
    for (++li; li != N / BIT + 1; ++li) if (a[li]) return ctz(a[li]) + li * BIT;
    return -1;
  }
};

int n, m;
int a[N], u[N], v[N], l[N], r[N], ans[N];
int rnd[N], xsum[N];
vector<int> g[N];
Bitset<B> bs[N];
int dep[N], lca[N], p[N][L];

void dfs(int x) {
  dep[x] = dep[p[x][0]] + 1;
  for (int i = 1; i != L; ++i) p[x][i] = p[p[x][i - 1]][i - 1];
  for (int y : g[x]) if (!dep[y]) {
    p[y][0] = x; dfs(y);
  }
}

int qlca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 0; i != L; ++i) if (((dep[y] - dep[x]) >> i) & 1) y = p[y][i];
  if (x == y) return x;
  for (int i = L - 1; i >= 0; --i) if (p[x][i] != p[y][i]) {
    x = p[x][i]; y = p[y][i];
  }
  return p[x][0];
}

int low, high;

void dfs2(int x) {
  bs[x] = bs[p[x][0]];
  xsum[x] = xsum[p[x][0]];
  if (a[x] >= low && a[x] <= high) {
    bs[x].flip(a[x] - low);
    xsum[x] ^= rnd[a[x]];
  }
  for (int y : g[x]) if (y != p[x][0]) dfs2(y);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) rnd[i] = rng();
  for (int rep = 1; rep != n; ++rep) {
    int x, y; cin >> x >> y;
    g[x].push_back(y); g[y].push_back(x);
  }
  for (int i = 1; i <= m; ++i) cin >> u[i] >> v[i] >> l[i] >> r[i];
  fill(ans + 1, ans + m + 1, -1);
  dfs(1);
  for (int i = 1; i <= m; ++i) lca[i] = qlca(u[i], v[i]);
  for (low = 1, high = B; low <= n; low += B, high += B) {
    dfs2(1);
    for (int i = 1; i <= m; ++i) if (ans[i] == -1 && max(low, l[i]) <= min(high, r[i])) {
      int lc = lca[i];
      int xs = xsum[u[i]] ^ xsum[v[i]];
      if (a[lc] >= low && a[lc] <= high) xs ^= rnd[a[lc]];
      if (xs == 0) continue;
      static Bitset<B> cur;
      cur.sx(bs[u[i]], bs[v[i]]);
      if (a[lc] >= low && a[lc] <= high) cur.flip(a[lc] - low);
      int pos = cur.fir(max(low, l[i]) - low);
      if (pos != -1) {
        pos += low;
        if (pos <= r[i]) ans[i] = pos;
      }
    }
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}