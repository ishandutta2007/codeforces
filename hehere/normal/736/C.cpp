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

const int maxN = 100 + 5;
const int maxK = 20 + 5;
const LL P = 1000000007;
int n, k;
vector<int> G[maxN];
struct Array {
  LL _buc[maxK];
  Array() { memset(_buc, 0, sizeof(_buc)); }
  LL& operator [](const int &id) {
    return _buc[id + 1];
  }
};
Array f[maxN][maxK], *g, h[maxK];

void inc(LL &x, LL y) {
  x = (x + y) % P;
}

void DFS(int u, int fa) {
  f[u][k + 1][0] = 1;
  f[u][0][-1] = 1;
  for(int v : G[u]) if(v != fa) {
    DFS(v, u);
    g = f[v];
    for(int i = 0; i <= k + 1; ++i) h[i] = f[u][i];
    for(int i = 0; i <= k + 1; ++i) f[u][i] = Array();
    for(int x = 0; x <= k + 1; ++x)
      for(int y = -1; y <= k; ++y) if(h[x][y])
			  for(int i = 0; i <= k + 1; ++i)
			    for(int j = -1; j < k; ++j) if(g[i][j]) {
			    	int dim1 = std::min(x, i + 1);
			    	int dim2 = std::max((y == -1 || i + 1 + y <= k) ? -1 : y, (j == -1 || x + 1 + j <= k) ? -1 : j + 1);
            inc(f[u][dim1][dim2],
              g[i][j] * h[x][y]);
//            printf("%d %d %d %d -> %d %d\n", x, y, i, j, dim1, dim2);
          }
  }
//  printf("Subtree %d done\n", u);
//  for(int i = 0; i <= k + 1; ++i)
//  	for(int j = -1; j <= k; ++j) if(f[u][i][j]) {
//  		printf("f(%d, %d, %d) = %lld\n", u, i, j, f[u][i][j]);
//		}
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y); G[y].push_back(x);
  }
  DFS(1, -1);
  LL ans = 0;
  for(int i = 0; i <= k + 1; ++i) inc(ans, f[1][i][-1]);
  cout << ans << endl;
  return 0;
}