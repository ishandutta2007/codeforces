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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#include <ctime>
class MyTimer {
	clock_t st;
public:
	MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
	~MyTimer() { report(); }
	void reset() { st = clock_t(); }
	void report() {  cerr << "Time consumed: " << (clock() - st) * \
		1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
#define eprintf(...) if(0) fprintf(stderr, __VA_ARGS__)
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

const int maxN = 200000 + 233;
int n, m, q;
int p[maxN], ip[maxN], a[maxN], pos[maxN];
int f[20][maxN], dep[maxN];
int x[20][maxN], lg[maxN];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) cin >> p[i], ip[p[i]] = i;
	for(int i = 1; i <= m; ++i) cin >> a[i];
	memset(pos, 0, sizeof(pos)); dep[0] = 0; f[0][0] = 0;
	for(int i = 1; i <= m; ++i) {
		int rk = ip[a[i]] - 1;
		if(rk == 0) rk = n;
		int last = pos[p[rk]];
		dep[i] = dep[last] + 1;
		f[0][i] = last;
		pos[a[i]] = i;
	}
	for(int k = 1; k < 20; ++k)
		for(int i = 1; i <= m; ++i)
			f[k][i] = f[k - 1][f[k - 1][i]];
	for(int i = 1; i <= m; ++i) {
		int p = i;
		for(int k = 0; k < 19; ++k) if((n - 1) >> k & 1)
			p = f[k][p];
		x[0][i] = p;
//		printf("%d: f = %d, x = %d\n", i, f[0][i], p);
	}
	lg[1] = 0;
	for(int i = 2; i <= m; ++i) lg[i] = lg[i / 2] + 1;
	for(int k = 1; k < 20; ++k)
		for(int i = 1; i + (1 << k) - 1 <= m; ++i)
			x[k][i] = std::max(x[k - 1][i], x[k - 1][i + (1 << (k - 1))]);
	while(q--) {
		int l, r; cin >> l >> r;
		int k = lg[r - l + 1];
		int res = std::max(x[k][l], x[k][r - (1 << k) + 1]);
//		printf("k = %d, res = %d\n", k, res);
		if(res >= l) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}