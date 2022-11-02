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
  void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
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

const int maxN = 2000 + 23;
int n, m, sx, sy;
int maxl, maxr;
bool ok[maxN][maxN];

void initialize() {
  scanf("%d%d%d%d", &n, &m, &sx, &sy);
  scanf("%d%d", &maxl, &maxr);
  static char s[maxN];
  memset(ok, 0, sizeof(ok));
  for(int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for(int j = 1; j <= m; ++j) ok[i][j] = (s[j] == '.');
  }
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1}; // right
int val[maxN][maxN];

int encode(int x, int y) {
	return x << 15 | y;
}
pii decode(int code) {
	return pii(code >> 15, code & ((1 << 14) - 1));
}

const int N = maxN * maxN * 4;
struct Heap
{
    pii g[N];
		int len;
    
    inline void push(pii res)
    {
        int now = ++len, nxt = len >> 1;
        while (nxt)
        {
            if (res < g[nxt])
                g[now] = g[nxt], now = nxt, nxt >>= 1;
            else break;
        }
        g[now] = res; 
    }
    
    inline pii top() {
    	return g[1];
		}
		
		bool empty() {
			return len == 0;
		}
    
    inline void pop()
    {
        int now = 1, nxt = 2;
				pii res = g[len--];
        while (nxt <= len)
        {
            if (nxt < len && g[nxt | 1] < g[nxt]) nxt |= 1;
            if (g[nxt] < res)
                g[now] = g[nxt], now = nxt, nxt <<= 1;
            else break;
        }
        g[now] = res;
    }
}Q;

void solve() {
  memset(val, 0x3f, sizeof(val));
  val[sx][sy] = 0;
  Q.push(pii(0, encode(sx, sy)));
  while(!Q.empty()) {
    pii p = Q.top(); Q.pop();
    int v = p.first;
    p = decode(p.second);
    if(v != val[p.first][p.second]) continue;
//    printf("from %d %d\n", p.first, p.second);
    int origin = val[p.first][p.second];
    for(int i = 0; i < 4; ++i) {
      int x = p.first + dx[i], y = p.second + dy[i];
      if(!ok[x][y]) continue;
//      printf("to %d %d\n", x, y);
      int d = origin + (i == 3);
      if(val[x][y] > d) {
//#ifdef DEBUG
//        assert(val[x][y] == 0x3f3f3f3f);
//#endif
        val[x][y] = d;
        Q.push(pii(d, encode(x, y)));
      }
    }
  }
}

int main() {
  initialize();
  solve();
  int cnt = 0;
//  for(int x = 1; x <= n; ++x) {
//  	for(int y = 1; y <= m; ++y) printf("%d ", val[x][y]);
//  	cout << endl;
//	}
  for(int x = 1; x <= n; ++x) for(int y = 1; y <= m; ++y) if(ok[x][y]) {
    if(val[x][y] <= maxr && (val[x][y] - y + sy) <= maxl) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}