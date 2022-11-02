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

const int maxL = 5000 + 5;
const int maxN = maxL * 2;
int len1, len2, n;
char s1[maxL], s2[maxL], s[maxN];

int sa[maxN], rk[maxN], height[maxN];

int b1[maxN << 1], b2[maxN << 1];
int c[maxN << 1];
void construct(int m) {
  int *x = b1, *y = b2;
  for(int i = 0; i < m; ++i) c[i] = 0;
  for(int i = 0; i < n; ++i) ++c[x[i] = s[i]];
  for(int i = 1; i < m; ++i) c[i] += c[i - 1];
  for(int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for(int k = 1; k <= n; k <<= 1) {
    int p = 0;
    for(int i = n - k; i < n; ++i) y[p++] = i;
    for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;

    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) ++c[x[y[i]]];
    for(int i = 1; i < m; ++i) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];

    std::swap(x, y);
    p = 2; x[sa[0]] = 1;
    for(int i = 1; i < n; ++i)
      x[sa[i]] =
        y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]
          ? p - 1
          : p++;
    if(p > n) break;
    m = p;
  }

  for(int i = 0; i < n; ++i) rk[sa[i]] = i;
  for(int i = 0, k = 0; i < n; ++i) if(rk[i]) {
    if(k) k--;
    int j = sa[rk[i] - 1];
    while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  } else height[0] = k = 0;
}

int t[maxN];

int main() {
  scanf("%s%s", s1, s2);
  len1 = strlen(s1); len2 = strlen(s2);
  n = 0;
  for(int i = 0; i < len1; ++i) t[n] = 1, s[n++] = s1[i];
  // [0, len1)
  t[n] = 3; s[n++] = 'z' + 1;
  for(int i = 0; i < len2; ++i) t[n] = 2, s[n++] = s2[i];
  // [len1 + 1, len1 + 1 + len2)
  t[n] = 4; s[n++] = 'z' + 2;
  s[n] = 0;
  construct(128);
  height[n] = 0;
//  printf("%s\n", s);
//  for(int i = 0; i < n; ++i) printf("%d %d %s\n", t[sa[i]], height[i], s + sa[i]);
  int ans = 0x3f3f3f3f;
  for(int i = 0; i < n - 1; ++i) if(t[sa[i]] != t[sa[i + 1]] && t[sa[i]] < 3 && t[sa[i + 1]] < 3) {
    int h0 = height[i], h = height[i + 1], h1 = height[i + 2];
    int low = std::max(h0, h1) + 1;
    if(low <= h) ans = std::min(ans, low);
  }
  cout << (ans == 0x3f3f3f3f ? -1 : ans);
  return 0;
}