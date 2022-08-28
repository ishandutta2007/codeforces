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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 300010;

struct Node {
  union {
    struct {
      Node *ls, *rs;
    };
    Node *ch[2];
  };
  bool rev;
  Node *prt, *pth;

  bool rel() const { return this == prt->rs; }

  void pd() {
    if (rev) {
      swap(ls, rs);
      for (int i = 0; i < 2; ++i)
        if (ch[i])
          ch[i]->rev ^= true;
      rev = false;
    }
  }

  void upd() {
  }

  void rot() {
    if (prt->prt)
      prt->prt->pd();
    prt->pd();
    pd();
    swap(pth, prt->pth);
    bool f = rel();
    Node *p = prt;
    if (prt->prt) prt->prt->ch[prt->rel()] = this;
    prt = prt->prt;
    p->ch[f] = ch[!f];
    if (ch[!f]) ch[!f]->prt = p;
    p->prt = this;
    ch[!f] = p;
    p->upd();
    upd();
  }

  void spl(Node *goal = NULL) {
    while (prt != goal) {
      if (prt->prt == goal)
        return rot();
      prt->prt->pd();
      prt->pd();
      if (rel() == prt->rel()) {
        prt->rot();
        rot();
      } else {
        rot();
        rot();
      }
    }
  }

  void expose() {
    spl();
    pd();
    if (rs) {
      rs->pth = this;
      rs->prt = NULL;
      rs = NULL;
      upd();
    }
  }

  bool splice() {
    spl();
    if (!pth)
      return false;
    pth->expose();
    pth->rs = this;
    prt = pth;
    pth = NULL;
    prt->upd();
    return true;
  }

  void access() {
    expose();
    while (splice());
  }

  void evert() {
    access();
    rev ^= true;
  }

  Node *getRoot() {
    access();
    Node *p = this;
    while ((p->pd(), p->ls))
      p = p->ls;
    return (p->spl(), p);
  }
};

void link(Node *x, Node *y) {
  x->evert();
  x->pth = y;
}

void cut(Node *x, Node *y) {
  x->evert();
  y->access();
  x->expose();
  y->pth = NULL;
}

bool connected(Node *x, Node *y) {
  return x->getRoot() == y->getRoot();
}

Node pool[N];

int n, m;
int l[N];
vector<int> prv[N], nxt[N];
ll ans[N];
vector<tuple<int, int, int>> qry[N];

struct FW {
  ll fw[N];

  void ch(int k, int x) {
    for (; k <= n; k += k & -k)
      fw[k] += x;
  }

  ll qry(int k) {
    ll ret = 0;
    for (; k; k &= k - 1)
      ret += fw[k];
    return ret;
  }
} fw0, fw1;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  int cur = 0;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    nxt[a].push_back(b);
    prv[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : prv[i]) {
      if (j <= cur) continue;
      while (connected(pool + i, pool + j)) {
        ++cur;
        for (int u : nxt[cur])
          cut(pool + u, pool + cur);
        if (j <= cur) break;
      }
      if (j <= cur) continue;
      link(pool + i, pool + j);
    }
    l[i] = cur;
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    qry[x].emplace_back(y, x, i);
    qry[y + 1].emplace_back(y, x, -i);
  }

  auto gval = [&](int r) {
    return fw0.qry(r) * r - fw1.qry(r);
  };

  for (int i = n; i; --i) {
    fw0.ch(l[i] + 1, 1);
    fw1.ch(l[i] + 1, l[i]);
    fw0.ch(i + 1, -1);
    fw1.ch(i + 1, -i);
    for (const auto[r, l, id] : qry[i]) {
      if (id > 0) {
        ans[id] += gval(r) - gval(l - 1);
      } else {
        ans[-id] -= gval(r) - gval(l - 1);
      }
    }
  }
  for (int i = 1; i <= q; ++i)
    cout << ans[i] << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}