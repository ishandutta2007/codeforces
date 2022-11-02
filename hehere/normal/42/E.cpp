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
typedef unsigned int U;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == (n) ? '}' : ',') << (qwq == (n) ? '\n' : ' '); }
#define displayv(a) displaya(a, 0, (int)(a.size()-1))
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
#define displayv(a) {}
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
const int maxM = 200000 + 233;
const int INF = 0x3f3f3f3f;
int n, m, q;
struct Edge {
  int x, y, w;
  Edge() {}
  Edge(int x, int y, int w) : x(x), y(y), w(w) {}
  friend bool operator < (const Edge &lhs, const Edge &rhs) {
    return lhs.w < rhs.w;
  }
}edges[maxM];
vector<pii> G[maxN];

int pa[maxN];
int findfa(int x) {
  return pa[x] ? pa[x] = findfa(pa[x]) : x;
}

int f[20][maxN], g[20][maxN], dep[maxN];
void DFS(int u, int fa) {
  for(pii p : G[u]) {
    int v = p.first, w = p.second;
    if(v == fa) continue;
    f[0][v] = u; g[0][v] = w;
    dep[v] = dep[u] + 1;
    DFS(v, u);
  }
}

int getmax(int x, int y) {
  if(dep[x] < dep[y]) std::swap(x, y);
  int dif = dep[x] - dep[y];
  int ans = 0;
  for(int i = 0; i < 20; ++i) if(dif >> i & 1)
    chmax(ans, g[i][x]), x = f[i][x];
  if(x == y) return ans;
  for(int i = 19; i >= 0; --i) if(f[i][x] != f[i][y])
    chmax(ans, g[i][x]), chmax(ans, g[i][y]),
    x = f[i][x], y = f[i][y];
  chmax(ans, g[0][x]); chmax(ans, g[0][y]);
  return ans;
}

int main() {
  n = readint(); m = readint();
  for(int i = 1; i <= m; ++i) {
    int x = readint(), y = readint(), w = readint();
    edges[i] = Edge(x, y, w);
  }
  std::sort(edges + 1, edges + m + 1);
  for(int u = 1; u <= n; ++u) pa[u] = 0;
  LL tot = 0;
  for(int i = 1; i <= m; ++i) {
    int x = edges[i].x, y = edges[i].y, w = edges[i].w;
    int fx = findfa(x), fy = findfa(y);
    if(fx != fy) {
      G[x].push_back(pii(y, w));
      G[y].push_back(pii(x, w));
      tot += w;
      pa[fx] = fy;
    }
  }

  int cnt = 0;

  for(int u = 1; u <= n; ++u) if(pa[u] == 0) {
    cnt++;
    f[0][u] = g[0][u] = dep[u] = 0;
    DFS(u, -1);
  }
  
//  display(cnt); display(tot);
//  displaya(pa, 1, n);

  if(cnt == 1)
    for(int k = 1; k < 20; ++k)
      for(int u = 1; u <= n; ++u)
        f[k][u] = f[k - 1][f[k - 1][u]],
        g[k][u] = std::max(g[k - 1][u], g[k - 1][f[k - 1][u]]);

//	displaya(f[0], 1, n);
//	displaya(g[0], 1, n);

  q = readint();
  for(int kase = 1; kase <= q; ++kase) {
    int x = readint(), y = readint();
    if(cnt > 2 || (cnt == 2 && findfa(x) == findfa(y))) printf("-1\n");
    else if(cnt == 2) printf("%lld\n", tot);
    else printf("%lld\n", tot - getmax(x, y));
  }

  return 0;
}