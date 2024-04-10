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
#include <string>
#include <sstream>
#include <utility>
#include <vector>
typedef unsigned int U;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) if(qwq == (st)) cerr << a[qwq]; else cerr << ", " << a[qwq];\
      cerr << "}" << endl; }
#define displayv(a) displaya(a, 0, (int)(a.size()-1))
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
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
#define displayv(a) {}
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

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
inline LL readLL() {
  LL a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 50000 + 233;
const int maxB = 1000000000 + 233;
const int maxM = 100;
const LL P = 1000000007;
int n, b, k, m;
struct Matrix {
  LL val[maxM][maxM];
  LL* operator [](const int index) {
    return val[index];
  }
  Matrix() {
    memset(val, 0, sizeof(val));
  }
  static Matrix Identity(int m) {
    Matrix r;
    for(int i = 0; i < m; ++i) r[i][i] = 1;
    return r;
  }
  friend Matrix operator * (Matrix &A, Matrix &B) {
    Matrix R;
    for(int i = 0; i < m; ++i)
      for(int k = 0; k < m; ++k)
      	for(int j = 0; j < m; ++j)
          R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % P;
    return R;
  }
}A[32];

int main() {
  n = readint(); b = readint(); k = readint(); m = readint();
  static int buc[maxM]; memset(buc, 0, sizeof(buc));
  for(int i = 0; i < n; ++i) {
    buc[readint() % m]++;
  }
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < m; ++j)
      A[0][(j * 10 + i) % m][j] += buc[i];
  for(int k = 1; k < 32; ++k) A[k] = A[k - 1] * A[k - 1];
//  for(int i = 0; i < m; ++i) displaya(A[0][i], 0, m - 1);
//  for(int i = 0; i < m; ++i) displaya(A[1][i], 0, m - 1);
  static LL f[maxN], g[maxN];
  memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
  f[0] = 1;
  for(int t = 0; t < 32; ++t) if(b >> t & 1) {
    memcpy(g, f, sizeof(f));
    memset(f, 0, sizeof(f));
    for(int i = 0; i < m; ++i) for(int j = 0; j < m; ++j)
      f[i] = (f[i] + g[j] * A[t][i][j]) % P;
  }
  printf("%lld\n", f[k] % P);
  return 0;
}