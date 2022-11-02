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

const int maxN = 4000 + 5;
const int maxK = 75 + 5;
const unsigned P = 998244353;
ULL qpow(ULL a, ULL b) {
    ULL r = 1;
    while(b) {
        if(b & 1) (r *= a) %= P;
        (a *= a) %= P; b >>= 1;
    }
    return r;
}
ULL fac[maxN], ifac[maxN];
ULL choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % P * ifac[n - k] % P;
}
int m;

void inc(unsigned &x, unsigned y) { (x += y) >= P ? x -= P : x; }

typedef unsigned Array[maxN];
Array buc1[maxN], buc2[maxN];
Array *x = buc1, *y = buc2;
struct Tree {
    int n;
    vector<int> G[maxN];

    void read() {
        for(int i = 1; i < n; ++ i) {
            int x, y; cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    unsigned f[maxK][maxN];
    void calc() {
        memset(x, 0, sizeof(buc1));
        memset(y, 0, sizeof(buc1));
        for(int u = 1; u <= n; ++ u) x[u][u] = 1;
        for(int i = 0; i <= m; ++ i) {
            for(int u = 1; u <= n; ++ u) f[i][u] = x[u][u];
            memset(y, 0, sizeof(buc1));
            for(int u = 1; u <= n; ++ u) {
                for(int v : G[u]) {
                    for(int t = 1; t <= n; ++ t)
                        inc(y[u][t], x[v][t]);
                }
            }
            std::swap(x, y);
        }
    }
}X, Y;

unsigned g[maxK];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> X.n >> Y.n >> m;
    X.read(); Y.read();
    X.calc(); Y.calc();
    for(int i = 0; i <= m; ++ i)
        for(int u = 1; u <= Y.n; ++ u)
            inc(g[i], Y.f[i][u]);
    fac[0] = 1;
    for(int i = 1; i < maxN; ++ i) fac[i] = fac[i - 1] * i % P;
    ifac[maxN - 1] = qpow(fac[maxN - 1], P - 2);
    for(int i = maxN - 2; i >= 0; -- i) ifac[i] = ifac[i + 1] * (i + 1) % P;
    unsigned ans = 0;
    for(int i = 0; i <= m; ++ i)
        for(int u = 1; u <= X.n; ++ u)
            inc(ans, (ULL)X.f[i][u] * g[m - i] % P * choose(m, i) % P);
    cout << ans << endl;
    return 0;
}