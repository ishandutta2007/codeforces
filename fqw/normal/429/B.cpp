#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;
const int MAXN=1010;

int t[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], d[MAXN][MAXN];
int n, m;

int main() {
	scanf("%d%d", &n,&m);
	forint(i, 1, n) forint(j, 1, m) scanf("%d", &t[i][j]);
	fillchar(a, 0);
	forint(i, 1, n) forint(j, 1, m)
		a[i][j]=max(a[i-1][j],a[i][j-1])+t[i][j];
	forintdown(i, n, 1) forintdown(j, m, 1)
		b[i][j]=max(b[i+1][j],b[i][j+1])+t[i][j];
	forintdown(i, n, 1) forint(j, 1, m)
		c[i][j]=max(c[i+1][j],c[i][j-1])+t[i][j];
	forint(i, 1, n) forintdown(j, m, 1)
		d[i][j]=max(d[i-1][j],d[i][j+1])+t[i][j];
	int ans=0;
	forint(i, 2, n-1) forint(j, 2, m-1) {
		ans=max(ans, a[i-1][j]+b[i+1][j]+c[i][j-1]+d[i][j+1]);
		ans=max(ans, a[i][j-1]+b[i][j+1]+c[i+1][j]+d[i-1][j]);
	}
	printf("%d\n", ans);
	
	return 0;
}