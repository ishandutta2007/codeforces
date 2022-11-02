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

#include <cmath>

const int maxN = 5000 + 5;
const int maxM = 5000 + 5;
int n, m;
double p[maxN];
int t[maxN];
double f[maxM], g[maxM];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> p[i] >> t[i];
    for(int i = 1; i <= n; ++ i) p[i] /= 100;
//    n = m = 5000;
//    for(int i = 1; i <= n; ++ i) p[i] = 0.99, t[i] = 5000;
    for(int j = 1; j <= m; ++ j) f[j] = 0;
    f[0] = 1;
    double ans = 0;
//    cerr << std::setprecision(3);
    for(int i = 1; i <= n; ++ i) {
        for(int j = 0; j <= m; ++ j) g[j] = 0;
        double sum = 0;
        double C = std::pow(1 - p[i], t[i] - 1);
        for(int j = 0; j < m; ++ j) {
            sum = sum * (1 - p[i]) + f[j];
            if(j + 1 - t[i] >= 0) sum -= f[j + 1 - t[i]] * C;
            // cerr << "sum on " << pii(i, j) << " = " << sum << endl;
            g[j + 1] = sum * p[i];
            if(j + 1 - t[i] >= 0) g[j + 1] += f[j + 1 - t[i]] * C;
        }
//        displaya(g, 0, m);
        memcpy(f, g, sizeof(g));
        if(i < n) {
            double tot = 0;
            for(int j = m - t[i + 1] + 1; j <= m; ++ j) tot = tot * (1 - p[i + 1]) + g[j];
            ans += tot * i;
        } else {
            double tot = 0;
            for(int j = 0; j <= m; ++ j) tot += g[j];
            ans += tot * i;
        }
    }
    cout << std::fixed << std::setprecision(10) << ans << endl;
    return 0;
}