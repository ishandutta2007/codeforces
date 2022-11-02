#include <cassert>
#include <cctype>
#include <cmath>
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
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[i] << (qwq == n ? ' ' : '\n'); }
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
};
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

const int maxT = 500 + 5;
const int maxN = 60;
int n;
struct Factor {
  LL p; int cnt;
  vector<LL> val;
  Factor(LL p = 1, int cnt = 0) : p(p), cnt(cnt) {
    val.clear(); val.resize(cnt + 1);
    val[0] = 1;
    for(int i = 1; i <= cnt; ++i) val[i] = val[i - 1] * p;
  }
  LL& operator [](const int &idx) {
  	return val[idx];
  }
  friend bool operator < (const Factor &A, const Factor &B) {
    return A.cnt != B.cnt ? A.cnt < B.cnt : A.p > B.p;
  }
};
vector<Factor> f;
LL A, B, C, P, R1, R2;
LL ans, ansA, ansB, ansC;
LL cube_root;
LL qpow(LL a, int b) {
  LL r = 1;
  while(b) {
    if(b & 1) r *= a;
    a *= a; b >>= 1;
  }
  return r;
}

LL DFS_inner(int d) {
  if(d == n) {
    if(chmin(ans, A * B + B * C + A * C))
      ansA = A, ansB = B, ansC = C
//      , cout << ans << " achieved by " << A << " " << B << " " << C << endl
	  ;
    return A * B + B * A + A * C;
  } else {
    LL ret = 0;
    Factor &ft = f[d];
    auto go = [&](int i) {
      LL _B = B, _C = C;
      B *= ft[i];
      C *= ft[ft.cnt - i];
      chmin(ret, DFS_inner(d + 1));
      B = _B; C = _C;
    };
    int upper = 0, lower = ft.cnt;
    while(upper < ft.cnt && B * ft[upper] * B * ft[upper] <= R1) ++upper;
    if(B * ft[upper] * B * ft[upper] > R1) --upper;
    R2 /= ft[ft.cnt];
    while(lower > 0 && B * ft[lower] * R2 >= A) --lower;
    if(B * ft[lower] * R2 < A) ++lower;
//    if(A == 4) {
//    	  for(auto ft : f) {
//  	printf("(%lld ^ %d) ", ft.p, ft.cnt);
//  } printf("\n");
//  		printf("now A = %lld, B = %lld, C = %lld\n", A, B, C);
//  		printf("p = %lld, cnt = %d, lower = %d, upper = %d\n", ft.p, ft.cnt, lower, upper);
//	}
    for(int i = upper; i >= lower; --i) go(i);
    R2 *= ft[ft.cnt];
    return ret;
  }
}

LL DFS(int d) {
  if(d == n) {
    R2 = 1;
    for(auto &ft : f) R2 *= ft[ft.cnt];
    R1 = R2;
    if(A * 2 * sqrt(R2 + 0.5) + R2 >= ans) return 0x3f3f3f3f3f3f3f3fLL;
    return DFS_inner(0);
  } else {
    LL ret = 0;
    Factor &ft = f[d];
    auto go = [&](int i) {
      ft.cnt -= i;
      LL _A = A;
      A *= ft[i];
      if(A <= cube_root)
        chmin(ret, DFS(d + 1));
      A = _A;
      ft.cnt += i;
    };
    int upper = 0;
    while(upper < ft.cnt && A * ft[upper] <= cube_root) ++upper;
    if(A * ft[upper] > cube_root) --upper;
    for(int i = upper; i >= 0; --i) go(i);
    return ret;
  }
}

void solve() {
  A = B = C = P = 1;
  ans = ansA = ansB = ansC = 0x3f3f3f3f3f3f3f3fLL;
  for(const Factor &ft : f) {
    for(int i = 0; i < ft.cnt; ++i) P *= ft.p;
  }
  cube_root = (LL)(std::pow((LD)P, (LD)0.3333333334));
  std::sort(f.begin(), f.end());
//  for(auto ft : f) {
//  	printf("(%lld ^ %d) ", ft.p, ft.cnt);
//  } printf("\n");
  DFS(0);
  cout << (ans * 2) << " " << ansA << " " << ansB << " " << ansC << endl;
}

/*
12
2 8
3 4
5 2 7 2
11 1 13 1 17 1 19 1 23 1 29 1 31 1 37 1
*/

int main() {
  int T; cin >> T;
  while(T--) {
  	f.clear();
    cin >> n;
    for(int i = 0; i < n; ++i) {
      LL p; int cnt; cin >> p >> cnt;
      f.push_back(Factor(p, cnt));
    }
    solve();
  }
  return 0;
}