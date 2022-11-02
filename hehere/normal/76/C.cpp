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
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == n ? '}' : ',') << (qwq == n ? '\n' : ' '); }
#include <ctime>
class MyTimer {
  clock_t st;
public:
  MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
  ~MyTimer() { report(); }
  void reset() { st = clock_t(); }
  void report() {  cerr << "Time consumed :" << (clock() - st) * 1e3 / CLOCKS_PER_SEC << endl; }
} myTimer;
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
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

const int maxN = 200000 + 233;
const int maxK = 22;
int n, k, limit;
int post[maxK][maxN], a[maxK], f[1 << maxK], G[maxK][maxK];
pii p[maxK];
char s[maxN];

int main() {
  scanf("%d%d%d", &n, &k, &limit);
  scanf("%s", s);
  int occurrence = 0;
  for(int i = 0; i < n; ++i) occurrence |= 1 << (s[i] -= 'A');
  for(int i = 0; i < k; ++i) scanf("%d", &a[i]);
  for(int i = 0; i < k; ++i) for(int j = 0; j < k; ++j) scanf("%d", &G[i][j]);
  for(int t = 0; t < k; ++t) {
    post[t][n - 1] = n;
    for(int i = n - 2; i >= 0; --i) post[t][i] = s[i + 1] == t ? i + 1 : post[t][i + 1];
  }
  memset(f, 0, sizeof(f));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < k; ++j) p[j] = pii(post[j][i], j);
    std::sort(p, p + k);
    int S = 0;
    for(int j = 0; j < k; ++j) if(p[j].first < n && p[j].second != s[i]) {
      int val = G[(int)s[i]][p[j].second];
//      printf("consider (%d %d), with S = %d, val = %d\n", i, p[j].first, S, val);
      f[S] += val; f[S | (1 << s[i]) | (1 << p[j].second)] += val;
      f[S | (1 << s[i])] -= val; f[S | (1 << p[j].second)] -= val;
      S |= (1 << p[j].second);
    } else if(p[j].first < n) {
    	int val = G[(int)s[i]][(int)s[i]];
    	f[S] += val; f[S | (1 << s[i])] -= val;
    	S |= (1 << (int)s[i]);
		}
  }
  for(int i = 0; i < k; ++i)
    for(int S = 0; S < (1 << k); ++S)
      if(S >> i & 1)
        f[S] += f[S ^ (1 << i)];
  int ans = 0;
  for(int S = 0; S < (1 << k); ++S) if((occurrence & S) == S && occurrence - S) {
    int val = f[S];
    for(int i = 0; i < k; ++i) if(S >> i & 1) val += a[i];
    if(val <= limit) ++ans;
//    if(val <= limit) cout << S << " : " << val << endl;
  }
  cout << ans << endl;
  return 0;
}