#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int n,x[60],s[60],f[60][60],g[60][110],h[60],a[60],b[60],c[110][110];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,u;
	scanf("%d",&n);
	a[0]=b[0]=1;
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   s[i]=s[i-1]+x[i]-2;
	   a[i]=(L)a[i-1]*i%q;
	   b[i]=((b[i-1]&1)?(b[i-1]+q>>1):(b[i-1]>>1));
	  }
	for(i=0;i<=2*n+1;i++)
	  {
	   c[i][0]=1;
	   for(j=1;j<=i;j++)
	     c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;
	  }
	h[0]=1;
	h[1]=-1;
	for(i=2;i<=n;i++)
	  h[i]=-(2ll*(i-1)*h[i-2]+h[i-1])%q;
	f[1][x[1]]=(q+1)/a[x[1]];
	for(i=1;i<=n;i++)
	  {
	   for(j=0;j<=i+i+1;j++)
	     if(g[i][j])
	       for(k=0;k<=j;k+=2)
	         f[i][j-k]=(f[i][j-k]+(L)c[j][k]*c[k][k>>1]%q*a[k>>1]%q*b[k>>1]%q*g[i][j])%q;
	   for(j=1;j<=i+i+1 && i+j<=n;j++)
	     if(f[i][j])
	       {
		    k=s[i+j]-s[i];
		    l=j-k;
		    f[i][j]=(L)f[i][j]*a[j]%q*b[k]%q;
		    for(u=0;u<=k;u++)
		      g[i+j][(k-u<<1)+l]=(g[i+j][(k-u<<1)+l]+(L)c[k][u]*h[u]%q*f[i][j])%q;
		   }
	  }
	f[n][0]=(f[n][0]+q)%q;
	printf("%d\n",f[n][0]);
	return 0;
}