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
#define displaya(a, st, n)                                                     \
  {                                                                            \
    cerr << #a << " = {";                                                      \
    for (int qwq = (st); qwq <= (n); ++qwq)                                    \
      if (qwq == (st))                                                         \
        cerr << a[qwq];                                                        \
      else                                                                     \
        cerr << ", " << a[qwq];                                                \
    cerr << "}" << endl;                                                       \
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
#ifndef LOCAL
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

const int maxN = 500000 + 233;
const int maxQ = 500000 + 233;
const LL maxD = 1000000000LL * maxN * 5;
int n, q;
vector< pair<int, LL> > G[maxN];
vector< pair<int, pii> > Q[maxN];
LL ans[maxQ];

LL d[maxN];

#define lson (o << 1)
#define rson (lson | 1)
LL min[maxN * 4], tag[maxN * 4];
void maintain(int o) {
	min[o] = std::min(min[lson], min[rson]);
}
void pushdown(int o) {
	if(tag[o]) {
		tag[lson] += tag[o]; min[lson] += tag[o];
		tag[rson] += tag[o]; min[rson] += tag[o];
		tag[o] = 0;
	}
}
void build(int o, int L, int R) {
	tag[o] = 0;
	if(L == R) {
		if(G[L].size() == 0) min[o] = d[L];
		else min[o] = maxD;
	} else {
		int M = (L + R) >> 1;
		build(lson, L, M);
		build(rson, M + 1, R);
		maintain(o);
	}
}
int ql, qr; LL qv;
void inc(int o, int L, int R) {
//    printf("inc(%lld): [%d, %d] on [%d, %d]\n", qv, ql, qr, L, R);
	if(ql <= L && R <= qr) {
		tag[o] += qv; min[o] += qv;
	} else {
		pushdown(o);
		int M = (L + R) >> 1;
		if(ql <= M) inc(lson, L, M);
		if(qr > M) inc(rson, M + 1, R);
		maintain(o);
	}
}
// qv = maxD
void query(int o, int L, int R) {
//    printf("query: [%d, %d] on [%d, %d]\n", ql, qr, L, R);
	if(ql <= L && R <= qr) {
		chmin(qv, min[o]);
	} else {
		pushdown(o);
		int M = (L + R) >> 1;
		if(ql <= M) query(lson, L, M);
		if(qr > M) query(rson, M + 1, R);
	}
}

int end[maxN];
void DFSPrepare(int u) {
	std::sort(G[u].begin(), G[u].end());
	end[u] = u;
	for(auto p : G[u]) {
		int v = p.first; LL w = p.second;
		d[v] = d[u] + w;
		DFSPrepare(v);
		end[u] = end[v];
	}
}

void DFS(int u) {
	for(auto p : Q[u]) {
		int i = p.first;
		ql = p.second.first; qr = p.second.second;
		qv = maxD;
		query(1, 1, n);
		ans[i] = qv + d[u];
	}
	for(pii p : G[u]) {
		int v = p.first; LL w = p.second;
		ql = v; qr = end[v]; qv = - 2 * w;
		inc(1, 1, n);
		DFS(v);
		ql = v; qr = end[v]; qv = + 2 * w;
		inc(1, 1, n);
	}
}

int main() {
	n = readint(); q = readint();
	display(n); display(q);
	for(int i = 2; i <= n; ++ i) {
		int p = readint(); LL z = readint();
		G[p].emplace_back(i, z);
	}
	for(int i = 1; i <= q; ++ i) {
		int x = readint(), l = readint(), r = readint();
		Q[x].emplace_back(i, pii(l, r));
	}
	d[1] = 0;
	DFSPrepare(1);
//	displaya(d, 1, n);
	build(1, 1, n);
	DFS(1);
	for(int i = 1; i <= q; ++ i) printf("%lld\n", ans[i]);
    return 0;
}