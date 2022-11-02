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
inline int readint() {
    int a = 0; char c = getchar(), p = 0;
    while(isspace(c)) c = getchar();
    if(c == '-') p = 1, c = getchar();
    while(isdigit(c)) a = a*10 + c - '0', c = getchar();
    return p ? -a : a;
}

const int maxN = 200000 + 233;
const int NODE = maxN * 40 + 60000;
//const int WIDTH = 23;
int n, m, q;
ULL data[NODE];
pii a[maxN]; int root[maxN];
int cnt = 0;

ULL encode(int x, int y, int z) {
    return (ULL)x << (23 + 18) | (ULL)y << 18 | (ULL)z;
}
void decode(ULL code, int &x, int &y, int &z) {
    z = code & ((1 << 18) - 1); code >>= 18;
    y = code & ((1 << 23) - 1); code >>= 23;
    x = code & ((1 << 23) - 1);
}
int getVal(ULL code) { return code & ((1 << 18) - 1); }
int ql, qr;
void add(int u, int &o, int L, int R) {
    if(L == R) { o = u + 1; return; }
    int lson, rson, val; decode(data[u], lson, rson, val);
    int nlson = lson, nrson = rson, nval = val;
    int M = (L + R) >> 1;
    int tag = val - std::min(L == M ? nlson : getVal(data[nlson]), M + 1 == R ? nrson : getVal(data[nrson]));
    o = ++cnt;
    if(ql <= L && R <= qr) {
        ++nval;
    } else {
        if(ql <= M) add(lson, nlson, L, M);
        if(qr > M) add(rson, nrson, M + 1, R);
        nval = std::min(L == M ? nlson : getVal(data[nlson]), M + 1 == R ? nrson : getVal(data[nrson])) + tag;
    }
    data[o] = encode(nlson, nrson, nval);
    // printf("So [%d, %d] has val = %d, while l = %d, r = %d\n", L, R, nval, getVal(data[nlson]), getVal(data[nrson]));
}
int query(int o, int L, int R) {
    if(o == 0) return 0;
    if(L == R) return o;
    int lson, rson, val; decode(data[o], lson, rson, val);
    int M = (L + R) >> 1, ans = maxN;
    int tag = val - std::min(L == M ? lson : getVal(data[lson]), M + 1 == R ? rson : getVal(data[rson]));
    // printf("[%d, %d]: val = %d, tag = %d, o = %d, data = %llX\n", L, R, val, tag, o, data[o]);
    if(ql <= L && R <= qr) {
        return val;
    } else {
        if(ql <= M) chmin(ans, query(lson, L, M) + tag);
        if(qr > M) chmin(ans, query(rson, M + 1, R) + tag);
        return ans;
    }
}

int main() {
    fprintf(stderr, "Memory: %.3lf\n", sizeof(data) / 1e6);
    n = readint(); m = readint();
    for(int i = 1; i <= n; ++i) a[i] = pii(readint(), i);
    std::sort(a + 1, a + n + 1);
    root[0] = cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int /*val = a[i].first, */pos = a[i].second;
        ql = std::max(1, pos - m + 1);
        qr = std::min(pos, n - m + 1);
        // qr = pos < n - m + 1 ? pos : n; // make it easier
        // fprintf(stderr, "Add 1 to [%d, %d]\n", ql, qr);
        add(root[i - 1], root[i], 1, n - m + 1);
        if(NODE - cnt < 50) fprintf(stderr, "i = %d, cnt = %d\n", i, cnt), assert(false);
    }
    // displaya(a, 1, n);
    q = readint();
    int lastans = 0;
    while(q--) {
        ql = readint(), qr = readint();
        int val = readint() ^ lastans;
        int p = std::lower_bound(a + 1, a + n + 1, pii(val, 0)) - a;
        --p; // display(p);
        int rt = root[p];
        printf("%d\n", lastans = query(rt, 1, n - m + 1));
    }
    return 0;
}