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

const int maxN = 1000000 + 233;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
char _b[maxN], _n[maxN], *B = _b, *N = _n;
int lb, ln;
void dec(char *s, int &len) {
  int i = len - 1;
  for(; s[i] == 0; s[i--] = 9);
  s[i]--;
}
LL b, n;
LL m;
LL qpow(LL a, LL b, LL m) {
  LL r = 1;
  while(b) {
    if(b & 1) (r *= a) %= m;
    b >>= 1;
    (a *= a) %= m;
  }
  return r;
}

void merge(LL &a, LL &n, LL b, LL m) {
  if(n < m) std::swap(a, b), std::swap(n, m);
  while(a % m != b) a += n;
  n *= m;
}

LL getmod(LL x) {
  LL r = 0;
  for(int i = 0; i < ln; ++i) r = (r * 10 + N[i]) % x;
  return r;
}

LL factor(LL tot) {
  LL r = 0, m = 1;
  auto calc = [&](LL x) -> void {
    LL n = 1;
    while(tot % x == 0) tot /= x, n *= x;
    LL phi = n / x * (x - 1);
//    printf("n = %lld, phi = %lld\n", n, phi);
    if(b % x != 0) merge(r, m, qpow(b, getmod(phi), n), n);
    else merge(r, m, 0, n);
  };
  for(LL i = 2; i * i <= tot; ++i) if(tot % i == 0) calc(i);
  if(tot > 1) calc(tot);
  return r;
}

LL solve() {
  if(ln >= 15) return factor(m);
  else {
    for(int i = 0; i < ln; ++i) {
      if(i == 0) n = 0;
      n = (n * 10 + N[i]);
    }
    return qpow(b, n, m);
  }
}

// 2323 192837981729847423 233333333

int main() {
  scanf("%s %s %lld", B, N, &m);
  lb = strlen(B), ln = strlen(N);
  for(int i = 0; i < lb; ++i) B[i] -= '0';
  for(int i = 0; i < ln; ++i) N[i] -= '0';
  dec(N, ln);
  b = 0;
  for(int i = 0; i < lb; ++i) b = (b * 10 + B[i]) % m;
  LL ans = solve();
  if(b-- == 0) b = m - 1;
  ans = ans * b % m;
  printf("%lld\n", ans ? ans : m);
  return 0;
}