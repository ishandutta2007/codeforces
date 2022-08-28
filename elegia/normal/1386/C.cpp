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

const int N = 200010, M = 400010;

struct LCT {
  struct Node {
    bool rev, xsum, xval;
    int val, myn;
    union {
      struct {
        Node *ls, *rs;
      };
      Node *ch[2];
    };
    Node *prt, *path;

    bool relation() const { return this == prt->rs; }

    void pushDown() {
      if (rev) {
        rev = false;
        swap(ls, rs);
        if (ls)
          ls->rev = !ls->rev;
        if (rs)
          rs->rev = !rs->rev;
      }
    }

    void update() {
      myn = val;
      xsum = xval;
      if (ls) {
        myn = min(myn, ls->myn);
        xsum ^= ls->xsum;
      }
      if (rs) {
        myn = min(myn, rs->myn);
        xsum ^= rs->xsum;
      }
    }

    void rotate() {
      if (prt->prt)
        prt->prt->pushDown();
      prt->pushDown();
      pushDown();
      path = prt->path;
      prt->path = NULL;
      bool f = relation();
      Node *p = prt;
      if (p->prt)
        p->prt->ch[p->relation()] = this;
      prt = p->prt;
      p->ch[f] = ch[!f];
      if (ch[!f])
        ch[!f]->prt = p;
      ch[!f] = p;
      p->prt = this;
      p->update();
      update();
    }

    void splay() {
      while (prt) {
        if (!prt->prt)
          return rotate();
        prt->prt->pushDown();
        prt->pushDown();
        if (relation() == prt->relation()) {
          prt->rotate();
          rotate();
        } else {
          rotate();
          rotate();
        }
      }
    }

    void expose() {
      splay();
      pushDown();
      if (rs) {
        rs->path = this;
        rs->prt = NULL;
        rs = NULL;
        update();
      }
    }

    bool splice() {
      splay();
      if (!path)
        return false;
      path->expose();
      path->rs = this;
      prt = path;
      path = NULL;
      prt->update();
      return true;
    }

    void access() {
      expose();
      while (splice());
    }

    void evert() {
      access();
      splay();
      rev = !rev;
    }

    int query() {
      access();
      splay();
      return myn;
    }

    bool odd() {
      access();
      splay();
      return xsum;
    }

    Node *top() {
      access();
      splay();
      Node *p = this;
      while (p->pushDown(), p->ls)
        p = p->ls;
      p->splay();
      return p;
    }
  };

  Node ver[N * 2 + M];

  void link(int u, int v) {
    ver[u].evert();
    ver[u].path = ver + v;
  }

  void cut(int u, int v) {
    ver[u].evert();
    ver[v].access();
    ver[u].expose();
    ver[v].path = NULL;
  }

  int query(int u, int v) {
    ver[u].evert();
    return ver[v].query();
  }

  bool odd(int u, int v) {
    ver[u].evert();
    return ver[v].odd();
  }

  bool conn(int u, int v) {
    return ver[u].top() == ver[v].top();
  }
} mst;

int n, m, q;
int u[M], v[M];
int ansr[M];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) cin >> u[i] >> v[i];
  for (int i = m + 1; i <= m * 2; ++i) {
    u[i] = u[i - m];
    v[i] = v[i - m];
  }
  for (int i = 1; i <= n; ++i) mst.ver[i].val = mst.ver[i].myn = numeric_limits<int>::max();
  int ptr = 1;

  auto rmv = [&](int i) {
    if (mst.conn(n + i, u[i])) {
      mst.cut(n + i, u[i]);
      mst.cut(n + i, v[i]);
    }
  };
  auto ins = [&](int i) {
    if (mst.conn(u[i], v[i])) {
      int j = mst.query(u[i], v[i]);
      rmv(j);
    }
    mst.ver[n + i].xval = mst.ver[n + i].xsum = 1;
    mst.ver[n + i].val = mst.ver[n + i].myn = i;
    mst.link(n + i, u[i]);
    mst.link(n + i, v[i]);
  };

  for (int i = 1; i <= m * 2; ++i) {
    while (ptr < i && mst.conn(u[i], v[i]) && !mst.odd(u[i], v[i])) {
      rmv(ptr++);
    }
    if (mst.conn(u[i], v[i]) && !mst.odd(u[i], v[i]))
      ++ptr;
    else
      ins(i);
    ansr[i] = ptr;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    ++r;
    l += m - 1;
    swap(l, r);
    cout << ((l >= ansr[r]) ? "NO\n" : "YES\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}