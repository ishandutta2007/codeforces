// Codeforces Round #472 (rated, Div. 2, based on VK Cup 2018 Round 2)
// Problem C
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iomanip>
#include <algorithm>
using std::swap; using std::sort;
typedef long long LL;
#define double long double
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
		inline int readint() {
		int a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	inline LL readLL() {
		LL a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	template<typename T>
	inline T min(T a, T b) { return a < b ? a : b; }
	template<typename T>
	inline T max(T a, T b) { return a > b ? a : b; }
}
using namespace BasicUnit;
const int maxN = 100000 + 233;
int n, U, a[maxN];
double best = -1;
int main() {
	
	n = readint(); U = readint();
	for(int i=1; i<=n; i++) a[i] = readint();
	int R = 3;
	for(int i=1; i<=n-2; i++) {
		while(R < n && a[R+1] - a[i] <= U) R++;
		if(a[R] - a[i] <= U && i+1 < R)
		best = max(best, (double)(a[R]-a[i+1]) / (double)(a[R]-a[i]));
	}
	
	if(best < 0) cout << "-1\n"; else cout << std::fixed << std::setprecision(15) << best << endl;
	return 0;
}