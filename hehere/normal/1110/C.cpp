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

const int maxQ = 1000 + 23;
const int maxA = 1 << 25;
int q;
map<int, int> M = {
pii(3, 1),
pii(7, 1),
pii(15, 5),
pii(31, 1),
pii(63, 21),
pii(127, 1),
pii(255, 85),
pii(511, 73),
pii(1023, 341),
pii(2047, 89),
pii(4095, 1365),
pii(8191, 1),
pii(16383, 5461),
pii(32767, 4681),
pii(65535, 21845),
pii(131071, 1),
pii(262143, 87381),
pii(524287, 1),
pii(1048575, 349525),
pii(2097151, 299593),
pii(4194303, 1398101),
pii(8388607, 178481),
pii(16777215, 5592405),
pii(33554431, 1082401)};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
//    for(int i = 2; i <= 25; ++ i) {
//        int x = (1 << i) - 1;
//        int ans = 0;
//        for(int y = 1; y < x; ++y) chmax(ans, gcd(x ^ y, x & y));
//        printf("pii(%d, %d),\n", x, ans);
//    }
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(M.count(x)) cout << M[x] << endl;
        else {
            auto i = M.upper_bound(x);
            cout << i->first << endl;
        }
    }
    return 0;
}