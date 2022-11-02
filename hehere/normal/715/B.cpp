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

const int maxN = 1000 + 233;
const int maxM = 10000 + 233;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, s, t;
LL len;
struct Edge {
  int from, to, dist, last;
  Edge() {}
  Edge(int f, int t, int d, int l) : from(f), to(t), dist(d), last(l) {}
}edges[maxM << 1];
bool matter[maxM];
int h[maxN];

LL d[maxN]; int p[maxN];
bool vis[maxN];
priority_queue<pll> pq;
void Dijkstra(int s) {
  memset(d, 0x3f, sizeof(d));
  memset(p, 0, sizeof(p));
  memset(vis, 0, sizeof(vis));
  d[s] = 0; pq.push(pll(0, s));
  while(!pq.empty()) {
  	int u = pq.top().second;
  	if(pq.top().first != -d[u]) { pq.pop(); continue; }
  	else pq.pop();
  	for(int i = h[u]; i; i = edges[i].last) {
  		const Edge &e = edges[i];
  		if(chmin(d[e.to], d[u] + e.dist)) {
  			p[e.to] = i; pq.push(pll(-d[e.to], e.to));
			}
		}
	}
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> len >> s >> t;
  memset(h, 0, sizeof(h));
  memset(matter, 0, sizeof(matter));
  for(int i = 1; i <= m; ++i) {
  	int x, y, w;
  	cin >> x >> y >> w;
    edges[i << 1] = Edge(x, y, w, h[x]); h[x] = i << 1;
    edges[i << 1 | 1] = Edge(y, x, w, h[y]); h[y] = i << 1 | 1;
    if(w == 0) matter[i] = true;
  }
  for(int i = 1; i <= m; ++i) if(matter[i])
    edges[i << 1].dist = edges[i << 1 | 1].dist = len + 1;
  Dijkstra(s);
//  displaya(d, 0, n - 1);
  if(d[t] < len) { printf("NO\n"); return 0; }
  for(int i = 1; i <= m; ++i) if(matter[i])
    edges[i << 1].dist = edges[i << 1 | 1].dist = 1;
  Dijkstra(s);
//  displaya(d, 0, n - 1);
  if(d[t] > len) { printf("NO\n"); return 0; }
  do {
	  int u = t;
	  while(u != s) {
	    int i = p[u];
	//    printf("%d %d\n", edges[i].from, edges[i].to);
	    if(matter[i / 2])
				{ edges[i].dist += len - d[t]; edges[i^1].dist += len - d[t]; matter[i / 2] = false; break; }
			u = edges[i].from;
	  }
	  Dijkstra(s);
	  displaya(d, 0, n - 1);
	} while(d[t] < len);

//  for(int i = 1; i <= m; ++i) if(matter[i])
//    edges[i << 1].dist = edges[i << 1 | 1].dist = len + 1;
  printf("YES\n");
  
	for(int i = 1; i <= m; ++i) {
    assert(edges[i << 1].dist == edges[i << 1 | 1].dist);
    printf("%d %d %d\n", edges[i << 1].from, edges[i << 1].to, edges[i << 1].dist);
  }
  return 0;
}