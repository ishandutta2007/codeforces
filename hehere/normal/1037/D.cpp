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

const int maxN = 200000 + 233;
int n;
int a[maxN];
int deg[maxN], fa[maxN];
int pos[maxN];
vector<int> G[maxN];

void DFS(int u, int fat) {
  for(auto it = G[u].begin(); it != G[u].end(); ++it) if(*it == fat) {
    G[u].erase(it, it + 1); break;
  }
  deg[u] = 0;
  for(int v : G[u]) if(v != fat) {
    ++deg[u]; fa[v] = u;
    DFS(v, u);
  }
}

bool check() {
  int end = 1;
  for(int i = 1; i <= n; ++i) {
  	int v = a[i];
    if(--deg[fa[v]] == 0 && i != pos[fa[v]]) return false;
    end += deg[v];
    if(deg[v]) pos[v] = end;
//    printf("%d %d %d %d %d\n", v, fa[v], deg[fa[v]], (int)G[v].size(), end);
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y); G[y].push_back(x);
  }
  fa[1] = 0; deg[0] = 1; pos[0] = 1;
  DFS(1, -1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  cout << (check() ? "Yes" : "No") << endl;
	return 0;
}