#include <cstdio>
#include <cassert>
#include <cstring>
#include <map>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

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

vector< pair< int, int > > fact(int n) {
  int m = n;
  vector< pair< int, int > > ret;

  for (int i = 2; i * i <= n; ++i) {
    if (m % i != 0) continue;
    int cnt = 0;
    while (m % i == 0) m /= i, ++cnt;

    ret.push_back({i, cnt});
  }

  if (m != 1) ret.push_back({m, 1});

  return ret;
}

map< pair< int, int >, int >  id;
int id_alloc;

int get_id(int i, int p) {
  if (!id.count({i, p}))
    id[make_pair(i, p)] = id_alloc++;
  return id[make_pair(i, p)];
}

int a[101];

int main(void) 
{
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a + i);

  int s = n * 50;
  int t = n * 50 + 1;

  MaxFlow MF(n * 50 + 10, s, t);

  REP(i, n) {
    auto f = fact(a[i]);

    for (auto pp : f) {
      if (i % 2 == 0)
	MF.add_edge(s, get_id(i, pp.first), pp.second);
      else
	MF.add_edge(get_id(i, pp.first), t, pp.second);
    }
  }

  REP(i, m) {
    int x, y;
    scanf("%d%d", &x, &y); --x; --y;
    int g = __gcd(a[x], a[y]);
    auto f = fact(g);
    
    if (x % 2 == 1) swap(x, y);

    for (auto pp : f) 
      MF.add_edge(get_id(x, pp.first), get_id(y, pp.first), pp.second);
  }

  printf("%d\n", MF.maxflow());

  return 0;
}