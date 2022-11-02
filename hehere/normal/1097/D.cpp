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

const int maxN = 100 + 5;
const LL P = 1000000007;
int k;
vector<pll> v;
LL inv[maxN];

void factorise(LL N) {
    for(LL i = 2; i * i <= N; ++i) if(N % i == 0) {
        int c = 0;
        while(N % i == 0) N /= i, ++c;
        v.emplace_back(i, c);
    }
    if(N > 1) v.emplace_back(N, 1);
}

LL ans = 0;
vector<LL> f[maxN];
void calc(int n) {
    if(f[n].size() > 0) return;
    f[n].assign(n + 1, 0);
    f[n][n] = 1;
    for(int c = 0; c < k; ++c) {
        for(int i = 0; i <= n; ++i) f[n][i] = f[n][i] * inv[i + 1] % P;
        for(int i = n - 1; i >= 0; --i) f[n][i] = (f[n][i] + f[n][i + 1]) % P;
    }
}
void DFS(int d, LL pr, LL val) {
//    printf("d = %d, pr = %lld, val = %lld\n", d, pr, val);
    if(d == (int)v.size()) {
        ans = (ans + pr * val) % P;
    } else {
//        display(v[d].second);
//        displayv(f[v[d].second]);
        for(int i = 0; i <= v[d].second; ++i) {
            DFS(d + 1, pr * f[v[d].second][i] % P, val);
            val = v[d].first * val % P;
        }
    }
}

int main() {
    LL N; cin >> N >> k;
    factorise(N);
    inv[1] = 1;
    for(int i = 2; i < maxN; ++i)
        inv[i] = (P - (P / i) * inv[P % i] % P) % P;
    for(pii p : v) calc(p.second);
    ans = 0;
    DFS(0, 1, 1);
    cout << (ans % P) << endl;
    return 0;
}