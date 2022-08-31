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

const int N = 500010, K = 51;

//const int N = 100, K = 10;

int n, m, k, q;
int u[N], v[N], d[N], lst[N], lm[N], c[N], color[N];
int f[K * N * 2], rk[K * N * 2];

struct Node {
  int l, r;
  vector<int> modifies;
  Node *ls, *rs;

  void insert(int l, int r, int id) {
    if (this->l == l && this->r == r) {
      modifies.push_back(id);
      return;
    }
    if (r <= ls->r) return ls->insert(l, r, id);
    if (l >= rs->l) return rs->insert(l, r, id);
    ls->insert(l, ls->r, id);
    rs->insert(rs->l, r, id);
  }
};

vector<pair<int, int>> ops;
Node* segTree;

int find(int x) { return f[x] == x ? x : find(f[x]); }

Node* build(int l, int r) {
  static Node pool[N * 2], *top = pool;
  Node* p = top++;
  p->l = l;
  p->r = r;
  if (l == r) return p;
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

void merge(int x, int y) {
  if (rk[x] < rk[y]) swap(x, y);
  f[y] = x;
  ops.emplace_back(y, rk[x]);
  if (rk[x] == rk[y]) ++rk[x];
}

bool add(int t, int u, int v) {
  int x1 = find((t - 1) * n * 2 + u * 2 - 1), y1 = find((t - 1) * n * 2 + v * 2 - 1);
  if (x1 == y1)
    return false;
  int x2 = find((t - 1) * n * 2 + u * 2);
  if (y1 == x2)
    return true;
  int y2 = find((t - 1) * n * 2 + v * 2);
  merge(x1, y2);
  merge(x2, y1);
  return true;
}

void dc(Node* o) {
  int cnt = ops.size();
  //cerr << "[" << o->l << ' ' << o->r << "]: ";
  for (int id : o->modifies) {
    add(color[d[id]], u[d[id]], v[d[id]]);
    //cerr << color[d[id]] << "(" << u[d[id]] << ", " << v[d[id]] << ") ";
  }
  //cerr << '\n';
  if (o->l == o->r) {
    int id = o->l;
    if (add(c[id], u[d[id]], v[d[id]])) {
      puts("YES");
      color[d[id]] = c[id];
    } else
      puts("NO");
    if (color[d[id]] && id < lst[id]) {
      //cerr << "insert " << (id + 1) << ' ' << lst[id] << '\n';
      segTree->insert(id + 1, lst[id], id);
    }
  } else {
    dc(o->ls);
    dc(o->rs);
  }
  while (ops.size() > cnt) {
    rk[f[ops.back().first]] = ops.back().second;
    f[ops.back().first] = ops.back().first;
    ops.pop_back();
  }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &u[i], &v[i]);
  for (int i = 1; i <= q; ++i)
    scanf("%d%d", &d[i], &c[i]);
  iota(f + 1, f + k * n * 2 + 1, 1);
  segTree = build(1, q);
  fill(lm + 1, lm + m + 1, q + 1);
  for (int i = q; i; --i) {
    lst[i] = lm[d[i]] - 1;
    lm[d[i]] = i;
  }
  dc(segTree);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}