#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

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

const int mod = 1000000007;
const int base = 1234567;
const int off = 1 << 17;

#define MAX 100005
#define MAXN 100005

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return (llint)a * b % mod; }

int H1[MAX];
int pw[MAX];
int pw2[MAX];

struct node {
  int zeros;
  int ones;
  int hash;
  int len;
  bool flip;

  node *l, *r;
  node() { ones = 0; hash = 0; zeros = len = off; l = r = NULL; }
  node(node *n) {
    zeros = n->zeros;
    ones = n->ones;
    hash = n->hash;
    len = n->len;
    flip = n->flip;
    l = n->l;
    r = n->r;
  }

  void do_flip() {
    swap(zeros, ones);
    hash = sub(H1[len], hash);
    flip ^= 1;
  }

  bool should_split() {
    return flip || l == NULL;
  }
};

void split(node *n) {
  if (n->l == NULL) {
    n->l = new node();
    n->r = new node();
    n->l->len = n->r->len = n->len / 2;
    n->flip = 0;

    if (n->zeros) {
      n->l->ones = n->r->ones = 0;
      n->l->zeros = n->r->zeros = n->len / 2;
      n->l->hash = n->r->hash = 0;
    } else {
      n->l->ones = n->r->ones = n->len / 2;
      n->l->zeros = n->r->zeros = 0;
      n->l->hash = n->r->hash = H1[n->len / 2];
    }
  } else {
    node *L = new node(n->l);
    node *R = new node(n->r);

    if (n->flip) {
      L->do_flip();
      R->do_flip();
      n->flip = 0;
    }

    n->l = L;
    n->r = R;
  }
}

node *_flip(int l, int r, int lo, int hi, node *n) {
  if (lo >= r || hi <= l) return n;
  if (lo >= l && hi <= r) {
    n->do_flip();
    return n;
  }

  split(n);
  n->l = _flip(l, r, lo, (lo + hi) / 2, n->l);
  n->r = _flip(l, r, (lo + hi) / 2, hi, n->r);
  n->hash = add(mul(n->l->hash, pw[n->len / 2]), n->r->hash);

  if (n->l->zeros == n->l->len)
    n->zeros = n->l->len + n->r->zeros;
  else
    n->zeros = n->l->zeros;
  
  if (n->l->ones == n->l->len)
    n->ones = n->l->len + n->r->ones;
  else
    n->ones = n->l->ones;

  return n;
}

node *flip(int l, int r, node *n) {
  node *ret = new node(n);
  return _flip(l, r + 1, 0, off, ret);
}

pair< int, int > _count_ones(int l, int r, int lo, int hi, node *n) {
  if (lo >= r || hi <= l) return {0, 0};
  if (lo >= l && hi <= r) return {n->ones, n->len};

  if (n->should_split()) split(n);

  auto L = _count_ones(l, r, lo, (lo + hi) / 2, n->l);
  auto R = _count_ones(l, r, (lo + hi) / 2, hi, n->r);

  if (L.first == L.second)
    return {L.first + R.first, L.second + R.second};

  return L;
}

int count_ones(int from, node *n) {
  return _count_ones(from, off, 0, off, n).first;
}

node *add_kth_power_of_2(int k, node *n) {
  int ones = count_ones(k, n);
  return flip(k, k + ones, n);
}

int cmp(node *n, node *m) {
  if (n->len == 1) {
    if (n->ones < m->ones) return -1;
    if (n->ones > m->ones) return +1;
    return 0;
  }

  if (n->hash == m->hash) return 0;

  if (n->should_split()) split(n);
  if (m->should_split()) split(m);

  int tcmp;
  if ((tcmp = cmp(n->r, m->r)) != 0) return tcmp;
  if ((tcmp = cmp(n->l, m->l)) != 0) return tcmp;

  assert(false);
}

int reduce(node *n) {
  if (n->len == 1) return n->ones;
  if (n->should_split()) split(n);
  return add(mul(pw2[n->r->len], reduce(n->r)), reduce(n->l));
}

void _output(node *n) {
  if (n->len == 1) {
    printf(n->ones ? "1" : "0");
    return;
  }
  if (n->should_split()) split(n);
  _output(n->l);
  _output(n->r);
}

void output(node *n) {
  _output(n);
  puts("");
}

node *D[MAXN];
int dad[MAXN];

struct cmpf {
  bool operator()(int a, int b) {
    int c = cmp(D[a], D[b]);
    if (c == 0) return a < b;
    return c < 0;
  }
};

int N, M;
int a, b, w;
int s, t;
vector< pair< int, int > > G[MAXN];

set< int, cmpf > pq;

int main(void)
{
  pw[0] = pw2[0] = 1;
  FOR(i, 1, MAXN) {
    H1[i] = add(mul(H1[i - 1], base), 1);
    pw[i] = mul(pw[i - 1], base);
    pw2[i] = mul(pw2[i - 1], 2);
  }

  node *inf = new node();
  inf = add_kth_power_of_2(off - 1, inf);

  REP(i, MAXN) D[i] = inf;

  scanf("%d%d", &N, &M);
  REP(i, M) {
    scanf("%d%d%d", &a, &b, &w);
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }

  scanf("%d%d", &s, &t);

  dad[s] = -1;
  D[s] = new node();
  pq.insert(s);

  while (!pq.empty()) {
    int n = *pq.begin();
    pq.erase(pq.begin());

    if (n == t) break;

    for (auto m : G[n]) {
      node *sum = add_kth_power_of_2(m.second, D[n]);
      if (cmp(D[m.first], sum) > 0) {
        pq.erase(m.first);
        D[m.first] = sum;
        dad[m.first] = n;
        pq.insert(m.first);
      }
    }
  }

  if (D[t] == inf) {
    puts("-1");
    exit(0);
  }

  printf("%d\n", reduce(D[t]));

  vector< int > sol;
  for (int i = t; i != -1; i = dad[i]) {
    sol.push_back(i);
  }

  reverse(sol.begin(), sol.end());
  printf("%d\n", sol.size());
  for (int n : sol) printf("%d ", n);
  puts("");

  return 0;
}