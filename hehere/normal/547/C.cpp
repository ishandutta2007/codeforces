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

const int maxN = 200000 + 233;
const int maxA = 500000 + 233;
int n, q, a[maxN];
int mu[maxA], phi[maxA];
bool c[maxN];
int cnt[maxA];
vector<int> d[maxA];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    n = readint(); q = readint();
    for(int i = 1; i <= n; ++i) a[i] = readint();
    for(int i = 1; i < maxA; ++i)
        for(int j = i; j < maxA; j += i)
            d[j].push_back(i);
    for(int i = 1; i < maxA; ++i) mu[i] = (i == 1);
    for(int i = 2; i < maxA; ++i)
        for(int j : d[i]) if(j < i) mu[i] -= mu[j];
    for(int i = 1; i < maxA; ++i) phi[i] = i;
    for(int i = 1; i < maxA; ++i)
        for(int j : d[i]) if(j < i) phi[i] -= phi[j];
    memset(c, 0, sizeof(c));
    LL ans = 0;
    while(q--) {
        int pos = readint();
        int x = a[pos];
        if(c[pos]) {
            c[pos] = false;
            ans += (x == 1);
            for(int j : d[x]) cnt[j]--, ans -= mu[j] * (2LL * cnt[j] + 1LL);
        } else {
            c[pos] = true;
            ans -= (x == 1);
            for(int j : d[x]) ans += mu[j] * (2LL * cnt[j] + 1LL), cnt[j]++;
        }
        printf("%lld\n", ans / 2);
    }
    return 0;
}