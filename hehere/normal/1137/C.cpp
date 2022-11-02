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

const int maxN = 100000 + 233;
const int maxD = 50;
int n, m, d;

vector<int> G[maxN], H[maxN];

int encode(int u, int x) {
	return u * d + x;
}
void decode(int code, int &u, int &x) {
	u = code / d; x = code % d;
}

int scc[maxN * maxD];
vector<int> stk;
int cnt = 0;
vector< vector<int> > comp;
void DFS1(int code) {
	scc[code] = true;
	int u, x; decode(code, u, x);
	for(int v : H[u]) {
		int to = encode(v, (x + d - 1) % d);
		if(!scc[to]) DFS1(to);
	}
	stk.push_back(code);
}

void DFS2(int code) {
	scc[code] = cnt;
	int u, x; decode(code, u, x);
	for(int v : G[u]) {
		int to = encode(v, (x + 1) % d);
		if(scc[to] == -1) DFS2(to);
	}
}

bool shown[maxN * maxD];
int f[maxN * maxD];
string open[maxN];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> d;
	for(int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		H[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i) cin >> open[i];
	memset(scc, 0, sizeof(scc));
	for(int u = 1; u <= n; ++u)
		for(int x = 0; x < d; ++x)
			if(!scc[encode(u, x)]) DFS1(encode(u, x));
	memset(scc, -1, sizeof(scc));
	cnt = 0;
	while(stk.size()) {
		if(scc[stk.back()] == -1) DFS2(stk.back()), ++cnt;
		stk.pop_back();
	}
	comp.assign(cnt, vector<int>());
	for(int u = 1; u <= n; ++u)
		for(int x = 0; x < d; ++x)
			comp[scc[encode(u, x)]].push_back(encode(u, x));
	memset(shown, 0, sizeof(shown));
	memset(f, 0, sizeof(f));
	for(auto &lst : comp) {
		int best = 0;
		int add = 0;
		for(int code : lst) {
			int u, x; decode(code, u, x);
//			eprintf("(%d, %d) ", u, x);
			for(int v : G[u]) { // no matter when inside SCC
				chmax(best, f[encode(v, (x + 1) % d)]);
			}
			if(open[u][x] == '1' && !shown[u]) add++, shown[u] = true;
		}
//		eprintf("\n");
		for(int code : lst) {
			int u, x; decode(code, u, x);
			f[code] = best + add;
			shown[u] = false;
		}
	}
	printf("%d\n", f[encode(1, 0)]);
	return 0;
}