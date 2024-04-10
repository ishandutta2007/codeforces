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
#include <iostream>
#include <limits>
#include <numeric>

#define MP make_pair

using namespace std;

typedef priority_queue<int> PQ;

#ifdef LBT

const int N = 100;

#else

const int N = 100010;

#endif

struct Node {
  int l, r, v;
  Node *ls, *rs;

  void*operator new(size_t) {
    static Node pool[N * 4];
    static Node* ptop = pool;
    return ptop++;
  }

  void upd() {
    v = max(ls->v, rs->v);
  }

  void ch(int k, int x) {
    if (l == r) {
      v = x;
      return;
    }
    (k <= ls->r ? ls : rs)->ch(k, x);
    upd();
  }

  int qry(int l, int r) const {
    if (this->l == l && this->r == r)
      return v;
    if (r <= ls->r)
      return ls->qry(l, r);
    if (l >= rs->l)
      return rs->qry(l, r);
    return max(ls->qry(l, ls->r), rs->qry(rs->l, r));
  }
};

Node* build(int l, int r) {
  Node* p = new Node;
  p->l = l;
  p->r = r;
  if (l == r)
    return p;
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

int n, m, cnt;
int a[N], ans[N], stk[N], cl[N], cr[N], cc[N];
vector<pair<int, pair<int, int>> > qry[N], sch1[N], sch2[N], sch3[N], sch4[N];
map<int, pair<int, int> > seg1, seg2, seg3, seg4; // ^ - \ V
priority_queue<int> q1[N], q2[N], dq1[N], dq2[N];
Node *sgt1, *sgt2;

int qtop(const PQ& pq) {
  return pq.empty() ? 0 : pq.top();
}

void ins(PQ* q, PQ* dq, Node* sgt, int k, int x) {
  if (x > qtop(q[k])) {
    sgt->ch(k, x);
  }
  q[k].push(x);
}

void ers(PQ* q, PQ* dq, Node* sgt, int k, int x) {
  dq[k].push(x);
  bool f = false;
  while (!dq[k].empty() && q[k].top() == dq[k].top()) {
    q[k].pop();
    dq[k].pop();
    f = true;
  }
  if (f)
    sgt->ch(k, qtop(q[k]));
}

void dis(PQ* q, PQ* dq, Node* sgt, int k, int x) {
  if (x < 0)
    ers(q, dq, sgt, k, -x);
  else
    ins(q, dq, sgt, k, x);
}

int main() {

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    qry[k].push_back(MP(i, MP(l, r - k + 1)));
  }
  for (int i = 1; i <= n; ++i) {
    int cur = 1;
    cl[i] = i;
    while (cnt && a[stk[cnt - 1]] >= a[i]) {
      --cnt;
      cl[i] -= cc[cnt];
      cur += cc[cnt];
      cr[stk[cnt]] = i - 1;
    }
    cc[cnt] = cur;
    stk[cnt++] = i;
  }
  while (cnt)
    cr[stk[--cnt]] = n;
  for (int i = 1; i <= n; ++i) {
    int x1 = i, y1 = 1, x2 = cl[i], y2 = cr[i] - cl[i] + 1;
    sch1[y2 + 1].push_back(MP(-a[i], MP(x2, y2)));
    sch4[y1].push_back(MP(a[i], MP(x1, y1)));
    int d;
    if ((x1 - x2) * 2 <= (y2 - y1)) {
      d = x1 - x2;
      if (y1 + d + 1 < y2 - d) {
        sch2[y1 + d + 1].push_back(MP(a[i], MP(x2, x1)));
        sch2[y2 - d].push_back(MP(-a[i], MP(x2, x1)));
        //if (i == 3)
        //  LOG("[%d %d] * [%d %d]\n", x2, x1, y1 + d + 1, y2 - d - 1);
      }
    } else {
      //LOG("HELLO %d\n", a[i]);
      d = y2 - y1 - (x1 - x2);
      //LOG("%d %d %d %d => %d\n", x1, y1, x2, y2, d);
      if (y1 + d + 1 < y2 - d) {
        sch3[y1 + d + 1].push_back(MP(a[i], MP(x1, x1 + d)));
        sch3[y2 - d].push_back(MP(-a[i], MP(x1, x1 + d)));
      }
    }
    sch1[y2 - d].push_back(MP(a[i], MP(x2, y2)));
    sch4[y1 + d + 1].push_back(MP(-a[i], MP(x1, y1)));
  }
  sgt1 = build(1, n);
  sgt2 = build(1, n);
  for (int k = 1; k <= n; ++k) {
/*#define SRT(X) sort(sch##X[k].begin(), sch##X[k].end(), greater<pair<int, pair<int, int> > >())
    SRT(1);
    SRT(2);
    SRT(3);
    SRT(4);*/
    for (const auto& pr : sch1[k]) {
      dis(q1, dq1, sgt1, pr.second.first, pr.first);
      if (pr.first < 0)
        seg1.erase(pr.second.first);
      else
        seg1.insert(MP(pr.second.first, MP(pr.second.second, pr.first)));
    }
    for (const auto& pr : sch2[k]) {
      dis(q1, dq1, sgt1, pr.second.first, pr.first);
      if (pr.first < 0) {
        seg2.erase(pr.second.first);
      } else {
        seg2.insert(MP(pr.second.first, MP(pr.second.second, pr.first)));
        //LOG("INS %d %d %d\n", pr.second.first, pr.second.second, pr.first);
      }
    }
    for (const auto& pr : sch3[k]) {
      dis(q2, dq2, sgt2, pr.second.second, pr.first);
      if (pr.first < 0)
        seg3.erase(pr.second.second);
      else
        seg3.insert(MP(pr.second.second, MP(pr.second.first, pr.first)));
    }
    for (const auto& pr : sch4[k]) {
      dis(q1, dq1, sgt1, pr.second.first, pr.first);
      if (pr.first < 0)
        seg4.erase(pr.second.first);
      else {
        seg4.insert(MP(pr.second.first, MP(1, pr.first)));
      }
    }

    for (const auto& pr : qry[k]) {
      int l = pr.second.first, r = pr.second.second;
      int id = pr.first;
      ans[id] = max(sgt1->qry(l, r), sgt2->qry(l + k - 1, r + k - 1));
      map<int, pair<int, int> >::iterator it;
      it = seg1.lower_bound(l);
      if (it != seg1.begin()) {
        int ll = (--it)->first;
        int rr = ll + (it->second.first - k);
        //LOG("%d FND %d %d\n", id, ll, rr);
        if (rr >= l)
          ans[id] = max(ans[id], it->second.second);
      }
      it = seg2.lower_bound(l);
      if (it != seg2.begin()) {
        int rr = (--it)->second.first;
        if (rr >= l)
          ans[id] = max(ans[id], it->second.second);
      }
      it = seg3.upper_bound(r + k - 1);
      if (it != seg3.end()) {
        int ll = it->second.first;
        if (ll <= r + k - 1)
          ans[id] = max(ans[id], it->second.second);
      }
      it = seg4.upper_bound(r);
      if (it != seg4.end()) {
        int rr = it->first;
        int ll = rr - (k - 1);
        //LOG("%d FND %d %d\n", id, ll, rr);
        if (ll <= r)
          ans[id] = max(ans[id], it->second.second);
      }
    }
  }

  for (int i = 1; i <= m; ++i)
    printf("%d\n", ans[i]);

  return 0;
}