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

struct E { int v; ll w1, w2; E* next; };

ll add(ll x, ll y) { return x != -1 && y != -1 ? (x + y) : -1; }

ll cmp(ll x, ll y) { return x != -1 && (x < y || y == -1); }

struct Mat {
  ll g[2][2];

  Mat() { memset(g, -1, sizeof(g)); }

  Mat(initializer_list<ll> list) {
    const ll* ptr = list.begin();
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        g[i][j] = *ptr++;
  }

  const ll* operator[](int k) const { return g[k]; }

  ll* operator[](int k) { return g[k]; }

  Mat operator*(const Mat& rhs) const {
    Mat ret = Mat();
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          ret[i][j] = min(ret[i][j], add(g[i][k], rhs[k][j]), cmp);
    return ret;
  }
};

const int N = 300010, Q = 600010;

int n;
ll wn[N], ans[Q];
int f[N], qu[Q][2];
Mat val[N];
vector<pair<int, bool>> qry[N];
vector<int> q2[N];
bool vis[N], opt[Q][2];
E* g[N];

void adde(int u, int v, ll w1, ll w2) { static E pool[N * 2], *p = pool; p->v = v; p->w1 = w1; p->w2 = w2; p->next = g[u]; g[u] = p++; }

void dfs1(int u);
void dfs2(int u);

Mat tran(const Mat& m) { return { m[0][0], m[1][0], m[0][1], m[1][1] }; }

int find(int x) {
  if (f[x] == x)
    return x;
  int prt = f[x];
  f[x] = find(f[x]);
  val[x] = val[x] * val[prt];
  return f[x];
}

void dfs3(int u);

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &wn[i]);
  for (int rep = 1; rep < n; ++rep) {
    int u, v; ll w1, w2;
    scanf("%d%d%lld%lld", &u, &v, &w1, &w2);
    adde(u, v, w1, w2); adde(v, u, w1, w2);
  }
  dfs1(1);
  memset(vis, 0, sizeof(vis));
  dfs2(1);
  int q; scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    int u = (x + 1) >> 1, v = (y + 1) >> 1;
    bool a = !(x & 1), b = !(y & 1);
    qu[i][0] = u; qu[i][1] = v;
    opt[i][0] = a; opt[i][1] = b;
    qry[u].emplace_back(i, 0);
    qry[v].emplace_back(i, 1);
  }
  fill(val + 1, val + n + 1, Mat{0, -1, -1, 0});
  dfs3(1);
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}

void dfs1(int u) {
  vis[u] = true;
  for (E* p = g[u]; p; p = p->next)
    if (!vis[p->v])
      dfs1(p->v), wn[u] = min(wn[u], wn[p->v] + p->w1 + p->w2);
}

void dfs2(int u) {
  vis[u] = true;
  for (E* p = g[u]; p; p = p->next)
    if (!vis[p->v])
      wn[p->v] = min(wn[p->v], wn[u] + p->w1 + p->w2), dfs2(p->v);
}

void dfs3(int u) {
  f[u] = u;
  for (E* p = g[u]; p; p = p->next)
    if (!f[p->v]) {
      dfs3(p->v);
      f[p->v] = u;
      val[p->v] = Mat({0, wn[p->v], wn[p->v], 0}) * Mat({p->w1, -1, -1, p->w2});
    }
  for (const auto& q : qry[u])
    if (f[qu[q.first][!q.second]]) {
      int lca = find(qu[q.first][!q.second]);
      q2[lca].push_back(q.first);
    }
  Mat cur{0, wn[u], wn[u], 0};
  for (int id : q2[u]) {
    Mat res1 = (find(qu[id][0]), val[qu[id][0]]), res2 = (find(qu[id][1]), val[qu[id][1]]);
    ans[id] = (res1 * cur * tran(res2))[opt[id][0]][opt[id][1]];
    //LOG("GOOD %d(%d, %d)->(%d, %d) %lld\n", id, qu[id][0], opt[id][0], qu[id][1], opt[id][1], ans[id]);
  }
}