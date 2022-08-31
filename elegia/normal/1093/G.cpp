#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

struct Node {
  int l, r, v;
  Node *ls, *rs;

  int qry(int l, int r) const {
    if (l == this->l && r == this->r)
      return v;
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    return max(ls->qry(l, ls->r), rs->qry(rs->l, r));
  }

  void set(int k, int x) {
    if (l == r) {
      v = x;
      return;
    }
    if (k <= ls->r)
      ls->set(k, x);
    else
      rs->set(k, x);
    v = max(ls->v, rs->v);
  }
};

const int N = 200010, K = 5;

int n, k;
int a[N][K], tmp[N];
Node* seg[1 << K];

Node* build(int l, int r);

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < k; ++j)
      scanf("%d", &a[i][j]);
  for (int s = 0; s < (1 << k); ++s) {
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < k; ++j) {
      int eff = (s >> j & 1) ? -1 : 1;
      for (int i = 1; i <= n; ++i)
        tmp[i] += eff * a[i][j];
    }
    seg[s] = build(1, n);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int pos;
      scanf("%d", &pos);
      for (int i = 0; i < k; ++i)
        scanf("%d", &tmp[i]);
      for (int s = 0; s < (1 << k); ++s) {
        int cur = 0;
        for (int j = 0; j < k; ++j)
          if (s >> j & 1)
            cur -= tmp[j];
        	else
         	 	cur += tmp[j];
        seg[s]->set(pos, cur);
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = 0;
      for (int s = 0; s < (1 << (k - 1)); ++s)
        ans = max(ans, seg[s]->qry(l, r) + seg[~s & ((1 << k) - 1)]->qry(l, r));
      printf("%d\n", ans);
    }
  }
  return 0;
}

Node* build(int l, int r) {
  static Node pool[N * 2 << K];
  static Node* ptop = pool;
  Node* p = ptop;
  ++ptop;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->v = tmp[l];
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->v = max(p->ls->v, p->rs->v);
  return p;
}