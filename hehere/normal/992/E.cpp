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

const int maxN = 200000 + 5;
const int maxQ = 200000 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, q;
LL a[maxN];
struct FenwickTree {
  LL C[maxN];
  void init() {
    for(int i = 0; i <= n; ++i) C[i] = 0;
  }
  void add(int p, LL x) {
    for(int i = p; i <= n; i += i & -i) C[i] += x;
  }
  LL sum(int p) {
    LL r = 0;
    for(int i = p; i > 0; i -= i & -i) r += C[i];
    return r;
  }
}fwt;
struct SegmentTree {
#define lson (o << 1)
#define rson (o << 1 | 1)
  LL max[maxN * 4];
  void init() {
    for(int o = 0; o <= n * 4; ++o) max[o] = -1;
  }

  void maintain(int o) {
    max[o] = std::max(max[lson], max[rson]);
  }

  int ql, qr, qp, ans;
  LL qv;
  void build(int o, int L, int R) {
    if(L == R) {
      max[o] = a[L];
    } else {
      int M = (L + R) >> 1;
      build(lson, L, M);
      build(rson, M + 1, R);
      maintain(o);
    }
  }

  void modify(int o, int L, int R) {
    if(L == R) {
      max[o] = qv;
    } else {
      int M = (L + R) >> 1;
      if(qp <= M) modify(lson, L, M);
      else modify(rson, M + 1, R);
      maintain(o);
    }
  }

  void dig(int o, int L, int R) {
    if(ans) return;
	if(L == R) {
      if(max[o] >= qv) ans = L;
    } else {
      int M = (L + R) >> 1;
      if(max[lson] >= qv) query(lson, L, M);
      else if(max[rson] >= qv) dig(rson, M + 1, R);
    }
  }

  void query(int o, int L, int R) {
  	if(ans) return;
    if(ql <= L && R <= qr) {
//      printf("[%d, %d] : %lld\n", L, R, max[o]);
      if(max[o] >= qv) dig(o, L, R);
    } else {
      int M = (L + R) >> 1;
//      printf("[%d, %d] : max = %lld\n", L, R, max[o]);
      if(ql <= M) query(lson, L, M);
      if(M < qr) query(rson, M + 1, R);
    }
  }

#undef lson
#undef rson
}st;

int solve() {
  LL pref = 0; int pos = 0;
  while(pos <= n) {
    st.ans = 0; st.ql = pos + 1; st.qr = n + 1; st.qv = pref;
    st.query(1, 1, n + 1);
//    printf("pos = %d, pref = %lld, st.ans = %d\n", pos, pref, st.ans);
//    printf("\t\tsum = %lld\n", fwt.sum(st.ans - 1));
	if(st.ans && a[st.ans] == fwt.sum(st.ans - 1)) return st.ans;
    pref = fwt.sum(st.ans); pos = st.ans;
    if(!pos) return -1;
  }
  return -1;
}

int main() {
  n = readint(); q = readint();
  st.init(); fwt.init();
  for(int i = 1; i <= n; ++i) {
    fwt.add(i, a[i] = readLL());
  }
  a[n + 1] = INF;
  st.build(1, 1, n + 1);
  for(int i = 1; i <= q; ++i) {
    int p = readint(); LL x = readLL();
    fwt.add(p, x - a[p]); a[p] = x;
    st.qp = p; st.qv = x; st.modify(1, 1, n + 1);
    printf("%d\n", solve());
  }
  return 0;
}