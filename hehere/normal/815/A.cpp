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

const int maxN = 100 + 5;
const int maxG = 500 + 5;
int n, m, x[maxN], y[maxN], G[maxN][maxN];

bool check() {
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
    if(G[i][j] != x[i] + y[j]) return false;
  for(int i = 1; i <= n; ++i) if(x[i] < 0) return false;
  for(int j = 1; j <= m; ++j) if(y[j] < 0) return false;
  return true;
}

int main() {
  n = readint(); m = readint();
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
    G[i][j] = readint();
  int maxi = maxG;
  int best = 0x3f3f3f3f, pos = -1;
  for(int i = 1; i <= n; ++i) chmin(maxi, G[i][1]);
  for(y[1] = 0; y[1] <= maxi; ++y[1]) {
    for(int i = 1; i <= n; ++i) x[i] = G[i][1] - y[1];
    for(int j = 2; j <= m; ++j) y[j] = G[1][j] - x[1];
    if(check()) {
      int sum = 0;
      for(int i = 1; i <= n; ++i) sum += x[i];
      for(int j = 1; j <= m; ++j) sum += y[j];
      if(chmin(best, sum)) pos = y[1];
    }
  }
  if(pos == -1) printf("-1\n");
  else {
  	y[1] = pos;
  	for(int i = 1; i <= n; ++i) x[i] = G[i][1] - y[1];
    for(int j = 2; j <= m; ++j) y[j] = G[1][j] - x[1];
  	printf("%d\n", best);
    for(int i = 1; i <= n; ++i) while(x[i]--) printf("row %d\n", i);
    for(int j = 1; j <= m; ++j) while(y[j]--) printf("col %d\n", j);
	}
  return 0;
}