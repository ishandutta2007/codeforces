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
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using std::pair; using std::make_pair;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef LOCAL
#include <ctime>
void displayTime() { cout << "Current time = " << clock() * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
#else
void displayTime() {}
#endif
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == n ? '}' : ',') << (qwq == n ? '\n' : ' '); }
#include <ctime>
class MyTimer {
  clock_t st;
public:
  MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
  ~MyTimer() { report(); }
  void reset() { st = clock_t(); }
  void report() {  cerr << "Time consumed :" << (clock() - st) * 1e3 / CLOCKS_PER_SEC << endl; }
} myTimer;
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
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

const int maxN = 300000 + 233;
int n, a[maxN], s[maxN];
int even[maxN], odd[maxN];
//int post[maxN];
int upd[maxN];

LL ans = 0;

int main() {
  n = readint();
  for(int i = 1; i <= n; ++i) a[i] = __builtin_popcountll(readLL());
  memset(s, 0, sizeof(s)); even[0] = odd[0] = 0;
  for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i], even[i] = even[i - 1] + (s[i] % 2 == 0), odd[i] = odd[i - 1] + (s[i] % 2 == 1);
//  for(int i = n; i >= 1; --i) post[i] = a[i + 1] ? i + 1 : post[i + 1];
  static int stk[maxN]; int len = 0;
  stk[++len] = n + 1; a[n + 1] = 200;
  for(int i = n; i >= 1; --i) {
    while(a[stk[len]] <= a[i]) --len;
    upd[i] = stk[len]; stk[++len] = i;
  }
  LL ans = 0;
  for(int i = 1; i <= n; ++i) {
    int t = i;
    while(t <= n) {
      int tarsum = s[i - 1] + 2 * (a[t]);
      int pos = std::lower_bound(s + 1, s + n + 1, tarsum) - s;
      chmax(pos, t);
//      printf("i = %d, t = %d : pos = %d\n", i, t, pos);
      if(pos >= upd[t]) {
      	t = upd[t];
//				printf("skipped\n");
				continue;
			}
      int dans = 0;
      if(s[i - 1] & 1) dans = odd[upd[t] - 1] - odd[pos - 1];
      else dans = even[upd[t] - 1] - even[pos - 1];
//      printf("   with dans = %d\n", dans);
			ans += dans;
      t = upd[t];
    }
  }
  cout << ans << endl;
  return 0;
}