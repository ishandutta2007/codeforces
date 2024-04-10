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

const int maxN = 100000 + 233;
const LL maxA = 100000 + 233;
int n;
LL a[maxN], b[maxN];
vector<int> G[maxN];
LL ans[maxN];

struct Node {
    Node *lson, *rson;
    LL k, b;
    Node() : lson(nullptr), rson(nullptr), k(0), b(maxA * maxA * maxN) {}
    LL eval(LL x) {
        return k * x + b;
    }

    void add(LL L, LL R, LL K, LL B) {
        // (k, b) smaller at x = L
        if(K * L + B < k * L + b) {
            std::swap(K, k); std::swap(B, b);
        }
        if(L == R) return;
        if(K * R + B > k * R + b) return;
        LL M = L + (R - L) / 2;
        // if (k, b) smaller at x = M
        if(K * M + B > k * M + b) {
            if(rson == nullptr) rson = new Node();
            rson->add(M + 1, R, K, B);
        } else {
            if(lson == nullptr) lson = new Node();
            std::swap(K, k); std::swap(B, b);
            lson->add(L, M, K, B);
        }
    }

    LL query(LL L, LL R, LL x) {
        LL ans = eval(x);
//    	printf("[%lld, %lld]: k = %lld, b = %lld, eval(%lld) = %lld\n", L, R, k, b, x, eval(x));
        if(L < R) {
            LL M = L + (R - L) / 2;
            if(x <= M && lson) chmin(ans, lson->query(L, M, x));
            if(x > M && rson) chmin(ans, rson->query(M + 1, R, x));
        }
        return ans;
    }

};
Node* p[maxN];

Node* merge(Node* x, Node* y, LL L, LL R) {
    if(x == nullptr) return y;
    else if(y == nullptr) return x;
    if(L == R) {
        if(x->eval(L) > y->eval(L)) return x;
        else return y;
    }
    LL M = L + (R - L) / 2;
    x->lson = merge(x->lson, y->lson, L, M);
    x->rson = merge(x->rson, y->rson, M + 1, R);
    x->add(L, R, y->k, y->b);
    return x;
}

void DFS(int u, int fa) {
    int cnt = 0;
    for(int v : G[u]) if(v != fa) {
        ++ cnt;
        DFS(v, u);
        p[u] = merge(p[u], p[v], -maxA, maxA);
    }
    if(cnt == 0) ans[u] = 0;
    else {
//    	printf("query from u = %d\n", u);
    	ans[u] = p[u]->query(-maxA, maxA, a[u]);
	}
    if(p[u] == nullptr) p[u] = new Node();
    p[u]->add(-maxA, maxA, b[u], ans[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    for(int i = 1; i <= n; ++ i) cin >> b[i];
    for(int i = 1; i < n; ++ i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(p, 0, sizeof(p));
    DFS(1, -1);
    for(int u = 1; u <= n; ++ u) printf("%lld%c", ans[u], " \n"[u == n]);
    return 0;
}