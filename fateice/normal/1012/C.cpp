#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,f[5010][2510],g[5010][2510],x[5010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=0;i<=n;i++)
	  for(j=1;j*2<=n+1;j++)
	    f[i][j]=g[i][j]=1e9;
	f[1][1]=0;
	for(i=2;i<=n;i++)
	  for(j=1;j*2<=i+1;j++)
	    {
         f[i][j]=min(f[i-2][j-1]+max(0,x[i-1]-min(x[i-2],x[i])+1),g[i-2][j-1]+max(0,x[i-1]-x[i]+1));
         g[i][j]=min(f[i-1][j]+max(0,x[i]-x[i-1]+1),g[i-1][j]);
        }
    for(i=1;i*2<=n+1;i++)
      printf("%d ",min(f[n][i],g[n][i]));
	return 0;
}