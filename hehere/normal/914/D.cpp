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

const int maxN = 500000 + 233;
int n, m, a[maxN];
int mygcd(int x, int y) {
  return !y ? x : mygcd(y, x % y);
}
int gcd(int x, int y) {
  return !x ? y : mygcd(x, y);
}

#define lson (o << 1)
#define rson (o << 1 | 1)

const int NODE = maxN * 4;
vector<int> val[NODE];
int sum[NODE];
vector<int> t;

void maintain(int o, int L, int R) {
	sum[o] = gcd(sum[lson], sum[rson]);
  t.clear();
  for(int x : val[lson]) t.push_back(gcd(x, sum[rson]));
  for(int y : val[rson]) t.push_back(gcd(y, sum[lson]));
  std::sort(t.begin(), t.end());
  t.resize(std::unique(t.begin(), t.end()) - t.begin());
  val[o].resize(t.size());
  for(int i = 0; i < (int)t.size(); ++i) val[o][i] = t[i];
  assert(val[o].size() < 40);
}

void build(int o, int L, int R) {
  if(L == R) {
    sum[o] = a[L];
    val[o] = {0};
  } else {
    int M = (L + R) >> 1;
    build(lson, L, M);
    build(rson, M + 1, R);
    val[o].reserve(std::min(32, R - L + 1));
    maintain(o, L, R);
  }
}

int pos;
void modify(int o, int L, int R) {
  if(L == R) {
    sum[o] = a[L];
  } else {
    int M = (L + R) >> 1;
    if(pos <= M) modify(lson, L, M);
    else modify(rson, M + 1, R);
    maintain(o, L, R);
  }
}

vector<int> res;
int ql, qr;
void query(int o, int L, int R) {
  if(ql <= L && R <= qr) {
//  	printf("[%d, %d] : sum = %d\n", L, R, sum[o]);
//  	displayv(val[o]);
		res.push_back(o);
	} else {
    int M = (L + R) >> 1;
    if(ql <= M) query(lson, L, M);
    if(qr > M) query(rson, M + 1, R);
  }
}

#undef lson
#undef rson

int main() {
  n = readint();
  for(int i = 1; i <= n; ++i) a[i] = readint();
  build(1, 1, n);
  m = readint();
  for(int kase = 1; kase <= m; ++kase) {
    int op = readint(), x = readint(), y = readint();
    if(op == 1) {
      int guess = readint();
      res.clear(); ql = x; qr = y;
      query(1, 1, n);
      vector<int> f(res.size(), 0), r(res.size(), 0);
      f.front() = sum[res.front()];
      for(int i = 1; i < (int)res.size(); ++i) f[i] = gcd(f[i - 1], sum[res[i]]);
      r.back() = sum[res.back()];
      for(int i = res.size() - 2; i >= 0; --i) r[i] = gcd(r[i + 1], sum[res[i]]);
//      displayv(f); displayv(r);
      for(int i = 0; i < (int)res.size(); ++i) {
        int sum = gcd(i == 0 ? 0 : f[i - 1], i == (int)res.size() - 1 ? 0 : r[i + 1]);
        for(int x : val[res[i]]) {
          if(gcd(x, sum) % guess == 0) { printf("YES\n"); goto END; }
        }
      }
      printf("NO\n");
      END: {}
    } else if(op == 2) {
      a[x] = y; pos = x;
      modify(1, 1, n);
    } else {
      assert(false);
    }
  }
  return 0;
}