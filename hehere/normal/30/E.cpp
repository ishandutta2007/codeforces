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

const int maxN = 100000 + 233;
int n, r[maxN];
char buc[maxN * 2];
int buc_z[maxN * 2];
char *s = buc + maxN;
int *z = buc_z + maxN;
int ans;
vector<pii> sol;

void manacher(char *s, int *r) {
  int n = strlen(s);
  int M = 0, R = 0;
  r[0] = 1;
  for(int i = 1; i < n; ++i) {
  	int &len = r[i];
    len = i > R ? 1 : std::min(r[2 * M - i], R - i);
    while(i - len >= 0 && i + len < n && s[i + len] == s[i - len]) ++len;
    if(i + len > R) M = i, R = i + len;
  }
}

void algoZ(char *s, int *z) {
  int n = strlen(s);
  int L = 0, R = 0;
  for(int i = 1; i < n; ++i) {
    int &len = z[i];
		len = i > R ? 0 : std::min(z[i - L], R - i);
    while(i + len < n && s[len] == s[i + len]) ++len;
    if(i + len > R) L = i, R = i + len;
  }
}

template<int NODE>
struct SegmentTree {
#define lson (o << 1)
#define rson (o << 1 | 1)
  int max[NODE];
  void maintain(int o, int L, int R) {
    max[o] = r[max[lson]] > r[max[rson]] ? max[lson] : max[rson];
  }
  void build(int o, int L, int R) {
    if(L == R) {
      max[o] = L;
    } else {
      int M = (L + R) >> 1;
      build(lson, L, M);
      build(rson, M + 1, R);
      maintain(o, L, R);
    }
  }
  int ql, qr, qp, qans;
  void modify(int o, int L, int R) {
    if(L == R) {
      max[o] = n; // remember to modify r[n]
    } else {
      int M = (L + R) >> 1;
      if(qp <= M) modify(lson, L, M);
      else modify(rson, M + 1, R);
      maintain(o, L, R);
    }
  }
  void query(int o, int L, int R) {
    if(ql <= L && R <= qr) {
      if(chmax(qans, r[max[o]])) qp = max[o];
    } else {
      int M = (L + R) >> 1;
      if(ql <= M) query(lson, L, M);
      if(qr > M) query(rson, M + 1, R);
    }
  }
#undef lson
#undef rson
};
SegmentTree <maxN * 4> st;

int mode;
struct Candidate {
  int ls, rs, sideLen;
  int L, M, R;
  int pos, len;
  Candidate(int ls, int rs, int sideLen, int L, int M, int R) :
    ls(ls), rs(rs), sideLen(sideLen), L(L), M(M), R(R) { pos = len = -1; }
  void update() {
    if(chmax(ans, sideLen * 2 + len)) sol = {pii(ls, sideLen), pii(pos, len), pii(rs, sideLen)};
  }
  friend bool operator < (const Candidate &A, const Candidate &B) {
    if(mode == 1) return A.L < B.L;
    else if(mode == 2) return A.R < B.R;
    else return assert(false), false;
  }
};
vector<Candidate> vc;

void initialize() {
  scanf("%s", s);
  n = strlen(s);
  manacher(s, r);
  for(int i = 0; i < n; ++i) s[- i - 1] = s[i];
  algoZ(s - n, z - n);

//  displaya(r, 0, n - 1);
//  displaya(z, 0, n - 1);

  ans = 0;
  for(int i = 0; i < n; ++i) if(chmax(ans, r[i] * 2 - 1)) ans = r[i] * 2 - 1, sol = {pii(i - r[i] + 1, r[i] * 2 - 1)};

  for(int i = 0; i < n; ++i) {
    int len = std::min(z[i], (n - i - 1) / 2);
    if(len == 0 || n - i < ans) continue;
    int l = i + len, r = n - len - 1;
    int m = (l + r) / 2;
    vc.push_back(Candidate(i, n - len, len, l, m, r)); // inclusive intervals
  }
}

priority_queue <pii, vector<pii>, std::greater<pii> > little_top;
priority_queue <pii, vector<pii>, std::less<pii> > large_top;

void solve() {
#define pq little_top
  mode = 1;
  std::sort(vc.begin(), vc.end());
  for(int i = 0; i < n; ++i) pq.push(pii(i - r[i] + 1, i));
  st.build(1, 0, n - 1);
  for(auto &c : vc) {
  	int r = c.R, l = c.L;
    if(r - l < 5) {
      for(int i = l; i < r; ++i) {
        c.len = std::min({::r[i], i - l + 1, r - i + 1});
        c.pos = i - c.len + 1;
        c.len = c.len * 2 - 1;
        c.update();
      }
      break;
    }
    while(!pq.empty() && pq.top().first < c.L) {
      st.qp = pq.top().second;
      st.modify(1, 0, n - 1);
      pq.pop();
    }
    st.qans = -1; st.qp = -1;
    st.ql = c.L; st.qr = c.M;
    st.query(1, 0, n - 1);
    if(c.L <= st.qp && st.qp <= c.M) {
      c.pos = st.qp - ::r[st.qp] + 1;
      c.len = ::r[st.qp] * 2 - 1;
      c.update();
    }
  }

#undef pq
#define pq large_top

  mode = 2;
  std::sort(vc.begin(), vc.end());
  for(int i = 0; i < n; ++i) pq.push(pii(i + r[i] - 1, i));
  st.build(1, 0, n - 1);
  for(auto &c : vc) {
  	int r = c.R, l = c.L;
    if(r - l < 5) break;
    while(!pq.empty() && pq.top().first > c.R) {
      st.qp = pq.top().second;
      st.modify(1, 0, n - 1);
      pq.pop();
    }
    st.qans = -1; st.qp = -1;
    st.ql = c.M + 1; st.qr = c.R;
    st.query(1, 0, n - 1);
    if(c.M + 1 <= st.qp && st.qp <= c.R) {
      c.pos = st.qp - ::r[st.qp] + 1;
      c.len = ::r[st.qp] * 2 - 1;
      c.update();
    }
  }
#undef pq
}

int main() {

  initialize();

  solve();

  cout << sol.size() << endl;
  for(auto p : sol) cout << p.first + 1 << " " << p.second << endl;
  return 0;
}