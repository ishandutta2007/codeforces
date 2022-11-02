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

const int maxN = 200000 + 233;
int n;
LL s, a[maxN];
LL ans = 0;
vector<int> v;

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> s;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int c1 = 0, c2 = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] < s) c1++;
    if(s < a[i]) c2++;
  }
  v.clear();
  if(c1 > n / 2) {
    for(int i = 1; i <= n; ++i) if(a[i] < s) v.push_back(s - a[i]);
    std::sort(v.begin(), v.end());
    for(int i = 0; i < (int)v.size() && c1 > n / 2; ++i) ans += v[i], --c1;
  }
  v.clear();
  if(c2 > n / 2) {
    for(int i = 1; i <= n; ++i) if(s < a[i]) v.push_back(a[i] - s);
    std::sort(v.begin(), v.end());
    for(int i = 0; i < (int)v.size() && c2 > n / 2; ++i) ans += v[i], --c2;
  }
  cout << ans << endl;
  return 0;
}