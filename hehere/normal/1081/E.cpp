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
const int DIV = 80;
int n;
LL a[maxN];
vector<pii> f[maxN];
vector<int> p[maxN];

void factorize(int n, vector<pii> &res) {
    res.clear();
    for(int x = 1; x * x < n; ++x) if(n % x == 0) {
        int y = n / x;
        if((x & 1) != (y & 1)) continue;
        res.emplace_back((y - x) / 2, (x + y) / 2);
    }
}

int main() {
    n = readint();
    for(int i = 2; i <= n; i += 2) {
        a[i] = readint();
        factorize(a[i], f[i]);
        p[i] = vector<int>(f[i].size(), (i == 2 ? 233 : -1));
    }
    for(int i = 2; i < n; i += 2) {
        int k = -1;
        for(int j = 0; j < (int)f[i].size(); ++j) if(p[i][j] != -1) {
            while(k + 1 < (int)f[i + 2].size() && f[i + 2][k + 1].first > f[i][j].second) ++k;
            if(k >= 0 && f[i + 2][k].first > f[i][j].second)
                p[i + 2][k] = j;
        }
//        printf("size = %d\n", (int)f[i + 2].size());
        for(int k = (int)f[i + 2].size() - 1; k - 1 >= 0; --k) if(p[i + 2][k] != -1)
            p[i + 2][k - 1] = p[i + 2][k];
    }
//    for(int i = 2; i <= n; i += 2) {
//        for(int j = 0; j < (int)f[i].size(); ++j) printf("(%d, %d, %d) ", p[i][j], f[i][j].first, f[i][j].second);
//        printf("\n");
//    }
    int pos = 0;
    for(int k = 0; k < (int)f[n].size(); ++k) if(p[n][k] != -1) pos = k;
    if(p[n].size() == 0 || p[n][pos] == -1) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for(int i = n; i > 2; pos = p[i][pos], i -= 2) {
            a[i - 1] = f[i][pos].first * (LL)f[i][pos].first
                - f[i - 2][p[i][pos]].second * (LL)f[i - 2][p[i][pos]].second;
        }
        a[1] = f[2][pos].first * (LL)f[2][pos].first;
        for(int i = 1; i <= n; ++i) printf("%lld%c", a[i], " \n"[i == n]);
    }
    return 0;
}