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

const int maxN = 2000000 + 233;
int n;
int a[maxN], s[maxN], pmin[maxN];

void initialize() {
    static char str[maxN];
    scanf("%s", str + 1);
    n = strlen(str + 1);
    for(int i = 1; i <= n; ++ i) a[i] = (str[i] == '(' ? 1 : -1);
    for(int i = n + 1; i <= 2 * n; ++ i) a[i] = a[i - n];
    s[0] = 0;
    for(int i = 1; i <= 2 * n; ++ i) s[i] = s[i - 1] + a[i];
    static int q[maxN];
    int f = 1, r = 0;
    q[r = 1] = 0;
    for(int i = 1; i <= n * 2; ++ i) {
        while(f <= r && s[q[r]] >= s[i]) -- r;
        q[++ r] = i;
        while(q[f] < i - n) ++ f;
        pmin[i] = s[q[f]];
    }
    for(int i = 1; i <= n; ++ i) pmin[i] = pmin[i + n - 1] - s[i - 1];
    displaya(pmin, 1, n);
}

int buc[maxN * 2], cub[maxN * 2], c[maxN];
int sa[maxN], rk[maxN], h[maxN];

void get_sa(int m) {
    int n = ::n * 2;
    memset(buc, -1, sizeof(buc));
    memset(cub, -1, sizeof(cub));
    int *x = buc, *y = cub;
    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i] = (a[i + 1] == -1 ? '0' : '1')]++;
    for(int i = 1; i < m; ++i) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for(int i = n - k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[i]]++;
        for(int i = 1; i < m; ++i) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];

        std::swap(x, y);
        x[sa[0]] = 0;
        p = 1;
        for(int i = 1; i < n; ++i) {
            x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
        }
        if(p == n) break;
        m = p;
    }
    for(int i = 0; i < n; ++i) rk[i] = x[i];
}


void solve() {
    get_sa(100);
    int best = 1;
    for(int i = 2; i <= n; ++ i) {
    	// pmin <= 0 always holds
        if(pmin[best] < pmin[i]) best = i;
        else if(pmin[best] == pmin[i]) {
            if(rk[best - 1] < rk[i - 1]) best = i;
        }
	}
	for(int i = 0; i < - pmin[best]; ++ i) putchar('(');
	for(int i = best; i < best + n; ++ i) putchar(a[i] == -1 ? ')' : '(');
	for(int i = 0; i < s[n] - pmin[best]; ++ i)
		putchar(')');
	putchar(10);
}

int main() {
    initialize();
    solve();
    return 0;
}