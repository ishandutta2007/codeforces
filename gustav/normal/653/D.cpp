#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>

#include <algorithm>
#include <functional>

#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
typedef pair< int, int > pii;

#define mp make_pair
#define pb push_back
#define ms(x,v) memset(x, v, sizeof(x))

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int inf = 1000000000;

struct MaxFlow {
  static const int MAX = 55;

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

const int MAXM = 505;
const int IT = 100;

int n, m, x;
int a[MAXM];
int b[MAXM];
int c[MAXM];

int main(void)
{
  scanf("%d%d%d", &n, &m, &x);

  REP(i, m) 
    scanf("%d%d%d", a + i, b + i, c + i);

  int up = 0;
  REP(i, m) up = max(up, c[i]);

  double lo = 0.0, hi = up;
  REP(it, IT) {
    double mid = 0.5 * (lo + hi);

    auto flow = MaxFlow(n, 1, n);

    REP(i, m) 
      flow.add_edge(a[i], b[i], min((double)x, floor(c[i] / mid)));

    if (flow.maxflow() >= x)
      lo = mid;
    else
      hi = mid;
  }

  printf("%.10lf\n", lo * x);
  
  return 0;
}