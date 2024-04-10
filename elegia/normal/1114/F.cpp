#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

struct IO_Tp
{
  const static int _I_Buffer_Size = 1 << 24;
  char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

  const static int _O_Buffer_Size = 1 << 22;
  char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

  IO_Tp()
  {
#ifdef LBT
    freopen("test.in", "r", stdin);
#endif
    fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
  }

  ~IO_Tp()
  {
    fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout);
  }

  IO_Tp &operator>>(int &res)
  {
    while (!isdigit(*_I_pos))
      ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos))
      (res *= 10) += *_I_pos++ & 15;
    return *this;
  }

  IO_Tp &operator>>(uint &res)
  {
    while (!isdigit(*_I_pos))
      ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos))
      (res *= 10) += *_I_pos++ & 15;
    return *this;
  }

  char get() {
    return *_I_pos++;
  }

  IO_Tp &operator<<(uint n)
  {
    static char _buf[10];
    char* _pos = _buf;
    do
      *_pos++ = '0' + n % 10;
    while (n /= 10);
    while (_pos != _buf)
      *_O_pos++ = *--_pos;
    return *this;
  }

  IO_Tp &operator<<(char ch)
  {
    *_O_pos++ = ch;
    return *this;
  }
} IO;

struct Node {
  int l, r;
  ll s, lz;
  Node *ls, *rs;

  ll get() const { return s | lz; }

  void pd() {
    if (lz) {
      ls->lz |= lz;
      rs->lz |= lz;
      s |= lz;
      lz = 0;
    }
  }

  void upd() {
    s = ls->get() | rs->get();
  }

  void ch(int l, int r, ll x) {
    if (this->l == l && this->r == r) {
      lz |= x;
      return;
    }
    pd();
    if (r <= ls->r)
      ls->ch(l, r, x);
    else if (l >= rs->l)
      rs->ch(l, r, x);
    else {
      ls->ch(l, ls->r, x);
      rs->ch(rs->l, r, x);
    }
    upd();
  }

  ll qry(int l, int r) {
    if (this->l == l && this->r == r)
      return get();
    pd();
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    return ls->qry(l, ls->r) | rs->qry(rs->l, r);
  }
};

const int N = 400010, P = 1000000007, X = 301;

int n, pc;
int a[N];
int pr[X], tot[X];
ll pf[X];
int fw[2][N];

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}


int lowBit(int k) { return k & -k; }

void ch(int* fw, int k, int x) {
  for (; k <= n; k += lowBit(k))
    fw[k] = fw[k] * (ll)x % P;
}

int qry(int* fw, int k) {
  int ret = 1;
  for (; k; k -= lowBit(k))
    ret = ret * (ll)fw[k] % P;
  return ret;
}

void ch(int k, int x) {
  ch(fw[0], k, mpow(x, P - k));
  ch(fw[1], k, x);
}

int qry(int k) {
  return qry(fw[0], k) * (ll)mpow(qry(fw[1], k), k) % P;
}

void ch(int l, int r, int x) {
  ch(l, x);
  ch(r + 1, mpow(x, P - 2));
}

int qry(int l, int r) {
  return qry(r) * (ll)mpow(qry(l - 1), P - 2) % P;
}

Node pool[N << 1];
Node* ptop = pool;

Node* build(int l, int r) {
  Node* p = ptop++;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->s = pf[a[l]];
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->upd();
  return p;
}

int main() {
#ifdef LBT
  int nol_cl = clock();
#endif

  int q;
  IO >> n >> q;
  for (int i = 0; i < 2; ++i)
    fill(fw[i] + 1, fw[i] + n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    IO >> a[i];
    ch(fw[0], i, a[i]);
  }
  for (int x = 2; x < X; ++x) {
    if (!pf[x]) {
      tot[pc] = (x - 1) * (ll)mpow(x, P - 2) % P;
      pr[pc] = x;
      for (int y = x; y < X; y += x)
        pf[y] |= 1LL << pc;
      ++pc;
    }
  }
  Node* seg = build(1, n);
  while (q--) {
    int l, r, x;
    IO.get();
    char opt = IO.get();
    IO >> l >> r;
    if (opt == 'T') {
      int ans = qry(l, r);
      ll pp = seg->qry(l, r);
      for (int i = 0; i < pc; ++i)
        if (pp >> i & 1)
          ans = ans * (ll)tot[i] % P;
      IO << (uint)ans << '\n';
    } else {
      IO >> x;
      ch(l, r, x);
      seg->ch(l, r, pf[x]);
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}