// Codeforces Round #472 (rated, Div. 2, based on VK Cup 2018 Round 2)
// Problem B
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::swap; using std::sort;
#include <set>
using std::set;
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
const int maxN = 50 + 5;
int n, m;
char s[maxN][maxN];
bool vis[maxN][maxN];
set<int> R, C;
set<int> TR, TC;

void spread(int x, int y) {
//	printf("spread (%d, %d)\n", x, y);
	vis[x][y] = 1; TR.insert(x); TC.insert(y);
	for(int i=1; i<=n; i++) if(s[i][y] == '#' && !vis[i][y]) spread(i, y);
	for(int j=1; j<=m; j++) if(s[x][j] == '#' && !vis[x][j]) spread(x, j);
}

int main() {
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> (s[i] + 1);
	
	R.clear(); C.clear(); TR.clear(); TC.clear();
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) if(s[i][j] == '#') {
			memset(vis, 0, sizeof(vis)); TR.clear(); TC.clear();
			spread(i, j);
			for(set<int>::iterator x = TR.begin(); x != TR.end(); ++x)
			for(set<int>::iterator y = TC.begin(); y != TC.end(); ++y)
				if(s[*x][*y] == '.') { printf("No\n"); return 0; }
				else s[*x][*y] = '.';
//			printf("Row = "); for(set<int>::iterator x = TR.begin(); x != TR.end(); ++x) printf("%d ", *x); printf("\n");
//			printf("Col = "); for(set<int>::iterator x = TC.begin(); x != TC.end(); ++x) printf("%d ", *x); printf("\n");
		}
	printf("Yes\n");
	return 0;
}