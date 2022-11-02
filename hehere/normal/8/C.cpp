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

const int maxN = 24 + 1;
const int INF = 0x3f3f3f3f;
int n;
int x[maxN], y[maxN];
int a[maxN][maxN];
int f[1 << maxN];
typedef pair<char, char> pcc;
pcc p[1 << maxN];

int main() {
  cin >> x[0] >> y[0] >> n;
  for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for(int i = 1; i <= n; ++i) x[i] -= x[0], y[i] -= y[0];
  x[0] = y[0] = 0;
  for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) {
    a[i][j] = 0;
		a[i][j] += (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		a[i][j] += x[i] * x[i] + y[i] * y[i];
		a[i][j] += x[j] * x[j] + y[j] * y[j];
  }
  f[0] = 0;
  for(int S = 2; S < (1 << (n + 1)); S += 2) {
    int &cur = f[S]; cur = INF;
    
    int i = __builtin_ctz(S);
    int T = S ^ (1 << i);
    if(chmin(cur, f[T] + a[i][0])) p[S] = pcc(i, 0);
    
    for(int j = i + 1; j <= n; ++j) if(T >> j & 1) {
      if(chmin(cur, f[T ^ (1 << j)] + a[i][j])) p[S] = pcc(i, j);
    }
  }
  int s = (1 << (n + 1)) - 1 - 1;
  printf("%d\n", f[s]);
  printf("0");
  while(s) {
//  	printf("s = %d\n", s); system("pause");
    int x = p[s].first, y = p[s].second;
    s ^= (1 << x);
    if(y) printf(" %d %d 0", x, y), s ^= (1 << y);
    else printf(" %d 0", x);
  }
  printf("\n");
  return 0;
}