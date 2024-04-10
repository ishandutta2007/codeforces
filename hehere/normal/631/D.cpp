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
int n, m;
char s[maxN], t[maxN];
LL cs[maxN], ct[maxN];

void read(int &n, char *s, LL *cs) {
  s[0] = 0;
  for(int i = 0; i < n;) {
    char c; LL cc;
    scanf("%lld-%c", &cc, &c);
    if(c == s[i]) { --n; cs[i] += cc; }
    else { ++i; s[i] = c; cs[i] = cc; }
  }
  s[n + 1] = 0;
}

bool spj() {
  if(n == 1) {
    LL ans = 0;
//    for(int i = 1; i <= n; ++i) printf("(%lld, %c) ", cs[i], s[i]);
//    for(int i = 1; i <= m; ++i) printf("(%lld, %c) ", ct[i], t[i]);
    for(int i = 1; i <= m; ++i) {
      if(t[i] == s[1] && ct[i] >= cs[1])
        ans += ct[i] - cs[1] + 1;
//        cout << ct[i] - cs[1] + 1 << endl;
    }
    cout << ans << endl;
    return true;
  } else if(n > m) {
    cout << 0 << endl;
    return true;
  }
  return false;
}

/*
20 10
123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b
123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b 123-a 123-b

20 10
1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b
1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b 1-a 1-b
*/

int z[maxN*2];
LL str[maxN*2];
void init_z(int n) {
	memset(z, 0, sizeof(z));
//	for(int i = 0; i < n; ++i) printf("%lld ", str[i]); cout << endl;
	int L = 0, R = 0;
	for(int i = 1; i < n; ++i) {
		int &len = z[i];
		len = i > R ? 0 : std::min(z[i - L], R - i + 1);
		while(i + len < n && str[i + len] == str[len]) ++len;
		if(chmax(R, i + len - 1)) L = i;
	}
//	for(int i = 0; i < n; ++i) cout << str[i] << " "; cout << endl;
//	for(int i = 0; i < n; ++i) cout << z[i] << " "; cout << endl;
}

int main() {
  scanf("%d%d", &m, &n);
  read(m, t, ct); read(n, s, cs);
  if(spj()) return 0;
  int p = 0;
  for(int i = 2; i <= n - 1; ++i) str[p++] = ((LL)cs[i]*1000LL) + (LL)s[i];
  str[p++] = -2;
  for(int i = 1; i <= m; ++i) str[p++] = ((LL)ct[i]*1000LL) + (LL)t[i];
  str[p++] = -1;
  init_z(p);
  p -= m + 1;
  for(int i = 1; i <= m; ++i) z[i] = z[p++];
  LL ans = 0;
  for(int i = 1; i <= m - n + 1; ++i) {
  	if(t[i] == s[1] && ct[i] >= cs[1]
        && z[i + 1] == n - 2
        && t[i + n - 1] == s[n]
        && ct[i + n - 1] >= cs[n])
      ++ans;
//   cout << (t[i] == s[1]) << (ct[i] >= cs[1])
//       << (z[i + 1] == n - 2)
//       << (t[i + n - 1] == s[n])
//       << (ct[i + n - 1] >= cs[n]) << endl;
  }
  cout << ans << endl;
  return 0;
}