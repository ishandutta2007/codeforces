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
int n, m;
vector<pii> G[maxN];
LL size[maxN], sum[maxN], f[maxN];

void DFS_first(int u, int fa) {
  for(int i = 0; i < (int)G[u].size(); ++i) if(G[u][i].first == fa) {
    G[u].erase(G[u].begin() + i, G[u].begin() + i + 1);
    break;
  }
  size[u] = 1; sum[u] = 0;
  for(auto p : G[u]) {
    int v = p.first, w = p.second;
    DFS_first(v, u);
    size[u] += size[v];
    sum[u] += (sum[v] += 2 * w);
  }
}

bool cmp(pii x, pii y) {
  return sum[x.first] * size[y.first] < sum[y.first] * size[x.first];
}
void DFS(int u) {
  for(pii p : G[u]) DFS(p.first);
  std::sort(G[u].begin(), G[u].end(), cmp);
  f[u] = 0;
  LL t = 0;
  for(pii p : G[u]) {
    int v = p.first;
    f[u] += p.second * size[v] + t * size[v] + f[v];
    t += sum[v];
  }
//  printf("f[%d] = %lld\n", u, f[u]);
}

int main() {
  n = readint();
  for(int i = 1; i < n; ++i) {
    int x = readint(), y = readint(), w = readint();
    G[x].push_back(pii(y, w));
    G[y].push_back(pii(x, w));
  }
  DFS_first(1, -1);
  DFS(1);
  cout << std::fixed << std::setprecision(8);
  cout << (f[1] / (double)(n - 1)) << endl;
  return 0;
}