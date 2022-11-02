//CF923B
//
#include <cstdio>
#include <cstring>
#include <cctype>
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
}
using namespace BasicUnit;
int n;

int main() {
	n = readint();
	if(n > 36) printf("-1\n");
	else if(n == 0) printf("233\n");
	else if(n < 0) printf("-1\n");
	else if(n == 1) printf("23333333330\n");
	else {
		int t1 = n / 2;
		int t2 = n % 2;
		while(t1--) printf("8");
		while(t2--) printf("0");
		printf("\n");
	}
	return 0;
}