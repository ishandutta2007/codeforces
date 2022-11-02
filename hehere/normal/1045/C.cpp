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
#include <stack>
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
using std::stack;
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
int n, m, q;
vector<int> H[maxN];
vector<int> G[maxN * 2];

void addEdges(int bcc, const vector<int> &v) {
	for(int x : v) {
		G[x].push_back(bcc + n);
		G[bcc + n].push_back(x);
	}
}

int f[20][maxN * 2], s[20][maxN * 2];
int dep[maxN * 2];
void DFS_little(int u, int fa, int d = 1) {
  dep[u] = d;
  for(int v : G[u]) if(v != fa) {
    f[0][v] = u;
    DFS_little(v, u, d + 1);
  }
}

int pre[maxN], iscut[maxN], bccno[maxN], dfs_clock, bcc_cnt;
vector<int> bcc;
stack<pii> S;

int DFS(int u, int fa) {
  int lowu = pre[u] = ++dfs_clock;
  int child = 0;
  for(int v : H[u]) {
    pii e = pii(u, v);
    if(!pre[v]) {
      S.push(e);
      child++;
      int lowv = DFS(v, u);
      chmin(lowu, lowv);
      if(lowv >= pre[u]) {
        iscut[u] = true;
        bcc_cnt++;
        bcc.clear();
        while(1) {
          pii x = S.top(); S.pop();
          if(bccno[x.first] != bcc_cnt) {
            bcc.push_back(x.first);
            bccno[x.first] = bcc_cnt;
          }
          if(bccno[x.second] != bcc_cnt) {
            bcc.push_back(x.second);
            bccno[x.second] = bcc_cnt;
          }
          if(x.first == u && x.second == v) break;
        }
//        displaya(bcc, 0, ((int)bcc.size() - 1));
        addEdges(bcc_cnt, bcc);
      }
    } else if(pre[v] < pre[u] && v != fa) {
      S.push(e);
      chmin(lowu, pre[v]);
    }
  }
  if(fa < 0 && child == 1) iscut[u] = 0;
  return lowu;
}

void build() {
  memset(pre, 0, sizeof(pre));
  memset(iscut, 0, sizeof(iscut));
  memset(bccno, 0, sizeof(bccno));
  dfs_clock = bcc_cnt = 0;
  for(int i = 0; i < n; ++i) if(!pre[i]) DFS(i, -1);
}

pii LCA(int x, int y) {
  int val = 0;
  if(dep[x] < dep[y]) std::swap(x, y);
  int dif = dep[x] - dep[y];
  for(int i = 0; i < 20; ++i) if(dif >> i & 1) {
    val += s[i][x]; x = f[i][x];
  }
  if(x == y) return pii(x, val + (x > n));
  for(int i = 19; i >= 0; --i) if(f[i][x] != f[i][y]) {
    val += s[i][x] + s[i][y];
    x = f[i][x]; y = f[i][y];
  }
  return pii(f[0][x], val + s[0][f[0][x]] + s[0][x] + s[0][y]);
}

int main() {
  n = readint(); m = readint(); q = readint();
  for(int i = 1; i <= m; ++i) {
    int x = readint(), y = readint();
    H[x].push_back(y); H[y].push_back(x);
  }
  build();
  DFS_little(1, -1);
  f[0][1] = 0;
  for(int i = 1; i <= n + bcc_cnt; ++i) s[0][i] = (i > n);
  for(int k = 1; k < 20; ++k) {
    for(int u = 1; u <= n + bcc_cnt; ++u) {
      f[k][u] = f[k - 1][f[k - 1][u]];
      s[k][u] = s[k - 1][u] + s[k - 1][f[k - 1][u]];
    }
  }
//  for(int u = 1; u <= n + bcc_cnt; ++u) {
//  	printf("%d : f = %d, d = %d, s = %d, ss = %d\n",
//			u, f[0][u], dep[u], s[0][u], s[1][u]);
//	}
  for(int kase = 1; kase <= q; ++kase) {
    int x = readint(), y = readint();
    pii p = LCA(x, y);
    printf("%d\n", p.second);
  }
  return 0;
}