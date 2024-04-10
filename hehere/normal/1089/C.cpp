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

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
  return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 500 + 5;
int n, m;
vector<int> G[maxN];
bool ok[maxN];
int dx[maxN], dy[maxN];

queue<int> Q;
void BFS(int s, int d[]) {
  for(int u = 1; u <= n; ++u) d[u] = -1;
  d[s] = 0; Q.push(s);
  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    for(int v : G[u]) if(d[v] == -1) d[v] = d[u] + 1, Q.push(v);
  }
}

int tot = 0;
int minmax = maxN, vert = -1;
bool vis[maxN];
int DFS(int u) {
  vis[u] = true;
  int sz = 1, max = 0;
  for(int v : G[u]) if(!vis[v] && ok[v]) {
    int c = DFS(v);
    sz += c;
    chmax(max, c);
  }
  chmax(max, tot - sz);
  if(chmin(minmax, max)) vert = u;
//  printf("u = %d: sz = %d, max = %d\n", u, sz, max);
  return sz;
}

void play() {
  for(int u = 1; u <= n; ++u) ok[u] = true;
//  int chance = 10;
  static char str[100];
  while(1) {
    minmax = maxN; vert = -1;
    int root = 0; tot = 0;
    for(int u = 1; u <= n; ++u) if(ok[u]) root = u, ++tot;
    assert(root > 0);
    for(int u = 1; u <= n; ++u) vis[u] = false;
    DFS(root);
    root = vert;
    cout << root << endl;
    scanf("%s", str);
    if(str[0] == 'F') return;
    int s;
    scanf("%d", &s);
    BFS(root, dx); // displaya(dx, 1, n);
    BFS(s, dy); // displaya(dy, 1, n);
    for(int u = 1; u <= n; ++u) if(dy[u] >= dx[u]) ok[u] = false;
  }
}

int main() {
  n = readint(); m = readint();
  for(int u = 1; u <= n; ++u) G[u].clear();
  for(int i = 1; i <= m; ++i) {
    int cnt = readint();
    int pre = -1;
    while(cnt--) {
      int x = readint();
      if(pre != -1) G[x].push_back(pre), G[pre].push_back(x);
      pre = x;
    }
  }
  for(int qwq = 1; qwq <= n; ++qwq) play();
  return 0;
}