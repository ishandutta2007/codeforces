#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105
#define INF 1LL << 60

using namespace std;

typedef long long LL;

int n,m,k,a[N];
LL F[N][N][N],p[N][N];

int main()
{
	memset(F,127/3,sizeof(F));
	//cout << F[0][0][0] << endl;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%I64d",&p[i][j]);
	
	for (int i=1;i<=m;i++) {
		if (a[1] == 0) F[1][i][1] = p[1][i];
		if (a[1] == i) F[1][i][1] = 0;
	}
	
	for (int i=2;i<=n;i++) {
		if (a[i] == 0) {
			for (int j=1;j<=m;j++) {
				for (int t=1;t<=k;t++)
					F[i][j][t] = min(F[i-1][j][t] + p[i][j] , F[i][j][t]);
				
				for (int lj=1;lj<=m;lj++) if (lj != j)
					for (int t=1;t<=k;t++)
						F[i][j][t] = min(F[i-1][lj][t-1] + p[i][j] , F[i][j][t]);
			}		
		} else {
			int j = a[i];
			
			for (int t=1;t<=k;t++)
				F[i][j][t] = min(F[i-1][j][t] , F[i][j][t]);
			
			for (int lj=1;lj<=m;lj++) if (lj != a[i])
				for (int t=1;t<=k;t++)
					F[i][j][t] = min(F[i-1][lj][t-1],F[i][j][t]);
		}
	}
	
	LL ans = INF;
	for (int i=1;i<=m;i++) ans = min(F[n][i][k],ans);
	
	if (ans == INF)	printf("-1\n"); else printf("%I64d\n",ans);
	
	return 0;
}