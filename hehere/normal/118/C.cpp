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

const int maxN = 10000 + 5;
int n, K;
string s;
vector < pair<int, string> > v;
vector < int > pos[10];

int abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
  cin >> n >> K >> s;
  for(int i = 0; i < 10; ++i) pos[i].clear();
  for(int i = 0; i < n; ++i) pos[(int)(s[i] -= '0')].push_back(i);
  v.clear();
  for(int c = 0; c < 10; ++c) {
//  	printf("Round c = %d\n", c);
    string t = s;
    int cnt = pos[c].size(), val = 0;
    // if(pos[c].size() >= k) { v.push_back(std::make_pair(cnt, t)); }
    for(int i = c, j = c, k = 0; i >= 0 || j <= 9; ++k) {
      int p;
      if(k & 1) p = --i;
      else p = ++j;
      if(!(0 <= p && p <= 9)) continue;
//      printf("before p = %d, cnt = %d\n", p, cnt);
      if(k & 1) {
      	// a -> z
        for(int x = pos[p].size() - 1; x >= 0 && cnt < K; --x) {
//        	printf("Operate by c = %d, p = %d, x = %d, pos = %d\n", c, p, x, pos[p][x]);
        	t[pos[p][x]] = c; ++cnt; val += abs(c - p);
		}

      } else {
//      	 z -> a
//      	printf("size = %d\n", (int)pos[p].size());
        for(int x = 0; x < ((int)pos[p].size()) && cnt < K; ++x) {
//        	printf("x = %d\n", x);
//        	printf("Operate by c = %d, p = %d, x = %d, pos = %d\n", c, p, x, pos[p][x]);
        	t[pos[p][x]] = c; ++cnt; val += abs(c - p);
		}
      }
//      printf("after p = %d, cnt = %d\n", p, cnt);
    }
//    printf("for c = %d, val = %d\n", c, val);
    for(int i = 0; i < n; ++i) t[i] += '0';
//    cout << t << endl;
    v.push_back(std::make_pair(val, t));
  }
  std::sort(v.begin(), v.end());
  cout << v[0].first << endl << v[0].second << endl;
  return 0;
}