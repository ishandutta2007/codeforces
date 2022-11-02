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
using std::endl; using std::map;
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

const int maxN = 100000 + 233;
const int maxQ = 1000000 + 233;
const int maxA = 7001;
using bitset = std::bitset<maxA>;
int n, q, mu[maxA];
bitset a[maxN];
bitset divisors[maxA], mul[maxA];

int main() {
    n = readint(); q = readint();
    memset(mu, 0, sizeof(mu));
    mu[1] = 1;
    for(int i = 1; i < maxA; ++i) {
        for(int j = i * 2; j < maxA; j += i)
            mu[j] -= mu[i];
    }
    for(int i = 1; i < maxA; ++i) {
        for(int j = i; j < maxA; j += i)
            divisors[j][i] = 1, mul[i][j] = (mu[j / i] != 0);
    }
    static char qaq[maxQ]; int len = 0;
    while(q--) {
        int op = readint();
        if(op == 1) {
            int x = readint(), v = readint();
            a[x] = divisors[v];
        } else if(op == 2) {
            int x = readint(), y = readint(), z = readint();
            a[x] = a[y] ^ a[z];
        } else if(op == 3) {
            int x = readint(), y = readint(), z = readint();
            a[x] = a[y] & a[z];
        } else if(op == 4) {
            int x = readint(), v = readint();
            int ans = (a[x] & mul[v]).count();
            qaq[len++] = '0' + (ans & 1);
        }
    }
    qaq[len] = 0;
    printf("%s\n", qaq);
    return 0;
}