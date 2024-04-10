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
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n;
vector<int> G[maxN];
LL a[maxN], f[maxN][2];

void DFS(int u, int fa) {
	f[u][0] = f[u][1] = 0;
	int cnt = 0;
	LL dif = INF;
	for(int v : G[u]) if(v != fa) {
		DFS(v, u);
		++ cnt;
		f[u][0] += f[v][0];
		f[u][1] += f[v][0];
		chmin(dif, f[v][1] - f[v][0]);
	}
	f[u][0] += std::min(dif + a[u], 0LL);
	f[u][1] += dif;
	if(cnt == 0) {
		f[u][0] = a[u];
		f[u][1] = 0;
	}
//	printf("%d: %lld %lld\n", u, f[u][0], f[u][1]);
}

set<int> ans;

int flg[maxN];
void dig(int u, int fa, int t) {
//	printf("%d digged with t = %d\n", u, t);
	int cnt = 0;
	LL sum = 0, dif = INF;
	for(int v : G[u]) if(v != fa) {
		++ cnt;
		sum += f[v][0];
		chmin(dif, f[v][1] - f[v][0]);
	}
	if(cnt == 0) {
		if(t & 1) ans.insert(u);
	} else {
		if(t & 1) {
			if(sum == f[u][0]) {
				for(int v : G[u]) if(v != fa) {
					flg[v] |= 1;
				}
			}
			if(sum + dif + a[u] == f[u][0]) {
				ans.insert(u);
				int cnt = (sum == f[u][0]);
				for(int v : G[u]) if(v != fa)
					cnt += (f[v][1] - f[v][0] == dif);
				for(int v : G[u]) if(v != fa) {
					if(f[v][1] - f[v][0] == dif)
						flg[v] |= 2;
					if(f[v][1] - f[v][0] != dif || cnt > 1)
						flg[v] |= 1;
				}
			}
		}
		if(t & 2) {
			assert(sum + dif == f[u][1]);
			int cnt = 0;
			for(int v : G[u]) if(v != fa)
				cnt += (f[v][1] - f[v][0] == dif);
			for(int v : G[u]) if(v != fa) {
				if(f[v][1] - f[v][0] == dif)
					flg[v] |= 2;
				if(f[v][1] - f[v][0] != dif || cnt > 1)
					flg[v] |= 1;
			}
		}
	}
	for(int v : G[u]) if(v != fa) dig(v, u, flg[v]);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = 1; i < n; ++ i) {
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, -1);
	printf("%lld", f[1][0]);
	memset(flg, 0, sizeof(flg));
	dig(1, -1, 1);
	printf(" %d\n", (int)ans.size());
	for(int x : ans) printf("%d ", x); printf("\n");
	return 0;
}