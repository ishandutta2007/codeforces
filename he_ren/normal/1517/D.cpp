#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXM = 5e2 + 5;
const int MAXD = 10 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN][MAXM], b[MAXN][MAXM];
int f[MAXD][MAXN][MAXM];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	if(d&1)
	{
		for(int i=1; i<=n; ++i, putchar('\n'))
			for(int j=1; j<=m; ++j)
				printf("-1 ");
		return 0;
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			scanf("%d",&a[i][j]);
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&b[i][j]);
	
	d /= 2;
	for(int k=1; k<=d; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
			{
				f[k][i][j] = inf;
				if(i > 1) f[k][i][j] = min(f[k][i][j], f[k-1][i-1][j] + b[i-1][j]);
				if(i < n) f[k][i][j] = min(f[k][i][j], f[k-1][i+1][j] + b[i][j]);
				if(j > 1) f[k][i][j] = min(f[k][i][j], f[k-1][i][j-1] + a[i][j-1]);
				if(j < m) f[k][i][j] = min(f[k][i][j], f[k-1][i][j+1] + a[i][j]);
			}
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=m; ++j)
			printf("%d ",f[d][i][j] * 2);
	return 0;
}