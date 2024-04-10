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
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct IO_Tp {
  const static int _I_Buffer_Size = 10 << 20;
  char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

  const static int _O_Buffer_Size = 10 << 20;
  char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

  IO_Tp() {
#ifdef LBT
    freopen("test.in", "r", stdin);
#endif
    fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
  }

  ~IO_Tp() {
    fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout);
  }

  IO_Tp &operator>>(int &res) {
    while (!isdigit(*_I_pos)) ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ & 15);
    return *this;
  }

  IO_Tp &operator>>(ll &res) {
    while (!isdigit(*_I_pos)) ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ & 15);
    return *this;
  }

  IO_Tp &operator<<(ll n) {
    static char _buf[20];
    char *_pos = _buf;
    do
      *_pos++ = '0' + n % 10;
    while (n /= 10);
    while (_pos != _buf) *_O_pos++ = *--_pos;
    return *this;
  }

  IO_Tp &operator<<(char ch) {
    *_O_pos++ = ch;
    return *this;
  }
} IO;

const int N = 100010;

struct Data {
  ll l, r, lm, rm, Lm, Rm, mm, m;

  Data(ll l = 0, ll r = 0) : l(l), r(r), lm(max(l, 0LL)), rm(max(r, 0LL)), Lm(max(l, r)), Rm(max(l, r)), mm(max(l, r)), m(max(l, r)) {}

  Data(ll l, ll r, ll lm, ll rm, ll Lm, ll Rm, ll mm, ll m) : l(l), r(r), lm(lm), rm(rm), Lm(Lm), Rm(Rm), mm(mm), m(m) {}

  Data operator+(const Data& rhs) const {
    ll _l = l + rhs.l, _r = r + rhs.r, _lm = max(lm, l + rhs.lm), _rm = max(rm + rhs.r, rhs.rm),
            _Lm = max({rhs.Lm, rhs.mm + rm, Lm + rhs.l}), _Rm = max({Rm, mm + rhs.lm, rhs.Rm + r}),
            _mm = max(mm + rhs.l, r + rhs.mm), _m = max({m, rhs.m, Lm + rhs.lm, rm + rhs.Rm});
    return Data(_l, _r, _lm, _rm, _Lm, _Rm, _mm, _m);
  }
};

struct Node {
  int l, r;
  Data d;
  Node *ls, *rs;

  void upd() { d = ls->d + rs->d; }

  void ch(int k, ll x) {
    if (l == r) {
      d = Data(x, -x);
      return;
    }
    (k <= ls->r ? ls : rs)->ch(k, x);
    upd();
  }
};

struct E {
  int v;
  ll w;
  int id;
  E* next;
};

int n;
int tin[N], tout[N];
ll cons[N << 1];
bool vis[N];
E* g[N];

void adde(int u, int v, ll w, int id) {
  static E pool[N * 2], *p = pool;
  p->v = v;
  p->w = w;
  p->id = id;
  p->next = g[u];
  g[u] = p;
  ++p;
}

void dfs(int u) {
  static int t;
  vis[u] = true;
  for (E* p = g[u]; p; p = p->next)
    if (!vis[p->v]) {
      tin[p->id] = ++t;
      cons[t] = p->w;
      dfs(p->v);
      tout[p->id] = ++t;
      cons[t] = -p->w;
    }
}

Node* build(int l, int r) {
  static Node pool[N << 2], *top = pool;
  Node* p = top++;
  p->l = l; p->r = r;
  if (l == r) {
    p->d = Data(cons[l], -cons[l]);
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid); p->rs = build(mid + 1, r);
  p->upd();
  return p;
}

int main() {
#ifdef LBT
  int nol_cl = clock();
#endif

  int q;
  ll w;
  IO >> n >> q >> w;
  for (int i = 1; i < n; ++i) {
    int u, v;
    ll x;
    IO >> u >> v >> x;
    adde(u, v, x, i);
    adde(v, u, x, i);
  }
  dfs(1);
  Node* seg = build(1, (n - 1) << 1);
  ll last = 0;
  while (q--) {
    int d;
    ll e;
    IO >> d >> e;
    d = (d + last) % (n - 1) + 1;
    e = (e + last) % w;
    seg->ch(tin[d], e);
    seg->ch(tout[d], -e);
    IO << (last = seg->d.m) << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}