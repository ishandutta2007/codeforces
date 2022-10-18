#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

const int inf = 1000000000;

struct MaxFlow {
  static const int MAX = 100005;

  int n, s, t;

  struct Edge {
    int to, cap, rev;
    Edge() {}
    Edge(int to, int cap) :
      to(to), cap(cap) {}
  };

  int bio[MAX];
  int cookie;
  int p[MAX];

  vector< Edge > G[MAX];

  MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
    memset(bio, 0, sizeof bio);
    cookie = 1;
  }

  void add_edge(int a, int b, int cap) {
    G[a].push_back(Edge(b, cap));
    G[b].push_back(Edge(a, 0));
    G[a].back().rev = G[b].size() - 1;
    G[b].back().rev = G[a].size() - 1;
  }

  int augment(int now, int flow) {
    if (now == t) return flow;
    if (bio[now] == cookie) return 0;
    bio[now] = cookie;

    int sent = 0;
    for (auto &e : G[now]) {
      if (e.cap == 0) continue;

      int send = augment(e.to, min(e.cap, flow));

      flow -= send;
      sent += send;
      e.cap -= send;
      G[e.to][e.rev].cap += send;
    }

    return sent;
  }

  int maxflow() {
    int ret = 0;
    int f;
    ++cookie;
    while ((f = augment(s, inf))) {
      ret += f;
      ++cookie;
    }
    return ret;
  }
};

const int MAXN = 55;
const int MAXM = 105;

int n, m;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int l[MAXM];
int r[MAXM];

const int s = 0;
const int t = 1;
int id_alloc = 1;

map< pair< int, int >, int > id;

int get_id(int i, int x) {
  if (id.count({i, x}))
    return id[make_pair(i, x)];
  id[make_pair(i, x)] = ++id_alloc;
  return id_alloc;
}

int f(int i, int x) {
  return a[i] * x * x + b[i] * x + c[i];
}

int main(void)
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d%d%d", a + i, b + i, c + i);
  REP(i, n) scanf("%d%d", l + i, r + i);

  MaxFlow MF(n * 202, s, t);

  int ZERO = 0;
  REP(i, n) 
    for (int x = l[i]; x <= r[i]; ++x)
      ZERO = min(ZERO, -f(i, x));
  ZERO = -ZERO;

  REP(i, n) {
    MF.add_edge(s, get_id(i, l[i] - 1), inf);
    MF.add_edge(get_id(i, r[i]), t, inf);
    for (int x = l[i]; x <= r[i]; ++x) 
      MF.add_edge(get_id(i, x - 1), get_id(i, x), ZERO - f(i, x));
  }

  REP(i, m) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d); --u; --v;
    for (int x = l[u] - 1; x <= r[u]; ++x)
      MF.add_edge(get_id(u, x), get_id(v, x - d), inf);
  }

  printf("%d\n", n * ZERO - MF.maxflow());

  return 0;
}