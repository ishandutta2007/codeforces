#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

template <class T>
class is_zero {
public:
    bool operator()(const T& x) const;
};

template <>
class is_zero<long long> {
public:
    bool operator()(const ll& x) const { return x == 0; }
};

template <class WeightT = int, class ZeroPredicator = is_zero<WeightT> >
class flow_graph {
public:
    typedef WeightT weight_type;
    typedef const weight_type& const_weight_reference;
    typedef weight_type* weight_array_type;

private:
    struct edge {
        int v;
        weight_type w;
        edge *next, *rev;
    };

    int v, e;
    edge *pool, *used;
    edge** adj;
    ZeroPredicator zero_predicator;

    edge* add_edge(int u, int v, const_weight_reference w) {
        edge* p = used;
        ++used;
        p->v = v;
        p->w = w;
        p->next = adj[u];
        adj[u] = p;
        return p;
    }

    bool bfs(int s, int t, int* level) {
        memset(level, -1, sizeof(int) * v);
        std::queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (edge* p = adj[u]; p; p = p->next)
                if (!zero_predicator(p->w) && level[p->v] == -1) {
                    level[p->v] = level[u] + 1;
                    if (p->v == t)
                        return true;
                    q.push(p->v);
                }
        }
        return false;
    }

    weight_type dfs(int u, int t, weight_type lim, edge** cadj, int* level) {
        if (u == t)
            return lim;
        weight_type flow = 0;
        for (edge*& p = cadj[u]; p; p = p->next)
            if (!zero_predicator(p->w) && level[u] < level[p->v]) {
                weight_type f = dfs(p->v, t, std::min(p->w, lim), cadj, level);
                flow += f;
                lim -= f;
                p->w -= f;
                p->rev->w += f;
                if (zero_predicator(lim))
                    return flow;
            }
        return flow;
    }

    weight_type dfs(int u, int t, edge** cadj, int* level) {
        weight_type flow = 0;
        for (edge*& p = cadj[u]; p; p = p->next)
            if (!zero_predicator(p->w) && level[u] < level[p->v]) {
                weight_type f = dfs(p->v, t, p->w, cadj, level);
                flow += f;
                p->w -= f;
                p->rev->w += f;
            }
        return flow;
    }

public:
    flow_graph() {}

    flow_graph(int v, int e, ZeroPredicator zero_predicator = is_zero<WeightT>())
        : v(v), e(e), zero_predicator(zero_predicator) {
        pool = new edge[e * 2];
        adj = new edge*[v];
        memset(pool, 0, sizeof(edge) * e * 2);
        memset(adj, 0, sizeof(edge*) * v);
        used = pool;
    }

    ~flow_graph() {
        delete[] pool;
        delete[] adj;
    }

    void link(int u, int v, const_weight_reference w) {
        edge *p = add_edge(u, v, w), *q = add_edge(v, u, 0);
        p->rev = q;
        q->rev = p;
    }

    /**
     * Calculate the maximum flow from `s` to `t`. Using the dinic algorithm.
     * time complexity: O(n^2e)
     **/
    weight_type max_flow(int s, int t) {
        int* level = new int[v];
        edge** cadj = new edge*[v];
        weight_type flow = 0;
        while (bfs(s, t, level)) {
            memcpy(cadj, adj, sizeof(edge*) * v);
            flow += dfs(s, t, cadj, level);
        }
        delete[] level;
        delete[] cadj;
        return flow;
    }
};

const int N = 110, S = 100010, K = 1010, INF = 1e9 + 10;
const ll LINF = 1LL << 53;

int n, m, s, b, k;

int dist[N][N];
int sx[S], a[S], f[S], p[S], bx[S], d[S], g[S];
vector<pair<int, int> > best[N];
pair<int, int> ed[K];
ll good[S];
int rel[S];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      dist[i][j] = i == j ? 0 : INF;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u != v)
      dist[u][v] = dist[v][u] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  scanf("%d%d%d", &s, &b, &k);
  for (int i = 1; i <= s; ++i)
    scanf("%d%d%d%d", &sx[i], &a[i], &f[i], &p[i]);
  for (int i = 1; i <= b; ++i) {
    scanf("%d%d%d", &bx[i], &d[i], &g[i]);
    best[bx[i]].emplace_back(d[i], g[i]);
  }
  for (int i = 1; i <= n; ++i) {
    sort(best[i].begin(), best[i].end());
    for (int j = 1; j < best[i].size(); ++j)
      best[i][j].second = max(best[i][j - 1].second, best[i][j].second);
  }
  memset(good, -1, sizeof(good));
  for (int i = 1; i <= s; ++i)
    for (int j = 1; j <= n; ++j)
      if (f[i] >= dist[sx[i]][j]) {
        auto it = lower_bound(best[j].begin(), best[j].end(), make_pair(a[i] + 1, 0));
        if (it != best[j].begin())
          good[i] = max(good[i], ll((it - 1)->second));
      }
  int cnt = 0;
  int S = ++cnt, T = ++cnt;
  for (int i = 1; i <= k; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed[i] = make_pair(u, v);
    if (!rel[u])
      rel[u] = ++cnt;
    if (!rel[v])
      rel[v] = ++cnt;
  }
  flow_graph<long long> g(cnt + 1, k + (cnt - 2));
  ll ans = 0;
  for (int i = 1; i <= k; ++i) {
    int u, v;
    tie(u, v) = ed[i];
    g.link(rel[u], rel[v], LINF);
  }
  for (int i = 1; i <= s; ++i) {
    if (good[i] == -1) good[i] = -LINF;
    else good[i] -= p[i];
    if (rel[i]) {
      if (good[i] >= 0) {
        ans += good[i];
        g.link(S, rel[i], good[i]);
      } else {
        g.link(rel[i], T, -good[i]);
      }
    } else {
      ans += max(0LL, good[i]);
    }
  }
  ans -= g.max_flow(S, T);
  printf("%lld\n", ans);
  return 0;
}