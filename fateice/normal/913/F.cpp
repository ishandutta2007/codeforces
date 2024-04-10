#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=998244353;
int n,a,b,p,c[2010][2010],x[2010],f[2010],g[2010];
inline int power(int a,int b)
{
    if(!b)
      return 1;
    int c=power(a,b>>1);
    c=(L)c*c%q;
    if(b&1)
      c=(L)c*a%q;
    return c;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&a,&b);
	p=(L)a*power(b,q-2)%q;
	/*for(i=0;i<=n;i++)
	  for(c[i][0]=1,j=1;j<=i;j++)
	    c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;*/
	for(i=0;i<=n;i++)
	  {
       c[i][0]=1;
       for(j=1;j<=i;j++)
         c[i][j]=((L)c[i-1][j-1]*power(p,i-j)+(L)c[i-1][j]*power(1-p,j))%q;
      }
	for(i=1;i<=n;i++)
	  {
       x[i]=1;
       for(j=1;j<i;j++)
         x[i]=(x[i]-(L)c[i][j]*x[j])%q;
      }
    for(i=2;i<=n;i++)
      {
       for(j=1;j<i;j++)
         f[i]=(f[i]+(L)c[i][j]*x[j]%q*(g[j]+g[i-j]-(i-j)*(i-j-1)/2))%q;
       g[i]=(L)(f[i]+i*(i-1)/2)*power(1-x[i],q-2)%q;
      }
    printf("%d\n",(g[n]+q)%q);
	return 0;
}