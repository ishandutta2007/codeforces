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

const int maxN = 5000 + 5;
int n;
char s[maxN];
int z[maxN][maxN];
int a, b, f[maxN];

void Z(int s) {
	int L = -1, R = -1;
	z[s][s] = n - s + 1;
	for(int i = s + 1; i <= n; ++ i) {
		int &len = z[s][i];
		if(i <= R) len = std::min(z[s][s - 1 + i - L + 1], R - i + 1);
		else len = 0;
		while(::s[i + len] == ::s[s + len]) len ++;
		if(i + len - 1 > R) L = i, R = i + len - 1;
	}
	displaya(z[s], 1, n);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	cin >> (s + 1); s[n + 1] = 0;
	for(int i = 1; i <= n; ++ i) Z(i);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	f[1] = a;
	for(int i = 1; i < n; ++ i) {
		int len = 0;
		for(int j = 1; j <= i; ++ j) {
			chmax(len, std::min(z[j][i + 1], i - j + 1));
		}
//		printf("z[%d] = %d\n", i + 1, len);
		assert(i + len <= n);
		chmin(f[i + 1], f[i] + a);
		for(int j = 1; j <= len; ++ j)
			chmin(f[i + j], f[i] + b);
	}
	printf("%d\n", f[n]);
	return 0;
}