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
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                      \
	{                                           \
		cerr << #a << " = {";                   \
		for (int qwq = (st); qwq <= (n); ++qwq) \
			if (qwq == (st))                    \
				cerr << a[qwq];                 \
			else                                \
				cerr << ", " << a[qwq];         \
		cerr << "}" << endl;                    \
	}
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
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
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
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

const int maxN = 200000 + 233;
const int maxA = 1000000 + 233;
int n, k, a[maxN], pa[maxN];
vector<int> G[maxN];

int M;

int f[maxN];
bool g[maxN];
int maxf[maxN], secf[maxN], sumf[maxN];
int cntg[maxN];
int sz[maxN];
void DFS(int u) {
    maxf[u] = secf[u] = sumf[u] = cntg[u] = 0;
    sz[u] = 1;
    for(int v : G[u]) if(a[v] >= M) {
        DFS(v);
        sz[u] += sz[v];
        if(g[v]) sumf[u] += sz[v], cntg[u] ++;
        else {
            if(maxf[u] < f[v]) secf[u] = maxf[u], maxf[u] = f[v];
            else chmax(secf[u], f[v]);
        }
    }
    f[u] = sumf[u] + maxf[u] + 1; // a little bit of ... myself
    g[u] = (cntg[u] == (int)G[u].size());
}

void March(int u, int fsz, int ff, bool fg) {
    // printf("u = %d: father passes fsz = %d, ff = %d, fg = %d\n", u, fsz, ff, (int)fg);
    sz[u] += fsz;
    if(fg) sumf[u] += fsz, cntg[u] ++;
    else {
        if(maxf[u] < ff) secf[u] = maxf[u], maxf[u] = ff;
        else chmax(secf[u], ff);
    }
    f[u] = sumf[u] + maxf[u] + 1;
    for(int v : G[u]) if(a[v] >= M) {
        int _f = f[u];
        int _cntg = cntg[u];
        if(g[v]) _f -= sz[v], _cntg --;
        else {
            if(f[v] == maxf[u]) _f = _f - maxf[u] + secf[u];
        }
        March(v, sz[u] - sz[v], _f, _cntg == (int)G[u].size());
    }
}

vector<int> roots;
bool check() {
    // display(M);
    roots.clear();
    for(int u = 1; u <= n; ++ u)
        if(a[u] >= M && a[pa[u]] < M) roots.push_back(u);
    memset(f, 0, sizeof(f));
    for(int rt : roots) {
        DFS(rt);
        March(rt, 0, 0, pa[rt] == 0);
    }
    // displaya(f, 1, n);
    for(int u = 1; u <= n; ++ u) if(f[u] >= k) return true;
    return false;
}

int main() {
    n = readint(); k = readint();
    for(int i = 1; i <= n; ++ i) a[i] = readint();
    for(int i = 1; i <= n - 1; ++ i) {
        int x = readint(), y = readint();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int> Q; Q.push(1); pa[1] = 0;
    while(Q.size()) {
        int u = Q.front(); Q.pop();
        for(auto i = G[u].begin(); i != G[u].end(); ++ i) if(*i == pa[u]) {
            G[u].erase(i); break;
        }
        for(int v : G[u]) Q.push(v), pa[v] = u;
    }
    int L = *std::min_element(a + 1, a + n + 1);
    int R = *std::max_element(a + 1, a + n + 1);
    while(L < R) {
        M = (L + R + 1) >> 1;
        if(check()) L = M;
        else R = M - 1;
    }
    printf("%d\n", L);
    return 0;
}