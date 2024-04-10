#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 105

using namespace std;
long long color[maxn];
long long p[maxn][maxn];
bool bdp[maxn][maxn][maxn];
long long idp[maxn][maxn][maxn];
long long nxco[maxn];
long long n,m,k;
long long inf=614748364800;
long long dp(long long a,long long b,long long c)// a need b before is c
{

	if(bdp[a][b][c]) return idp[a][b][c];
	bdp[a][b][c]=true;
	if(b<0) return idp[a][b][c]=inf;
	if(a==n+1)
	{ 
		if(b==0) return idp[a][b][c]=0;
		else return idp[a][b][c]=inf;
	}
	idp[a][b][c]=inf;
	if(color[a]) 
		if(color[a]==c) return idp[a][b][c]=dp(a+1,b,c);
		else return idp[a][b][c]=dp(a+1,b-1,color[a]);
	else 
	{
		for(long long i=1;i<=m;i++)
		{
			if(i==c) idp[a][b][c]=min(idp[a][b][c],dp(a+1,b,i)+p[a][i]);
			else idp[a][b][c]=min(idp[a][b][c],dp(a+1,b-1,i)+p[a][i]);
		}
		return idp[a][b][c];
	}
}

int main()
{
	memset(bdp,false,sizeof(bdp));
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(long long i=1;i<=n;i++) scanf("%I64d",&color[i]);
	for(long long i=1;i<=n;i++)	
		for(long long j=1;j<=m;j++)
			scanf("%I64d",&p[i][j]);
	if(dp(1,k,0)==inf) printf("-1\n");
	else printf("%I64d\n",dp(1,k,0));
	return 0;
}