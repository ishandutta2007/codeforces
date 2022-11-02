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
#ifndef LOCAL
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),\
	1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
	int a = 0; char c = getchar(), p = 0;
	while(isspace(c)) c = getchar();
	if(c == '-') p = 1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return p ? -a : a;
}

const int maxN = 250000 + 233;
const int maxM = 10000000 + 233;
int n, m;
vector<pii> block[maxN];
int h[maxM];
LL c[maxM];
int stk[maxM], len;
LL f[maxM];
int lb[maxM], rb[maxM];

void initialize() {
	n = readint(); m = readint();
	for(int i = 1; i <= n; ++ i) {
		int sz = readint();
		block[i].resize(sz);
		for(int j = 0; j < sz; ++ j) block[i][j].first = readint();
		for(int j = 0; j < sz; ++ j) block[i][j].second = readint();
	}
	int q = readint();
	int len = 0;
	while(q --) {
		int id = readint(); LL mul = readint();
		for(auto p : block[id]) {
			++ len;
			h[len] = p.first;
			c[len] = p.second * mul;
		}
	}
	assert(len == m);
}

void precalculate() {
	len = 0;
	for(int i = 1; i <= m; ++ i) {
		lb[i] = std::max(i - h[i] + 1, 1);
		while(len && lb[i] <= stk[len]) {
			chmin(lb[i], lb[stk[len]]);
			-- len;
		}
		stk[++ len] = i;
	}
	len = 0;
	for(int i = m; i >= 1; -- i) {
		rb[i] = std::min(i + h[i] - 1, m);
		while(len && stk[len] <= rb[i]) {
			chmax(rb[i], rb[stk[len]]);
			-- len;
		}
		stk[++ len] = i;
	}
	displaya(h, 1, m);
	displaya(c, 1, m);
	displaya(lb, 1, m);
	displaya(rb, 1, m);
}

LL solve() {
	f[0] = 0;
	for(int i = 1; i <= m; ++ i) {
		f[i] = f[lb[i] - 1] + c[i];
		while(len && rb[stk[len]] < i) -- len;
		if(len) chmin(f[i], f[stk[len] - 1] + c[stk[len]]);
		if(len == 0 || f[i - 1] + c[i] < f[stk[len] - 1] + c[stk[len]]) stk[++ len] = i;
	}
	return f[m];
}

int main() {
	initialize();
	precalculate();
	cout << solve() << endl;
	return 0;
}