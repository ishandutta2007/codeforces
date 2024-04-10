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
const int maxM = 200000 + 233;
int n, m, k;
int from[maxM], to[maxM];
int deg[maxN];
priority_queue<pii, vector<pii>, std::greater<pii> > pq;
vector<pii> G[maxN];
bool inq[maxN];

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  memset(deg, 0, sizeof(deg));
  memset(inq, 0, sizeof(inq));
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    deg[u]++; deg[v]++;
    G[u].push_back(pii(v, i));
    G[v].push_back(pii(u, i));
    from[i] = u; to[i] = v;
  }
  for(int i = 1; i <= n; ++i) pq.push(pii(deg[i], i)), inq[i] = true;
//  for(int i = 1; i <= n; ++i) printf("%d ", deg[i]); printf("\n");

  vector<int> arr(m);
  int ans = n;
  for(int i = m; i >= 1; --i) {
//  	printf("round %d\n", i);
    while(!pq.empty()) {
      int u = pq.top().second;
      if(!inq[u]) { pq.pop(); continue; }
      else if(deg[u] >= k) break;
	  else inq[u] = false, --ans, pq.pop();
//	  printf("%d pop\n", u);
      for(const pii &p : G[u]) if(inq[p.first] && p.second <= i) {
      	int v = p.first;
      	--deg[v];
//      	printf("deg[%d]-- -> %d\n", v, deg[v]);
        pq.push(pii(deg[v], v));
      }
    }
    arr[i - 1] = ans;
    int x = from[i], y = to[i];
    if(inq[x] && inq[y])
	pq.push(pii(--deg[x], x)), pq.push(pii(--deg[y], y));
  }
  for(int x : arr) printf("%d\n", x);
  return 0;
}