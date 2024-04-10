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

const int N = 100010;

struct Node {
  union {
    struct { Node *ls, *rs; };
    Node* ch[2];
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
    Node* p = prt;
    if (prt->prt) prt->prt->ch[prt->rel()] = this;
    prt = prt->prt;
    p->ch[f] = ch[!f];
    if (ch[!f]) ch[!f]->prt = p;
    p->prt = this;
    ch[!f] = p;
    p->upd();
    upd();
  }

  void spl(Node* goal = NULL) {
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

  Node* splice() {
    spl();
    if (!pth)
      return NULL;
    pth->expose();
    pth->rs = this;
    prt = pth;
    pth = NULL;
    prt->upd();
    return prt;
  }

  void access() {
    expose();
    while (splice());
  }

  void evert() {
    access();
    rev ^= true;
  }
};

void link(Node* x, Node* y) {
  x->evert();
  x->pth = y;
}

void cut(Node* x, Node* y) {
  x->evert();
  y->access();
  x->expose();
  y->pth = NULL;
}

Node lct[N];

int n, m;
vector<pair<int, int>> g[N];
ll sum[N];

int val[N << 2], dfn[N], dfnr[N];

void change(int o, int l, int r, int k, int x) {
  val[o] = x;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid) change(o << 1, l, mid, k, x);
  else change(o << 1 | 1, mid + 1, r, k, x);
}

int query(int o, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return val[o];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(o << 1, l, mid, ql, qr);
  if (ql > mid) return query(o << 1 | 1, mid + 1, r, ql, qr);
  return max(query(o << 1, l, mid, ql, mid), query(o << 1 | 1, mid + 1, r, mid + 1, qr));
}

void dfs(int u) {
  static int t;
  dfn[u] = ++t;
  for (auto [v, w] : g[u]) {
    sum[v] = sum[u] + w;
    dfs(v);
  }
  dfnr[u] = t;
  if (g[u].empty())
    lct[u].access();
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int rep = 1; rep < n; ++rep) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    link(lct + u, lct + v);
  }
  lct[1].evert();
  dfs(1);
  vector<pair<ll, ll>> seq;
  for (int i = 1; i <= m; ++i) {
    int s, t;
    cin >> s >> t;
    Node *p = lct + s, *q;
    while ((q = p->splice())) {
      int u = q - lct;
      ll val = query(1, 1, n, dfn[u] + 1, dfnr[u]);
      if (val) val += sum[u];
      seq.emplace_back(val, t + sum[u]);
      //cerr << "insert (" << query(1, 1, n, dfn[u] + 1, dfnr[u]) + sum[u] << ", " << t + sum[u] << "] of " << i << '\n';
    }
    change(1, 1, n, dfn[s], t);
  }
  sort(seq.begin(), seq.end());
  priority_queue<ll, vector<ll>, greater<ll>> heap;
  vector<ll> solved;
  ll cur = 0;
  int p = 0, ans = 0;
  while (p < seq.size() || !heap.empty()) {
    while (p < seq.size() && seq[p].first == cur) {
      heap.push(seq[p].second);
      ++p;
    }
    if (heap.empty()) cur = seq[p].first;
    else {
      if (heap.top() == cur) {
        for (ll v : solved)
          if (v >= cur)
            --ans;
        break;
      }
      solved.push_back(heap.top());
      heap.pop();
      ++cur;
      ++ans;
    }
  }
  if (heap.empty() && p == seq.size())
    cur = -1;
  cout << cur << ' ' << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}