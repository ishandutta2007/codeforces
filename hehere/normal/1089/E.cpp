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

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
  return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

int n;

vector<pii> p;

void solve(int n) {
	int o = n;
  p.emplace_back(1, 1);
  while(n > 2) {
    --n;
    if(p.back().first & 1) {
      if(p.back().second == 8) p.emplace_back(p.back().first + 1, p.back().second);
      else p.emplace_back(p.back().first, p.back().second + 1);
    } else {
      if(p.back().second == 1) p.emplace_back(p.back().first + 1, p.back().second);
      else p.emplace_back(p.back().first, p.back().second - 1);
    }
  }
  if(p.back().second == 8) {
	  if(o < 57)
	  	p.emplace_back(p.back().first + 1, p.back().second);
	  else {
	  	int s = p.size(); std::swap(p[s - 1], p[s - 2]);
	  	p.emplace_back(8, p.back().second);
		}
	} else {
		p.emplace_back(8, p.back().second);
	}
  p.emplace_back(8, 8);
}

void special(int n) {
  p.emplace_back(1, 1);
  for(int i = 1; i <= 47; ++i) {
    if(p.back().first & 1) {
      if(p.back().second == 8) p.emplace_back(p.back().first + 1, p.back().second);
      else p.emplace_back(p.back().first, p.back().second + 1);
    } else {
      if(p.back().second == 1) p.emplace_back(p.back().first + 1, p.back().second);
      else p.emplace_back(p.back().first, p.back().second - 1);
    }
  }
  p.emplace_back(7, 1); p.emplace_back(8, 1);
  p.emplace_back(8, 2); p.emplace_back(7, 2);
  p.emplace_back(7, 8);
  n -= 47 + 5;
  while(1) {
    if(p.back().first == 7 && n == 2) break;
    if(p.back().first == 8 && n == 1) break;
    --n;
    if(p.back().first == 7) {
      if(p.back().second == 3) p.emplace_back(8, 3);
      else p.emplace_back(7, p.back().second - 1);
    } else {
      p.emplace_back(p.back().first, p.back().second + 1);
    }
  }
  if(n == 2) p.emplace_back(8, p.back().second);
  p.emplace_back(8, 8);
}

void output(pii q) {
  printf("%c%d%c", (char)(q.second - 1 + 'a'), q.first, " \n"[q == p.back()]);
}

bool check() {
	vector<pii> v = p;
	for(int i = 0; i < (int)v.size() - 1; ++i) {
		if(!(v[i].first == v[i + 1].first || v[i].second == v[i + 1].second)) {
			output(v[i]); output(v[i + 1]); cout << endl;
			return false;
		}
	}
	std::sort(v.begin(), v.end());
	assert(std::unique(v.begin(), v.end()) == v.end());
	return true;
}

int main() {
//	for(n = 2; n <= 63; ++n) {
//		display(n);
//		p.clear();
//		if(n <= 57) solve(n);
//  	else special(n);
//  	check();
//	}
  int n = readint();
  if(n <= 57) solve(n);
  else special(n);
  assert((int)p.size() == n + 1);
  for(pii q : p) {
  	output(q);
  }
  return 0;
}