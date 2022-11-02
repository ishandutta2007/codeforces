#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef LOCAL
#include <ctime>
void displayTime() { cout << "Current time = " << clock() * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
#else
void displayTime() {}
#endif
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[i] << (qwq == n ? ' ' : '\n'); }
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
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

const int maxN = 100000 + 233;
int n, m;
struct Point {
  LL x, y;
  int id;
  friend bool operator == (const Point &A, const Point &B) {
    return A.x == B.x && A.y == B.y;
  }
  friend bool operator != (const Point &A, const Point &B) {
    return A.x != B.x || A.y != B.y || A.id != B.id;
  }
  friend bool operator < (const Point &A, const Point &B) {
    return A.x != B.x ? A.x < B.x : A.y > B.y;
  }
  void print() const {
  	printf("(#%d, %lld, %lld) ", id, x, y);
  }
}p[maxN*2], pa[maxN*2], pb[maxN*2];
int la, lb;
struct Vector {
  LL x, y;
};
Vector operator - (Point A, Point B) {
  return (Vector){A.x - B.x, A.y - B.y};
}
LL Cross(Vector A, Vector B) {
  return A.x * B.y - A.y * B.x;
}

bool cmp1(const Point &A, const Point &B) {
  return A.x != B.x ? A.x < B.x : A.y != B.y ? A.y < B.y : A.id > B.id;
}
bool cmp2(const Point &A, const Point &B) {
  return A.x != B.x ? A.x > B.x : A.y != B.y ? A.y > B.y : A.id > B.id;
}

void getConvexHull(Point *p, int n, int &m, Point *stk) {
//  for(int i = 0; i <= n; ++i) p[i].print(); printf("\n");
  m = 0;
  for(int kase = 1; kase <= 2; ++kase) {
    std::sort(p, p + n + 1, kase == 1 ? cmp1 : cmp2);
    for(int i = 0; i <= n; ++i) {
      while((m && p[i] == stk[m - 1] && stk[m - 1].id >= p[i].id) ||
        (m > 1 && Cross(p[i] - stk[m - 1], stk[m - 1] - stk[m - 2]) > 0))
        --m;
      stk[m++] = p[i];
    }
  }
  --m;
}

int main() {
  scanf("%d %d %*d %*d", &n, &m);
  p[0] = (Point){0LL, 0LL, 0};
  for(int i = 1; i <= n + m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    p[i] = (Point){(LL)x, (LL)y, i};
  }
  std::sort(p + n + 1, p + n + m + 1);
  LL mx = 0, my = 0;
  for(int i = n + 1; i <= n + m; ++i) chmax(mx, p[i].x), chmax(my, p[i].y);
  p[n + m + 1] = (Point){0LL, my, n + m + 1};
  p[n + m + 2] = (Point){mx, 0, n + m + 2};
  std::swap(p[0], p[n]);
  getConvexHull(p + n, m + 2, la, pa);
//  for(int i = 0; i < la; ++i) pa[i].print(); printf("\n");
  getConvexHull(p, n + m + 2, lb, pb);
//  for(int i = 0; i < lb; ++i) pb[i].print(); printf("\n");
  if(la != lb) { cout << "Max" << endl; return 0; }
  for(int i = 0; i < la; ++i) if(pa[i] != pb[i])
    { cout << "Max" << endl; return 0; }
  cout << "Min" << endl;
  return 0;
}