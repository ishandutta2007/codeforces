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

const int maxN = 1000000 + 233;
int n, k;
char s[maxN];
int z[maxN];
int d[maxN];

void algoZ() {
  int L = 0, R = 0;
  z[1] = n;
  for(int i = 2; i <= n; ++i) {
    int &len = z[i];
    len = R < i ? 0 : std::min(z[i - L + 1], R - i + 1);
    while(i + len <= n && s[1 + len] == s[i + len]) len++;
    if(chmax(R, i + len - 1)) L = i;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  // special case : k == 1
  algoZ();
//  displaya(z, 1, n);
  memset(d, 0, sizeof(d));
  for(int len = 1; len <= std::min(n / k + 2, n); ++len) {
    int extra;
		for(int i = 1; i <= k; ++i) if((i - 1) * len + 1 > n || z[(i - 1) * len + 1] < len) goto FAIL;
    extra = len * k + 1 > n ? 0 : std::min(z[len * k + 1], len);
    d[len * k]++; d[len * k + extra + 1]--;
//    printf("When len = %d, cover [%d, %d]\n", len, len * k, len * k + extra + 1);
    FAIL: {}
  }
  for(int i = 1; i <= n; ++i) d[i] += d[i - 1];
  for(int i = 1; i <= n; ++i) s[i] = (d[i] ? '1' : '0');
  printf("%s\n", s + 1);
  return 0;
}