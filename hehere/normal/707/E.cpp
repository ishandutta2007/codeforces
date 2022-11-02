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
  while(!isdigit(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 2000 + 5;
const int maxK = 2000 + 5;
const int maxQ = 1000000 + 233;
int n, m, k, q;
vector< pair<pii, LL> > gar[maxK];
struct Query {
  int x1, y1, x2, y2;
  int t, id;
}qs[maxQ];
vector<int> indices;
LL con[maxN][maxN];
LL C[maxN][maxN];
void modify(int x, int y, LL val) {
  for(int i = x; i <= n; i += i & -i)
    for(int j = y; j <= m; j += j & -j)
      C[i][j] += val;
}
LL sum(int x, int y) {
  LL r = 0;
  for(int i = x; i > 0; i -= i & -i)
    for(int j = y; j > 0; j -= j & -j)
      r += C[i][j];
  return r;
}
char active[maxK];

int main() {
  n = readint(); m = readint(); k = readint();
  for(int i = 1; i <= k; ++i) {
    int len = readint();
    gar[i].reserve(len);
    for(int j = 1; j <= len; ++j) {
      int x = readint(), y = readint(), w = readint();
      gar[i].push_back(make_pair(pii(x, y), w));
    }
  }
  q = readint();
  for(int i = 0; i < q; ++i) {
    char c = getchar();
    while(c != 'S' && c != 'A') c = getchar();
    if(c == 'S') {
      qs[i].t = 0; qs[i].id = readint();
    } else {
      qs[i].t = 1;
      qs[i].x1 = readint(); qs[i].y1 = readint();
      qs[i].x2 = readint(); qs[i].y2 = readint();
      indices.push_back(i);
      qs[i].id = indices.size() - 1;
    }
  }
  memset(C, 0, sizeof(C));
  for(int i = 1; i <= k; ++i) {
    for(auto p : gar[i]) modify(p.first.first, p.first.second, p.second);
    for(int j = 0; j < (int)indices.size(); ++j) {
      Query &p = qs[indices[j]];
//      printf("query %d: %d %d %d %d\n", indices[j], p.x1, p.y1, p.x2, p.y2);
      con[i][j] = sum(p.x2, p.y2) - sum(p.x1 - 1, p.y2) - sum(p.x2, p.y1 - 1) + sum(p.x1 - 1, p.y1 - 1);
		}
    for(auto p : gar[i]) modify(p.first.first, p.first.second, -p.second);
  }
  for(int i = 1; i <= k; ++i) active[i] = 1;
  for(int i = 0; i < q; ++i) {
    if(qs[i].t == 0) active[qs[i].id] ^= 1;
    else {
      LL tot = 0;
      for(int j = 1; j <= k; ++j) if(active[j]) {
//      	printf("%d remains active\n", j);
        tot += con[j][qs[i].id];
      }
      printf("%lld\n", tot);
    }
  }
  return 0;
}
/*
8 7 4
36
3 2 1
3 3 1
4 3 1
4 2 1
5 2 1
5 3 1
6 3 1
6 2 1
7 2 1
7 3 1
8 3 1
8 4 1
7 4 1
7 5 1
8 5 1
8 6 1
7 6 1
7 7 1
6 7 1
6 6 1
5 6 1
5 7 1
4 7 1
4 6 1
3 6 1
3 7 1
2 7 1
2 6 1
1 6 1
1 5 1
2 5 1
2 4 1
1 4 1
1 3 1
2 3 1
2 2 1
4
3 4 1
3 5 1
4 5 1
4 4 1
4
5 5 1
5 4 1
6 4 1
6 5 1
8
1 1 1
2 1 1
3 1 1
4 1 1
5 1 1
6 1 1
7 1 1
8 1 1
6
ASK 4 1 5 7
ASK 2 3 7 6
SWITCH 2
ASK 2 3 7 6
SWITCH 3
ASK 2 3 7 6

*/