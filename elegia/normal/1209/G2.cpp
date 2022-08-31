#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <set>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Data {
  int lv, rv, sum, cur;
  bool fl;
  
  Data() : lv(0), rv(0), sum(0), cur(0), fl(false) {}
  
  Data(int lv, int rv, int sum, int cur, bool fl) : lv(lv), rv(rv), sum(sum), cur(cur), fl(fl) {}
  
  friend Data unite(const Data& lhs, const Data& rhs) {
    int cret = lhs.cur + rhs.cur;
    if (lhs.rv && rhs.lv) --cret;
    if (lhs.fl) {
      if (rhs.fl)
        return Data(max(lhs.lv, rhs.lv), max(lhs.lv, rhs.lv), 0, cret, true);
      return Data(max(lhs.lv, rhs.lv), rhs.rv, rhs.sum, cret, false);
    }
    if (rhs.fl)
      return Data(lhs.lv, max(lhs.rv, rhs.lv), lhs.sum, cret, false);
    return Data(lhs.lv, rhs.rv, lhs.sum + rhs.sum + max(lhs.rv, rhs.lv), cret, false);
  }
};

struct Node {
  int l, r, mx, tag;
  Node *ls, *rs;
  Data v;
  
  void upd() {
    if (l != r) {
      mx = max(ls->mx, rs->mx);
    }
    if (!tag) {
      if (l == r)
        v = Data();
      else
        v = unite(ls->v, rs->v);
    } else {
      v = Data(max(mx, 1), max(mx, 1), 0, r - l + 2, true);
    }
  }

  void setv(int k, int x) {
    if (l == r) {
      mx = x;
      upd();
      return;
    }
    (k <= ls->r ? ls : rs)->setv(k, x);
    upd();
  }
  
  void change(int l, int r, int x) {
    if (this->l == l && this->r == r) {
      tag += x;
      upd();
      return;
    }
    if (r <= ls->r)
      ls->change(l, r, x);
    else if (l >= rs->l)
      rs->change(l, r, x);
    else {
      ls->change(l, ls->r, x);
      rs->change(rs->l, r, x);
    }
    upd();
  }
};

const int N = 200010;

int n, m, cur;
set<int> pos[N];
int a[N];
Node* segTree;

void apply(const set<int>& st, int factor) {
  if (st.size() > 1) {
    segTree->change(*st.begin(), *st.rbegin() - 1, factor);
    if (factor == 1)
      segTree->setv(*st.begin(), st.size());
    else
      segTree->setv(*st.begin(), 0);
  }
}

Node* build(int l, int r) {
  static Node pool[N << 1], *top = pool;
  Node* p = top++;
  p->l = l;
  p->r = r;
  if (l == r) {
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

int gans() {
  return segTree->v.cur - segTree->v.lv - segTree->v.sum;
}

int main() {
//  freopen("test.in", "r", stdin);
//  freopen("test.out", "w", stdout);
  
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]].insert(i);
  }
  segTree = build(1, n);
  for (int i = 1; i <= 200000; ++i)
    apply(pos[i], 1);
  
  printf("%d\n", gans());
  while (q--) {
    int i, x;
    scanf("%d%d", &i, &x);
    apply(pos[a[i]], -1);
    pos[a[i]].erase(i);
    apply(pos[a[i]], 1);
    apply(pos[a[i] = x], -1);
    pos[x].insert(i);
    apply(pos[x], 1);
    printf("%d\n", gans());
  }
  
  return 0;
}