// Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// A
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
	inline int readint() {
		int a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	inline LL readLL() {
		LL a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	inline int min(int a, int b) {
		return a < b ? a : b;
	}
	inline int max(int a, int b) {
		return a > b ? a : b;
	}
	inline LL min(LL a, LL b) {
		return a < b ? a : b;
	}
	inline LL max(LL a, LL b) {
		return a > b ? a : b;
	}
	inline int checkmin(int &a, int b) {
		return a > b ? a = b : a;
	}
	inline int checkmax(int &a, int b) {
		return a < b ? a = b : a;
	}
	inline LL checkmin(LL &a, LL b) {
		return a > b ? a = b : a;
	}
	inline LL checkmax(LL &a, LL b) {
		return a < b ? a = b : a;
	}
}
using namespace BasicUnit;
LL a, b;
int main(){
	a = readLL(); b = readLL();
	if(a > b) std::swap(a, b);
	LL m = a + b >> 1LL;
	LL s1 = m - a;
//	printf("%lld\n", m);
	LL ans = 0;
	for(int i=1; i<=s1; i++) ans += i;
	s1 = b - m;
	for(int i=1; i<=s1; i++) ans += i;
	printf("%lld\n", ans);
	return 0;
}