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
int n, f[maxN][maxN];
char s[maxN];
int cnt[maxN];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(f, 0, sizeof(f));
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i) {
    for(int j = i, k = i; 1 <= j && k <= n && s[j] == s[k]; --j, ++k)
      f[j][k] = 1;
    for(int j = i, k = i + 1; 1 <= j && k <= n && s[j] == s[k]; --j, ++k)
      f[j][k] = 1;
  }
  for(int len = 1; len <= n; ++len) {
    for(int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
      int x = i + len / 2 - 1, y = j - len / 2 + 1;
//    	printf("[%d, %d] with [%d, %d], %d -> %d\n", i, x, y, j, f[i][j], i < j && f[i][j] ? std::min(f[i][x], f[y][j]) + 1 : f[i][j]);
      if(i < j && f[i][j]) f[i][j] = std::min(f[i][x], f[y][j]) + 1;
      cnt[f[i][j]]++;
    }
  }
  for(int i = n - 1; i >= 1; --i) cnt[i] += cnt[i + 1];
  for(int i = 1; i <= n; ++i) printf("%d%c", cnt[i], " \n"[i == n]);
  return 0;
}