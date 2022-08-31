#include<bits/stdc++.h>
using namespace std;
int n,m,a[30][30],x[4194304],f[4194304],u[4194304],v[4194304],g[30];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	while(m--)
	  {
	   scanf("%d%d",&i,&j);
	   a[i-1][j-1]=a[j-1][i-1]=1;
	   g[i-1]|=(1<<j-1);
	   g[j-1]|=(1<<i-1);
	  }
	for(i=1;i<(1<<n);i++)
	  if(i&1)
	    x[i]=0;
	  else
	    x[i]=x[i>>1]+1;
	for(i=1;i<(1<<n);i++)
	  {
	   j=x[i];
	   if(i==(1<<j))
	     f[i]=0;
	   else
	     {
		  f[i]=1e9;
		  if(!f[i^(1<<j)])
		    {
			 for(k=0;k<n;k++)
			   if((i^(1<<j))&(1<<k) && !a[j][k])
			     break;
			 if(k==n)
			   f[i]=0;
			}
		 }
	  }
	for(i=1;i<(1<<n);i++)
	  for(j=0;j<n;j++)
	    if(i&(1<<j) && f[i]+1<f[i|g[j]])
	      {
	       f[i|g[j]]=f[i]+1;
	       u[i|g[j]]=j+1;
	       v[i|g[j]]=i;
		  }
	printf("%d\n",f[(1<<n)-1]);
	for(i=(1<<n)-1;u[i];i=v[i])
	  printf("%d ",u[i]);
	return 0;
}