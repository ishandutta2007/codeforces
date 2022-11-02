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
#include <sstream>
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
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) if(qwq == (st)) cerr << a[qwq]; else cerr << ", " << a[qwq];\
      cerr << "}" << endl; }
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

const int maxN = 180 + 5;
const int INF = 0x3f3f3f3f;
int n, w[maxN];
int p[maxN][maxN], d[maxN][maxN];
vector<int> G[maxN];

void init(int u, int root, int fa) {
  for(int v : G[u]) if(v != fa) {
    p[v][root] = u;
    d[v][root] = d[u][root] + 1;
    init(v, root, u);
  }
}

int f[maxN][maxN], g[maxN];
void DFS(int u, int fa) {
  memset(f[u], INF, sizeof(f[u]));
  for(int v : G[u]) if(v != fa) DFS(v, u);
  g[u] = INF;
  for(int t = 1; t <= n; ++t) {
    f[u][t] = w[d[u][t]];
    if(p[u][t] != fa) {
			f[u][t] = w[d[u][t]];
	    for(int v : G[u]) if(v != fa)
	    	if(v == p[u][t]) f[u][t] += f[v][t];
	      else f[u][t] += std::min(f[v][t], g[v]);
	    else {}
	    chmin(g[u], f[u][t]);
		} else {
			for(int v : G[u]) if(v != fa)
				f[u][t] += std::min(f[v][t], g[v]);
		}
  }
//  printf("g[%d] = %d\n", u, g[u]);
}

int master[maxN];
void printG(int u, int fa);
void printF(int u, int t, int fa) {
	master[u] = t;
  if(p[u][t] != fa) {
    for(int v : G[u]) if(v != fa)
    	if(v == p[u][t]) printF(v, t, u);
      else f[v][t] < g[v] ? printF(v, t, u) : printG(v, u);
    else {}
	} else {
		for(int v : G[u]) if(v != fa)
			f[v][t] < g[v] ? printF(v, t, u) : printG(v, u);
	}
}
void printG(int u, int fa) {
	for(int t = 1; t <= n; ++t) if(p[u][t] != fa)
		if(g[u] == f[u][t]) {
			printF(u, t, fa);
			return;
		}
}

/*
4 12
10 20 30
1 2 2 3 3 4

6 10
4 8 10 11 12
3 6
2 6
3 5
2 4
1 6
*/

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> w[i];
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y); G[y].push_back(x);
  }
  for(int root = 1; root <= n; ++root) {
    p[root][root] = root;
    d[root][root] = 0;
    init(root, root, -1);
  }
  DFS(1, -1);
  printf("%d\n", g[1]);
  printG(1, -1);
  for(int u = 1; u <= n; ++u) printf("%d%c", master[u], " \n"[u == n]);
  return 0;
}