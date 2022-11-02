// Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// C
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
const int maxN = 100000 + 233;
const int maxA = 100000 + 233;
int n, a[maxN], c[3], mn = maxA, mx = -maxA;

int main(){
	n = readint();
	for(int i=1; i<=n; i++) {
		a[i] = readint();
		mn = min(mn, a[i]); mx = max(mx, a[i]);
	}
	if(mx - mn <= 1) {
		printf("%d\n", n);
		for(int i=1; i<=n; i++) printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for(int i=1; i<=n; i++) c[a[i] - mn]++;
	
	int xa = min(c[0], c[2]);
	int xb = c[1] / 2;
	int ans = n - max(xa, xb)*2;
	printf("%d\n", ans);
	if(xa > xb) {
		for(int i=0; i<c[0] - xa; i++) printf("%d ", mn);
		for(int i=0; i<c[2] - xa; i++) printf("%d ", mn + 2);
		for(int i=0; i<xa+xa+c[1]; i++) printf("%d ", mn + 1);
		printf("\n");
	} else {
		for(int i=0; i<c[0] + xb; i++) printf("%d ", mn);
		for(int i=0; i<c[2] + xb; i++) printf("%d ", mn + 2);
		for(int i=0; i<c[1] - xb - xb; i++) printf("%d ", mn + 1);
	}
	
	return 0;
}