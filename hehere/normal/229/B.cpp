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

const int maxN = 100000 + 233;
const int INF = 0x3f3f3f3f;
int n, m;
vector<pii> G[maxN];
vector<int> s[maxN];
int d[maxN];

int getleave(int t, const vector<int> &s) {
  if(s.size() == 0) return t;
  int i = 0;
  while(i < (int)s.size() && s[i] < t) ++i;
  if(i == (int)s.size() || s[i] != t) return t;
  while(i + 1 < (int)s.size() && s[i + 1] == s[i] + 1) ++i;
  return s[i] + 1;
}

int main() {
  n = readint(); m = readint();
  for(int i = 1; i <= m; ++i) {
    int x = readint(), y = readint(), w = readint();
    G[x].push_back(pii(y, w));
    G[y].push_back(pii(x, w));
  }
  for(int i = 1; i <= n; ++i) {
    s[i].resize(readint());
    for(auto &x : s[i]) x = readint();
  }
  priority_queue<pii> pq;
  memset(d, INF, sizeof(d));
  d[1] = 0;
  pq.push(pii(0, 1));
  while(!pq.empty()) {
    int u = pq.top().second;
    if(pq.top().first == -d[u]) pq.pop();
    else { pq.pop(); continue; }
    int base = getleave(d[u], s[u]);
//    printf("%d : %d -> %d\n", u, d[u], base);
    for(pii p : G[u]) {
      int v = p.first, w = p.second;
      if(chmin(d[v], base + w)) pq.push(pii(-d[v], v));
    }
  }
  printf("%d\n", d[n] == INF ? -1 : d[n]);
  return 0;
}