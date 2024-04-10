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

const int maxN = 2000 + 5;
int n, cnt;
int l[maxN], r[maxN];
int f[maxN * 2][maxN * 2];
vector<pii> segs[maxN * 2];

vector<int> res;
void print(int l, int r) {
//	printf("print(%d, %d)\n", l, r);
  if(l == r) return;
  int p = -1;
  int basis = 0;
  for(int i = 0; i < (int)segs[l].size() && segs[l][i].first <= r; ++i) {
    int j = i;
    for(; j < (int)segs[l].size() && segs[l][i].first == segs[l][j].first; ++j);
    --j;
    if(segs[l][i].first == r) {
      basis = j - i + 1;
      for(int k = i; k <= j; ++k) res.push_back(segs[l][k].second);
//      for(int k = i; k <= j; ++k) printf("%d ", segs[l][k].second); printf("\n");
    }
    else if(p == -1 || f[l][p] + f[p][r] < f[l][segs[l][i].first] + f[segs[l][i].first][r]) p = segs[l][i].first;
    i = j;
  }
  f[l][r] -= basis;
  if(p != -1 && f[l][r] == f[l][p] + f[p][r]) {
//		printf("print(%d, %d) -> %d\n", l, r, p);
  	print(l, p); print(p, r);
		return;
	}
  if(f[l][r - 1] == f[l][r]) print(l, r - 1);
  else if(f[l + 1][r] == f[l][r]) print(l + 1, r);
  else assert(false);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int x, y; cin >> x >> y;
    l[i] = x - y; r[i] = x + y;
  }
  vector<int> dis; dis.reserve(n * 2);
  for(int i = 1; i <= n; ++i)
    dis.push_back(l[i]), dis.push_back(r[i]);
  std::sort(dis.begin(), dis.end());
  dis.erase(std::unique(dis.begin(), dis.end()), dis.end());
  cnt = dis.size();
  for(int i = 1; i <= n; ++i) {
    int x = std::lower_bound(dis.begin(), dis.end(), l[i]) - dis.begin() + 1,
        y = std::lower_bound(dis.begin(), dis.end(), r[i]) - dis.begin() + 1;
  	segs[x].push_back(pii(y, i));
	}
  for(int i = 1; i <= cnt; ++i) std::sort(segs[i].begin(), segs[i].end());
  memset(f, 0, sizeof(f));
  for(int k = 1; k < cnt; ++k)
    for(int l = 1, r = l + k; r <= cnt; ++l, ++r) {
      f[l][r] = std::max(f[l][r - 1], f[l + 1][r]);
      int basis = 0;
      for(int i = 0; i < (int)segs[l].size() && segs[l][i].first <= r; ++i) {
        int j = i;
        for(; j < (int)segs[l].size() && segs[l][i].first == segs[l][j].first; ++j);
        --j;
        if(segs[l][i].first == r) basis = j - i + 1;
        else chmax(f[l][r], f[l][segs[l][i].first] + f[segs[l][i].first][r]);
        i = j;
      }
      f[l][r] += basis;
    }
//  for(int i = 1; i <= cnt; ++i) {
//  	for(int j = i; j <= cnt; ++j) printf("%d ", f[i][j]);
//  	printf("\n");
//	}
  cout << f[1][cnt] << endl;
  res.clear(); res.reserve(f[1][cnt]);
  print(1, cnt);
  std::sort(res.begin(), res.end());
  for(int x : res) cout << x << " "; cout << endl;
  return 0;
}