#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,x[2010],f[2010][5],a[5]={0,1,2,1,2};
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<=n+1;i++)
	  for(j=1;j<=4;j++)
	    f[i][j]=max(f[i-1][j],f[i-1][j-1])+(x[i]==a[j]);
	printf("%d\n",f[n+1][4]);
	return 0;
}