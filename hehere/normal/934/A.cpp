//CF923A
//
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'\n", __LINE__, __FUNCTION__);
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
		while(isalpha(c)) a = a*10 + c - '0', c = getchar();
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
}
using namespace BasicUnit;
const int maxN = 50 + 2;
int n, m;
int a[maxN], b[maxN];

int main() {
	n = readint(); m = readint();
	for(int i=0; i<n; i++) a[i] = readint();
	std::sort(a, a+n);
	for(int i=0; i<m; i++) b[i] = readint();
	std::sort(b, b+m);
	LL ans = (LL)(2e18);
	for(int i=0; i<n; i++) {
		LL ta = (LL)(-2e18);
		for(int j=0; j<n; j++) if(j != i) {
			for(int k=0; k<m; k++) 
				ta = max(ta, a[j]*(LL)b[k]);
		}
		ans = min(ta, ans);
	}
	printf("%lld\n", ans);
	
	
	return 0;
}