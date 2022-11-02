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

const int maxN = 2000 + 5;
const LL P = 998244353;
int n, a[maxN][maxN];
LL f[maxN][maxN];
LL p[maxN], fac[maxN];

struct FenwickTree {
    int C[maxN];
    void clear() {
        for(int i = 0; i <= n; ++i) C[i] = 0;
    }
    void add(int p, int x) {
        for(; p <= n; p += p & -p) C[p] += x;
    }
    int sum(int p) {
        int r = 0;
        for(; p > 0; p -= p & -p) r += C[p];
        return r;
    }
} tx, ty;
/*
5
1 2 3 5 4
2 1 4 3 5
1 3 2 5 4
2 3 1 4 5
1 5 4 2 3
3752109
*/

int main() {
    n = readint();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = readint();
    f[0][0] = 1; f[1][0] = 0; f[2][0] = 1;
    for(int i = 1; i <= n; ++i) {
        if(i > 2)
            f[i][0] = (i - 1) * (f[i - 1][0] + f[i - 2][0]) % P;
        for(int j = 1; j <= i; ++j)
            f[i][j] = (j * f[i - 1][j - 1] + (i - j) * f[i - 1][j]) % P;
    }
    p[0] = 1; fac[0] = 1;
    for(int i = 1; i <= n; ++i) p[i] = p[i - 1] * f[n][0] % P, fac[i] = fac[i - 1] * i % P;
    LL ans = 0;
    tx.clear();
    for(int j = 1; j <= n; ++j) ans = (ans + (a[1][j] - 1 - tx.sum(a[1][j] - 1)) * fac[n - j] % P * p[n - 1]) % P, tx.add(a[1][j], 1);
    static int posA[maxN], posB[maxN], k[maxN];
    static vector<int> x[maxN], y[maxN];
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) posA[a[i - 1][j]] = j, posB[a[i][j]] = j;
        for(int j = 1; j <= n; ++j) k[j] = 0; tx.clear(); ty.clear();
        for(int j = 1; j <= n; ++j) x[j].clear(), y[j].clear();
        for(int v = 1; v <= n; ++v) {
            int lim = std::min(posA[v], posB[v]);
            y[1].push_back(v); y[lim].push_back(-v);
            if(posA[v] <= posB[v])
                k[posA[v]]++, k[posB[v] + 1]--;
            if(posA[v] < posB[v])
                x[posA[v] + 1].push_back(v), x[posB[v]].push_back(-v);
        }
        for(int j = 1; j <= n; ++j) k[j] += k[j - 1];
        for(int j = 1; j <= n; ++j) {
            for(int t : x[j]) if(t > 0) tx.add(t, 1); else tx.add(-t, -1);
            for(int t : y[j]) if(t > 0) ty.add(t, 1); else ty.add(-t, -1);
            int x = tx.sum(a[i][j] - 1), y = ty.sum(a[i][j] - 1);
            ans = (ans + ((x == 0 ? 0 : x * f[n - j][k[j] - 1]) + y * f[n - j][k[j]]) % P * p[n - i]) % P;
        }
    }
    printf("%lld\n", ans % P);
    return 0;
}