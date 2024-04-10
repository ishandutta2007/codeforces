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

const int maxN = 800;
const int maxD = 500;
const int maxS = 5000 + 1;
using bitset = std::bitset<maxS>;
int d, s, p[maxN];
bitset f[maxN][maxD];

void write(int n, int r, int s) {
    while(n--) {
        int good = -1;
        for(int t = 0; t < 10; ++t) {
            if(f[n][(r + d - t * p[n] % d) % d][s - t])
                { good = t; break; }
        }
        assert(good != -1);
        putchar('0' + good);
        r = (r + d - good * p[n] % d) % d;
        s -= good;
    }
    putchar(10);
}

int main() {
    cin >> d >> s;
    f[0][0][0] = true;
    p[0] = 1;
    for(int i = 1; i < maxN; ++i) p[i] = p[i - 1] * 10 % d;
    for(int i = 0; i + 1 < maxN; ++i) {
        if(i) { // try to report answer
            if(f[i][0][s]) {
                write(i, 0, s);
                return 0;
            }
        }
        for(int r = 0; r < d; ++r) {
            for(int t = 0; t < 10; ++t) {
                f[i + 1][(r + t * p[i]) % d] |= f[i][r] << t;
            }
        }
    }
    printf("-1\n");
    return 0;
}