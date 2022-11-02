#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using std::pair; using std::make_pair;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == n ? '}' : ',') << (qwq == n ? '\n' : ' '); }
#include <ctime>
class MyTimer {
  clock_t st;
public:
  MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
  ~MyTimer() { report(); }
  void reset() { st = clock_t(); }
  void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}
inline LL readLL() {
  LL a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 100000 + 233;
const int maxM = 100000 + 233;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, q;
struct Edge {
  int from, to, dist, last;
  Edge() {}
  Edge(int f, int t, int d, int l) : from(f), to(t), dist(d), last(l) {}
}edges[maxM];
vector<pii> G[maxN]; // tree edges
vector<pii> H[maxN]; // complete graph
LL d[maxN];
int f[20][maxN], dep[maxN];
map<int, int> M;

int pa[maxN];
int findfa(int x) {
  return pa[x] ? pa[x] = findfa(pa[x]) : x;
}

void DFS(int u, int fa) {
//	printf("%d with fa = %d\n", u, fa);
  for(const pii &p : G[u]) {
    int v = p.first;
    if(v == fa) continue;
    else f[0][v] = u, d[v] = d[u] + p.second, dep[v] = dep[u] + 1;
    DFS(v, u);
  }
}

int LCA(int x, int y) {
  if(dep[x] < dep[y]) std::swap(x, y);
  int dif = dep[x] - dep[y];
  for(int i = 0; i < 20; ++i) if(dif >> i & 1) x = f[i][x];
  if(x == y) return x;
  for(int i = 19; i >= 0; --i) if(f[i][x] != f[i][y])
    x = f[i][x], y = f[i][y];
  return f[0][x];
}

bool vis[maxN];
LL aux[50][maxN];
void Dijkstra(int s, LL d[]) {
//	printf("Dijkstra from %d\n", s);
  for(int u = 0; u <= n; ++u) vis[u] = false, d[u] = INF;
  using ppp = pair<LL, int>;
  priority_queue<ppp> pq;
  d[s] = 0; pq.push(ppp(0, s));
  while(!pq.empty()) {
    int u = pq.top().second; pq.pop();
    if(vis[u]) continue; else vis[u] = true;
    for(const pii &p : H[u]) {
      int v = p.first;
      if(chmin(d[v], d[u] + p.second)) {
        pq.push(ppp(-d[v], v));
      }
    }
  }
//  displaya(d, 1, n);
}

int main() {
  n = readint(); m = readint();
  for(int i = 1; i <= m; ++i) {
    int x = readint(), y = readint(), d = readint();
    edges[i] = Edge(x, y, d, 0);
  }
  std::sort(edges + 1, edges + m + 1, [](Edge x, Edge y) -> bool { return x.dist < y.dist; });
  memset(pa, 0, sizeof(pa));
  for(int u = 0; u <= n; ++u) G[u].clear(), H[u].clear();
  M.clear();
	for(int i = 1; i <= m; ++i) {
    int x = edges[i].from, y = edges[i].to;
    int fx = findfa(x), fy = findfa(y);
    H[x].push_back(pii(y, edges[i].dist));
    H[y].push_back(pii(x, edges[i].dist));
    if(fx == fy) {
      int s = M.size();
      if(!M.count(x)) M[x] = s++;
      if(!M.count(y)) M[y] = s++;
      continue;
    } else pa[fx] = fy;
    G[x].push_back(pii(y, edges[i].dist));
    G[y].push_back(pii(x, edges[i].dist));
//    printf("Tree edge : (%d, %d, %d)\n", x, y, edges[i].dist);
  }
  f[0][1] = 0; d[1] = 0; dep[1] = 1;
  DFS(1, -1);
  for(int k = 1; k < 20; ++k) for(int u = 1; u <= n; ++u)
    f[k][u] = f[k - 1][f[k - 1][u]];
  for(auto p : M) Dijkstra(p.first, aux[p.second]);
  q = readint();
  while(q--) {
    int x = readint(), y = readint();
    LL ans = INF;
    int lca = LCA(x, y);
    chmin(ans, d[x] + d[y] - 2 * d[lca]);
    for(auto p : M) chmin(ans, aux[p.second][x] + aux[p.second][y]);
    printf("%lld\n", ans);
  }
  return 0;
}