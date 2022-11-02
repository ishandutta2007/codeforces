// Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
// Problem A
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
	template<typename T>
	inline T readint() {
		T a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	template<typename T>
	inline T min(T a, T b) {
		return a < b ? a : b;
	}
	template<typename T>
	inline T max(T a, T b) {
		return b < a ? a : b;
	}
}
using namespace BasicUnit;
const int maxR = 500 + 23;
int r, c;
char s[maxR][maxR];

int main() {
	r = readint<int>(); c = readint<int>();
	for(int i=1; i<=r; i++) scanf("%s", s[i] + 1);
	bool flag = true;
	for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) {
		if(j < c && s[i][j] == 'S' && s[i][j+1] == 'W') flag = false;
		if(j < c && s[i][j] == 'W' && s[i][j+1] == 'S') flag = false;
		if(i < r && s[i][j] == 'S' && s[i+1][j] == 'W') flag = false;
		if(i < r && s[i][j] == 'W' && s[i+1][j] == 'S') flag = false;
	}
	if(flag) {
		printf("Yes\n");
		for(int i=1; i<=r; i++) 
			for(int j=1; j<=c; j++) if(s[i][j] == '.') s[i][j] = 'D';
		for(int i=1; i<=r; i++) printf("%s\n", s[i] + 1);
	} else {
		printf("No\n");
	}
	
	return 0;
}