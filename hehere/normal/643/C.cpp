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

const int maxN = 200000 + 233;
const double maxA = 1e5;
const double eps = 1e-4;
int n, k;
double a[maxN];
double s[maxN], t[maxN];
double f[maxN];
pair<double, double> line[maxN];
int p[maxN];

double gety(const pair<double, double> &A, double x) {
    return A.first * x + A.second;
}
double getx(const pair<double, double> &A, const pair<double, double> &B) {
    return - (A.second - B.second) / (A.first - B.first);
}

int main() {
    n = readint(); k = readint();
    s[0] = t[0] = 0;
    double base = 0;
    for(int i = 1; i <= n; ++i)
        a[i] = readint(),
        s[i] = s[i - 1] + a[i], t[i] = t[i - 1] + 1.0 / a[i],
        base += s[i] / a[i];
    for(int i = 0; i <= n; ++i) f[i] = 0;
    --k;
    while(k--) {
        int f = 0, r = 0;
        line[r++] = make_pair(0, 0);
        for(int i = 1; i <= n; ++i) {
            pair<double, double> newline(s[i], ::f[i] - s[i] * t[i]);
            while(f + 1 < r) {
                double y1 = gety(line[f], t[i]);
                double y2 = gety(line[f + 1], t[i]);
                if(y1 < y2) f++; else break;
            }
            // for(int x = f; x < r; ++x) chmax(::f[i], gety(line[x], t[i]));
            ::f[i] = gety(line[f], t[i]);
            while(f + 1 < r) {
                double x13 = getx(line[r - 2], newline);
                double x23 = getx(line[r - 1], newline);
                if(x13 > x23) --r; else break;
            }
            line[r++] = newline;
        }
        displaya(::f, 1, n);
    }
    printf("%.5lf\n", base - f[n]);
    return 0;
}