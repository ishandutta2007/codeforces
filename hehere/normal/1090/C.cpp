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
#ifdef QUICK_READ
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
int n, m;
int size[maxN];
set<pii> S;

const int NODE = 500000 * 20 * 2;
int cnt = 0;
int root[maxN];
int sum[NODE], lson[NODE], rson[NODE];

void add(int &o, int L, int R, int val) {
    if(o == 0) o = ++cnt, sum[o] = lson[o] = rson[o] = 0;
    sum[o]++;
    if(L == R) {
        // nothing to do
    } else {
        int M = (L + R) >> 1;
        if(val <= M) add(lson[o], L, M, val);
        else add(rson[o], M + 1, R, val);
    }
}

int pos = -1;
void move(int &x, int &y, int L, int R) {
    // printf("move: [%d, %d], sum = %d, %d\n", L, R, sum[x], sum[y]);
    if(x == 0) x = ++cnt;
    assert(y);
    if(y == 0) y = ++cnt;
    sum[x]++; sum[y]--;
    if(L == R) {
        pos = L;
    } else {
        int M = (L + R) >> 1;
        if(sum[lson[x]] < sum[lson[y]]) move(lson[x], lson[y], L, M);
        else move(rson[x], rson[y], M + 1, R);
    }
}

int len, optx[500000 + 233], opty[500000 + 233], optv[500000 + 233];

int main() {
    n = readint(); m = readint();
    memset(root, 0, sizeof(root));
    for(int i = 1; i <= n; ++i) {
        int c = readint(); S.emplace(c, i); size[i] = c;
        while(c--) add(root[i], 1, m, readint());
    }
    len = 0;
    while(S.begin()->first + 2 <= S.rbegin()->first) {
        int x = S.begin()->second; S.erase(S.begin());
        int y = S.rbegin()->second; S.erase(*S.rbegin());
        size[x]++; size[y]--;
        pos = -1;
        move(root[x], root[y], 1, m);
        assert(pos != -1);
        ++len; optx[len] = y; opty[len] = x; optv[len] = pos;
        S.insert(pii(size[x], x)); S.insert(pii(size[y], y));
    }
    printf("%d\n", len);
    for(int i = 1; i <= len; ++i) printf("%d %d %d\n", optx[i], opty[i], optv[i]);
    return 0;
}