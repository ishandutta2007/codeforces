#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>

#include <stack>
#include <queue>
#include <vector>
#include <cassert>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

namespace lc {
  struct node {
    int val;
    bool proot;
    int dwei;
    int wei;
    node *l, *r, *p;

    node() {}

    node(int val) : val(val) { 
      proot = true; 
      l = r = p = NULL;
      wei = 1;
      dwei = 0;
    }

    void update () {
      assert(dwei >= 0);
      wei = 1 + dwei;
      if (l) wei += l->wei;
      if (r) wei += r->wei;
    }

    void setl(node *n) { l = n; if (n) n->p = this; update(); }
    void setr(node *n) { r = n; if (n) n->p = this; update(); }
  };

  node *last;
  node nodes[200005];

  void init(int N) {
    REP(i, N) nodes[i] = node(i + 1);
  }

  node *rot(node *a, node *b) {
    node *p = b->p;

    if (a == b->l) {
      b->setl(a->r); a->setr(b);
    } else {
      b->setr(a->l); a->setl(b);
    }

    if (p && !b->proot) {
      if (p->l == b)
        p->setl(a);
      else
        p->setr(a);
    } else if (b->proot) {
      a->proot = true;
      b->proot = false;
    }

    a->p = p;

    return a;
  }

  node *splay(node *n) {
    node *p, *pp;
    while (n->p && n->p->p && !n->proot && !n->p->proot && !n->p->p->proot) {
      p = n->p; pp = p->p;
      if ((n == p->l) ^ (p == pp->l))
        n = rot(rot(n, p), pp);
      else
        n = rot(n, rot(p, pp));
    }

    while (n->p && !n->proot) n = rot(n, n->p);

    return n;
  }

  
  void access(node *n) {
    splay(n);
    last = n;
    if (n->r) {
      n->r->proot = true;
      n->dwei += n->r->wei;
      n->setr(NULL);
    }
    while (n->p != NULL) {
      splay(n->p);

      if (n->p->r) {
        n->p->r->proot = true;
	n->p->dwei += n->p->r->wei;
      }

      n->proot = false;
      n->p->dwei -= n->wei;
      n->p->setr(n);
      last = n->p;
      splay(n);
    }
  }

  node *pfind_root(node *n) {
    access(n);
    for (node *it = n; ; it = it->l) {
      if (it->l == NULL) {
        return splay(it);
      }
    }
  }

  node *pparent(node *n) {
    access(n);
    if (n->l == NULL) return NULL;
    for (node *it = n->l; ; it = it->r) {
      if (it->r == NULL) {
        return splay(it);
      }
    }
  }

  void plink(node *n, node *m) { // n je root svojeg podstabla
    access(n);
    access(m);
    m->setr(n);
    n->proot = false;
  }

  void pcut(node *n) {
    access(n);
    n->l->proot = true;
    n->l->p = NULL;
    n->setl(NULL);
  }

  void inorder(node *n) {
    if (n == NULL) return;
    printf("(");
    inorder(n->l);
    printf("%d ", n->val);
    inorder(n->r);
    printf(")");
  }

#define fix(n) (!(n) ? -1 : (n)->val)

  void link(int n, int m) { plink(&nodes[n - 1], &nodes[m - 1]); }
  void unlink(int n, int m) {
    node *p = pparent(&nodes[n - 1]);
    if (p == &nodes[m - 1])
      pcut(&nodes[n - 1]);
    else
      pcut(&nodes[m - 1]);
  }
  int get_cnt(int n) { 
    node *r = pfind_root(&nodes[n - 1]);
    return r->wei;
  }
};

const int MAXN = 100005;

int n, q;
vector< pair< int, int > > T[MAXN];

llint dist[MAXN];
llint best[MAXN];
int alive[MAXN];
int p[MAXN];

int far(int i, llint d = 0, int dad = -1) {
  dist[i] = d;
  int ret = i;

  for (auto jt : T[i]) {
    int j = jt.first;
    int w = jt.second;
    if (j == dad) continue;
    int r = far(j, d + w, i);
    if (dist[r] > dist[ret]) ret = r;
  }

  return ret;
}

void spread(int i, llint d = 0, int dad = -1) {
  best[i] = max(best[i], d);
  
  for (auto jt : T[i]) {
    int j = jt.first;
    int w = jt.second;
    if (j == dad) continue;
    spread(j, d + w, i);
  }
}

int main(void)
{
  lc :: init(100005);
  scanf("%d", &n);

  REP(i, n - 1) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    T[a].push_back({b, w});
    T[b].push_back({a, w});
  }

  int a = far(1); spread(a);
  int b = far(a); spread(b);

  REP(i, n) p[i] = i + 1;
  sort(p, p + n, [](int a, int b) {
      return best[a] < best[b];
    });

  scanf("%d", &q);

  REP(i, q) {
    llint l; cin >> l;

    int sol = 0;
    for (int a = 0, b = -1; a < n; ++a) {
      while (b + 1 < n && (b < a || best[p[b + 1]] - best[p[a]] <= l)) {
	++b;
	alive[p[b]] = 1;
	for (auto it : T[p[b]]) {
	  if (!alive[it.first]) continue;
	  lc :: link(p[b], it.first);
	}
	sol = max(sol, lc :: get_cnt(p[b]));
      }
      for (auto it : T[p[a]]) {
	if (!alive[it.first]) continue;
	lc :: unlink(it.first, p[a]);
      }
      alive[p[a]] = 0;
    }

    printf("%d\n", sol);
  }

  return 0;
}