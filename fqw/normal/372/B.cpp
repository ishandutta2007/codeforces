#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int MAXN=44;

int a[MAXN][MAXN];
int g[MAXN][MAXN][MAXN][MAXN];
int x[MAXN][MAXN][MAXN][MAXN];
int y[MAXN][MAXN][MAXN][MAXN];
int n, m;

int main() {
	int q;
	scanf("%d%d", &n,&m); scanf("%d", &q);
	fillchar(a, 0);
	forint(i, 1, n) {
		char s[99]; scanf("%s", s);
		forint(j, 1, m) a[i][j]=(s[j-1]=='0'?0:1);
	}
	forint(i, 1, n) forint(j, 1, m)
		a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		//printf("%2d ", a[i][j]); if(j==m) printf("\n"); }
	fillchar(g, 0);
	forint(i, 1, n) forint(j, 1, m)
		forint(i2, i, n) forint(j2, j, m)
			if(a[i2][j2]-a[i-1][j2]-a[i2][j-1]+a[i-1][j-1]==0)
				g[i][j][i2][j2]=1;
	fillchar(x, 0);
	forint(i, 1, n) forint(j, 1, m)
		forint(i2, i, n) forint(j2, j, m)
			x[i][j][i2][j2]=x[i][j][i2-1][j2]+x[i][j][i2][j2-1]-x[i][j][i2-1][j2-1]+g[i][j][i2][j2];
	fillchar(y, 0);
	forintdown(i2, n, 1) forintdown(j2, m, 1)
		forintdown(i, i2, 1) forintdown(j, j2, 1)
			y[i][j][i2][j2]=y[i+1][j][i2][j2]+y[i][j+1][i2][j2]-y[i+1][j+1][i2][j2]+x[i][j][i2][j2];
	while(q--) {
		int a, b, c, d; scanf("%d%d%d%d", &a,&b,&c,&d);
		//printf("g=%d\n", g[a][b][c][d]);
		printf("%d\n", y[a][b][c][d]);
	}
	return 0;
}