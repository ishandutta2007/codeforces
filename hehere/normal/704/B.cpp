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
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n, s, t;
int x[maxN], a[maxN], b[maxN], c[maxN], d[maxN];
LL f[maxN * 2], g[maxN * 2];

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> s >> t;
  
  for(int i = 1; i <= n; ++i) cin >> x[i];
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) cin >> c[i];
  for(int i = 1; i <= n; ++i) cin >> d[i];
  for(int i = 1; i <= n; ++i) {
    b[i] -= x[i]; c[i] += x[i];
    d[i] -= x[i]; a[i] += x[i];
  }
  memset(g, 0x3f3f3f3f, sizeof(g)); memset(f, 0x3f3f3f3f, sizeof(f));
  int out = 0, in = 0;
  f[0] = 0;
  
	for(int i = 1; i <= n; ++i) {
    int a = ::a[i], b = ::b[i], c = ::c[i], d = ::d[i];
		
//		memcpy(g, f, sizeof(f)); memset(f, 0x3f3f3f3f, sizeof(f));
    for(int j = (i == 1 ? 0 : (std::min(in, out) + 1)); j <= in + out; ++j) g[j] = f[j], f[j] = INF;
    
    if(i == s) for(int j = (i == 1 ? 0 : (std::min(in, out) + 1)); j <= in + out; ++j) {
      if(j >= out + 1) chmin(f[j], g[j] + c); // lout
      chmin(f[j + 1], g[j] + d); // rout
    } else if(i == t) for(int j = (i == 1 ? 0 : (std::min(in, out) + 1)); j <= in + out; ++j) {
      if(j >= in + 1) chmin(f[j], g[j] + a); // lin
      chmin(f[j + 1], g[j] + b); // rin
    } else for(int j = (i == 1 ? 0 : (std::min(in, out) + 1)); j <= in + out; ++j) {
      if(j >= in + 1 && j >= out + 1) chmin(f[j], g[j] + a + c); // lin, lout
      if(j >= in + 1) chmin(f[j + 1], g[j] + a + d); // lin, rout
      if(j >= out + 1) chmin(f[j + 1], g[j] + b + c); // rin, lout
      chmin(f[j + 2], g[j] + b + d); // rin, rout
    }
    out += (i != t); in += (i != s);
//    displaya(f, 0, n * 2);
  }
  assert(in == out);
  printf("%lld\n", f[in]);
  return 0;
}