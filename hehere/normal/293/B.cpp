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
using std::pair; using std::make_pair;
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
#define displaya(a, st, n) { cerr << #a << " = {"; for(int qwq = (st); qwq <= (n); ++qwq) { cerr << a[qwq]; if(qwq < n) cerr << ", "; else cerr << "}" << endl; } }
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

const int maxN = 10 + 2;
const int maxK = 10 + 2;
const LL P = 1000000007;
int n, m, k;
int a[maxN][maxN];
int pre[maxN][maxN], post[maxN][maxN];
int cnt[maxK];

LL A[maxK][maxK];
int tot = 0, c0 = 0;

bool initialize() {
  if(n + m - 1 > k) return true;
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(--a[i][j] >= 0) ++cnt[a[i][j]];
  for(int i = 0; i <= n + 1; ++i) for(int j = 0; j <= m + 1; ++j)
    pre[i][j] = post[i][j] = (1 << k) - 1;
  for(int i = n; i >= 1; --i) for(int j = m; j >= 1; --j) {
  	if(a[i][j] >= 0 && !(post[i + 1][j] & post[i][j + 1] & (1 << a[i][j]))) return /*printf("%d %d\n", i, j),*/ true;
  	if(a[i][j] >= 0) post[i][j] = post[i + 1][j] & post[i][j + 1] & ~(1 << a[i][j]);
  	else post[i][j] = post[i + 1][j] & post[i][j + 1];
  }
  for(int i = 0; i < k; ++i) tot += (cnt[i] == 0);
  for(int i = 0; i < maxK; ++i) {
  	for(int j = 0; j <= i; ++j) {
  		LL &r = A[i][j]; r = 1;
  		for(int t = i; t >= i - j + 1; --t) r = r * t % P;
	  }
  }
  return false;
}

void print() {
  	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

LL ans = 0;

void inc(LL &a, const LL &b) {
	(a += b) >= P ? a -= P : a;
}

void dfs(int x, int y) {
  if(y == m + 1) ++x, y = 1;
  if(x > n) {
//  	print();
  	inc(ans, A[tot][c0]);
//  	fprintf(stderr, "A[%d][%d] = %lld\n", tot, c0, A[tot][c0]);
    return;
  }
  int S = (pre[x][y] = pre[x - 1][y] & pre[x][y - 1]) & post[x + 1][y] & post[x][y + 1];
//  printf("S = %d on (%d, %d)\n", S, x, y);
//  getchar();
  if(a[x][y] >= 0) { pre[x][y] &= ~(1 << a[x][y]); if(S >> a[x][y] & 1) dfs(x, y + 1); return; }
  bool f = false;
  int pp = pre[x][y];
//  if(x == 2 && y == 3) {
//  	displaya(cnt, 0, k - 1);
//  	display(c0);
//  	print();
//  	printf("S = %d\n", S);
//  	cout << endl;
//  	getchar();
//  }
  for(int c = 0; c < k; ++c) if((S >> c) & 1) {
    if(!cnt[c]) { if(f) continue; else ++c0, f = true; }
    pre[x][y] = pp & ~(1 << c);
    cnt[c]++;
//    a[x][y] = c;
//    printf("put %d on (%d, %d)\n", c, x, y);
    dfs(x, y + 1);
//    a[x][y] = -1;
	cnt[c]--;
	if(cnt[c] == 0) --c0;
  }
  pre[x][y] = pp;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  if(initialize()) { cout << 0 << endl; return 0; }
  ans = 0;
//  print();
  dfs(1, 1);
//  cout << endl;
  cout << ans % P << endl;
  return 0;
}