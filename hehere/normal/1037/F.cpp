#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
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
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
#endif

template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifndef LOCAL
#define QUICK_READ
#endif
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
const LL P = 1000000007;
int n, k, a[maxN];
struct SparseTable {
  int n, lg2[maxN];
  int f[maxN][22];
  int *a;
  void init(int n, int *a) {
    this->n = n; this->a = a;
    memset(lg2, 0, sizeof(lg2));
    memset(f, 0, sizeof(f));
    lg2[1] = 0;
    for(int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
    for(int i = 1; i <= n; ++i) f[i][0] = a[i];
    for(int k = 1; k <= lg2[n]; ++k)
      for(int i = 1; i + (1 << (k - 1)) <= n; ++i)
        f[i][k] = std::max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
  }
  int query(int L, int R) {
    int k = lg2[R - L + 1];
    return std::max(f[L][k], f[R - (1 << k) + 1][k]);
  }
} st;
int m;
int b[maxN], p[maxN];
bool cmp(int x, int y) {
  return b[x] > b[y];
}
int C[maxN];
void modify(int p, int x) {
  for(int i = p; i <= m; i += i & -i) C[i] += x;
}
int sum(int p) {
  int r = 0;
  for(int i = p; i > 0; i -= i & -i) r += C[i];
  return r;
}
int pre(int p) {
  int s = sum(p);
  if(s == 0) return 0;
  int r = 0;
  for(int i = (1 << 22); i; i >>= 1) {
    if(r + i <= m && C[r + i] < s) s -= C[r += i];
  }
  return r + 1;
}
int post(int p) {
  int s = sum(p) + 1;
  int r = 0;
  for(int i = (1 << 22); i; i >>= 1) {
//  	if(r + i <= m) printf("s = %d, r = %d, consider C[%d] = %d\n", s, r, r + i, C[r + i]);
    if(r + i <= m && C[r + i] < s) s -= C[r += i];
  }
//  printf("r = %d\n", r);
  return r + 1;
}

int main() {
  n = readint(); k = readint();
  for(int i = 1; i <= n; ++i) a[i] = readint();
  st.init(n, a);
  LL ans = 0;
  for(int t = 1; t < k; ++t) {
    m = 0;
    for(int i = t, j = t + k - 1; j <= n; i += k - 1, j += k - 1) {
      b[++m] = st.query(i, j);
    }
//    for(int i = 1; i <= m; ++i) printf("%d ", b[i]); printf("\n");
    for(int i = 1; i <= m; ++i) p[i] = i, C[i] = 0;
    std::sort(p + 1, p + m + 1, cmp);
    for(int i = 1; i <= m; ++i) {
      int l = pre(p[i]), r = post(p[i]);
//      printf("%d : %d, %d\n", p[i], l, r);
      ans += (r - p[i]) * (LL)(p[i] - l) % P * (LL)b[p[i]] % P;
      modify(p[i], 1);
    }
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}