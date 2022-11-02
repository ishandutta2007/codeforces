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
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                      \
	{                                           \
		cerr << #a << " = {";                   \
		for (int qwq = (st); qwq <= (n); ++qwq) \
			if (qwq == (st))                    \
				cerr << a[qwq];                 \
			else                                \
				cerr << ", " << a[qwq];         \
		cerr << "}" << endl;                    \
	}
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#include <ctime>
class MyTimer {
	clock_t st;
public:
	MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
	~MyTimer() { report(); }
	void reset() { st = clock_t(); }
	void report() {  cerr << "Time consumed: " << (clock() - st) * \
		1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
#define eprintf(...) if(0) fprintf(stderr, __VA_ARGS__)
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

const int maxN = 500000 + 233;
int n, k, m, s;
int a[maxN], b[maxN], req[maxN];
int cnt[maxN];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> m >> k >> n >> s;
	for(int i = 1; i <= m; ++ i) cin >> a[i]; a[0] = 1;
	memset(req, 0, sizeof(req));
	for(int i = 1; i <= s; ++ i) cin >> b[i], req[b[i]] += 1;
	int ok = 0, len = k + m - k * n;
	for(int i = 1; i < maxN; ++ i) ok += (cnt[i] >= req[i]);
	for(int i = 1; i < len; ++ i) {
		if(++cnt[a[i]] == req[a[i]]) ++ ok;
	}
	int j = 0;
	for(int i = k + m - k * n; i <= m; ++ i) {
		if(++cnt[a[i]] == req[a[i]]) ++ ok;
		while(i - j > len || j % k != 0)
			if(++j, (cnt[a[j]]-- == req[a[j]])) -- ok;
		if(ok == maxN - 1) {
			eprintf("[%d, %d]\n", j + 1, i);
			memset(cnt, 0, sizeof(cnt));
			printf("%d\n", i - j - k);
			int thr = i - j - k;
			for(int t = j + 1; t <= i; ++ t) {
				if(cnt[a[t]] == req[a[t]]) {
					if(thr) printf("%d ", t), thr--;
				}
				else cnt[a[t]] ++;
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}