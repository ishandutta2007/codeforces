#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,x[5010],f[5010][5010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]),f[i][i]=x[i];
	for(k=1;k<n;k++)
	  for(i=1;(j=i+k)<=n;i++)
	    f[i][j]=f[i][j-1]^f[i+1][j];
	for(k=1;k<n;k++)
	  for(i=1;(j=i+k)<=n;i++)
	    f[i][j]=max(f[i][j],max(f[i][j-1],f[i+1][j]));
	scanf("%d",&m);
	while(m--)
	  {
       scanf("%d%d",&i,&j);
       printf("%d\n",f[i][j]);
      }
	return 0;
}