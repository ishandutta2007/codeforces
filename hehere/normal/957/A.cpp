// Codeforces Round #472 (rated, Div. 2, based on VK Cup 2018 Round 2)
// Problem A
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::swap; using std::sort;
typedef long long LL;
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
const int maxN = 100 + 5;
int n;
char s[maxN];

int main() {
	cin >> n;
	scanf("%s", s);
	int cnt = 0;
	for(int i=0; i<n; i++) if(s[i] == '?') cnt++;
	if(cnt == 0) { printf("No\n"); return 0; }
	for(int i=0; i<n-1; i++) if(s[i] != '?' && s[i] == s[i+1])
		{ printf("No\n"); return 0; }
	if(s[0] == '?' || s[n-1] == '?') { printf("Yes\n"); return 0; }
	for(int i=1; i<n-1; i++) if(s[i] == '?') if(s[i-1] == s[i+1] || s[i-1] == '?' || s[i+1] == '?')
		{ printf("Yes\n"); return 0; }
	printf("No\n");
	return 0;
}