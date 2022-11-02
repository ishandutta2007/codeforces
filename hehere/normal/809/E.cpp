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
const LL P = 1000000007;
int n;
vector<int> G[maxN];

LL qpow(LL a, LL b) {
  LL r = 1;
  while(b) {
    if(b & 1) (r *= a) %= P;
    b >>= 1; (a *= a) %= P;
  }
  return r;
}
void inc(LL &x, LL y) {
  (x += y) >= P ? x -= P : x;
}
void dec(LL &x, LL y) {
  (x -= y) < 0 ? x += P : x;
}
LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

LL inv[maxN], phi[maxN], dphi[maxN], c[maxN];
vector<int> divisors[maxN];

void initialize() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  static int p[maxN];
  for(int u = 1; u <= n; ++u) cin >> p[u];
  for(int u = 1; u <= n; ++u) G[u].clear();
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y; x = p[x]; y = p[y];
    G[x].push_back(y); G[y].push_back(x);
  }
  memset(phi, 0, sizeof(phi));
  for(int i = 1; i <= n; ++i) inv[i] = qpow(i, P - 2);
  for(int i = 1; i <= n; ++i) divisors[i].clear();
  for(int i = 1; i <= n; ++i)
    for(int j = i; j <= n; j += i) divisors[j].push_back(i);
  auto get_phi = [&](int x) -> LL {
    LL r = x;
    while(x > 1) {
      int i = divisors[x][1];
      while(x % i == 0) x /= i;
      r = r / i * (i - 1);
    }
    return r;
  };
  for(int i = 1; i <= n; ++i) phi[i] = get_phi(i), dphi[i] = i * qpow(phi[i], P - 2) % P;
  for(int i = 1; i <= n; ++i) {
  	c[i] += dphi[i];
    c[i] %= P; c[i] += P; c[i] %= P;
    for(int j = i * 2; j <= n; j += i) c[j] -= c[i];
  }
//  displaya(phi, 1, n);
//  displaya(dphi, 1, n);
//  displaya(c, 1, n);
}

LL ans = 0;

bool done[maxN];
int tot, bestv = 0x3f3f3f3f, center = -1;
int DFSCenter(int u, int fa) {
  int sz = divisors[u].size(), max = 0;
  for(int v : G[u]) if(v != fa && !done[v]) {
    int cc = DFSCenter(v, u);
    sz += cc;
    chmax(max, cc);
  }
  chmax(max, tot - sz);
  chmin(bestv, max) && (center = u);
  return sz;
}

int DFSSize(int u, int fa) {
  int sz = divisors[u].size();
  for(int v : G[u]) if(v != fa && !done[v]) sz += DFSSize(v, u);
  return sz;
}

vector<pii> f, g;
void DFS(int u, int fa, int dep) {
  f.emplace_back(u, dep);
  for(int v : G[u]) if(v != fa && !done[v]) {
    DFS(v, u, dep + 1);
  }
}

LL calc(vector<pii> &a) {
	static LL f[maxN];
  LL res = 0;
  if(a.size() < 0) {
		for(auto i = a.begin(); i != a.end(); ++i)
  		for(auto j = a.begin(); j != i; ++j) {
  			LL x = i->first, y = j->first, d = i->second + j->second, g = gcd(x, y);
//  			cout << *i << " " << *j << " " << d * phi[x] % P * phi[y] % P * dphi[g] % P << endl;
  			inc(res, d * phi[x] % P * phi[y] % P * dphi[g] % P);
			}
	} else {
		for(pii p : a) {
			for(int d : divisors[p.first]) {
				inc(f[d], phi[p.first]);
			}
		}
		for(pii p : a) {
			LL dans = 0;
			for(int d : divisors[p.first]) {
				inc(dans, (P - phi[p.first] + f[d] * c[d]) % P);
			}
			dans = dans * p.second % P * phi[p.first] % P;
			inc(res, dans);
//			if(dans) cout << p << " gives " << dans << endl;
		}
		for(pii p : a) {
			for(int d : divisors[p.first]) f[d] = 0;
		}
	}
  inc(res, res);
//	displayv(a);
//	display(res);
  return res;
}

void solve(int u) {
  bestv = 0x3f3f3f3f; center = -1;
  int cur_size = DFSCenter(u, -1);
  assert(cur_size == tot);
  u = center;
  f.clear(); g.clear();
  LL dans = 0;
  for(int v : G[u]) if(!done[v]) {
    DFS(v, u, 1);
    dans -= calc(f);
    g.insert(g.end(), f.begin(), f.end());
    f.clear();
  }
  g.emplace_back(u, 0);
  dans += calc(g);
  dans %= P; dans += P; dans %= P;
  ans = (ans + dans) % P;
  done[u] = true;
  for(int v : G[u]) if(!done[v]) {
    tot = DFSSize(v, -1);
    solve(v);
  }
}

int main() {
  initialize();
  memset(done, 0, sizeof(done));
  tot = 0;
  for(int i = 1; i <= n; ++i) tot += divisors[i].size();
  solve(1);
//  display(ans);
  ans = ans * qpow(n, P - 2) % P * qpow(n - 1, P - 2) % P;
  cout << ans << endl;
  return 0;
}