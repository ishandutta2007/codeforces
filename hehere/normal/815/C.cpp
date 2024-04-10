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

const int maxN = 5000 + 5;
const int INF = 0x3f3f3f3f;
int n, b, c[maxN], d[maxN], p[maxN], sz[maxN];
int f[2][maxN][maxN];

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> b;
  cin >> c[1] >> d[1]; p[1] = 0;
  for(int i = 2; i <= n; ++i) cin >> c[i] >> d[i] >> p[i];
  memset(sz, 0, sizeof(sz));
  for(int u = n; u >= 1; --u) sz[p[u]] += ++sz[u];
  for(int u = 1; u <= n; ++u)
    for(int i = 0; i <= sz[u]; ++i) f[0][u][i] = f[1][u][i] = INF;
  for(int u = 1; u <= n; ++u)
    f[0][u][0] = 0, f[0][u][1] = c[u],
    f[1][u][0] = INF, f[1][u][1] = c[u] - d[u];
  for(int u = 1; u <= n; ++u) sz[u] = 1;
  for(int v = n; v > 1; --v) {
    int u = p[v];
    for(int x = sz[u]; x >= 0; --x) for(int y = 1; y <= sz[v]; ++y)
      chmin(f[0][u][x + y], f[0][u][x] + f[0][v][y]),
      chmin(f[1][u][x + y], f[1][u][x] + std::min(f[0][v][y], f[1][v][y]));
    sz[u] += sz[v];
  }
  int i = 0;
  for(; i <= n && std::min(f[0][1][i], f[1][1][i]) <= b; ++i);
  --i;
  printf("%d\n", i);
  return 0;
}