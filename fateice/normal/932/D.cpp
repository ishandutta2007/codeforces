#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,a[400010][25],b[400010][25],f[400010][25];
L x[400010],g[400010][25],p;
inline int find(L i,L j)
{
    int k;
    for(k=20;k>=0;k--)
      if(f[i][k]<j)
        i=a[i][k];
    if(x[i]<j)
      return a[i][0];
    else
      return i;
}
inline L ask(L i,L j)
{
    int k,p=0;
    for(k=20;k>=0;k--)
      if(g[i][k]<=j)
        {
         j-=g[i][k];
         i=b[i][k];
         p+=(1<<k);
        }
    return p;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	L i,j;
	int k;
	x[0]=1e16;
	for(i=0;i<=20;i++)
	  f[0][i]=g[0][i]=1e16;
	n=1;
	for(i=1;i<=20;i++)
	  f[1][i]=g[1][i]=1e16;
	scanf("%d",&m);
	while(m--)
	  {
       scanf("%lld",&i);
       if(i==1)
         {
          scanf("%lld%lld",&i,&j);
          i^=p;
          j^=p;
          n++;
          x[n]=j;
          a[n][0]=i;
          f[n][0]=j;
          for(i=1;i<=20;i++)
            {
             a[n][i]=a[a[n][i-1]][i-1];
             f[n][i]=max(f[n][i-1],f[a[n][i-1]][i-1]);
            }
          b[n][0]=find(a[n][0],j);
          g[n][0]=j;
          for(i=1;i<=20;i++)
            {
             b[n][i]=b[b[n][i-1]][i-1];
             g[n][i]=g[n][i-1]+g[b[n][i-1]][i-1];
            }
         }
       else
         {
          scanf("%lld%lld",&i,&j);
          i^=p;
          j^=p;
          p=ask(i,j);
          printf("%lld\n",p);
         }
      }
	return 0;
}