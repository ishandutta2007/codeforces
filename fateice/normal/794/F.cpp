#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,g[300000][10],p;
long long f[300000][10],x[10],y[10],w;
inline void down(int i)
{
    int j;
    if(i<p)
      {
       for(j=0;j<10;j++)
         {
          g[2*i][j]=g[i][g[2*i][j]];
          g[2*i+1][j]=g[i][g[2*i+1][j]];
         }
      }
    for(j=0;j<10;j++)
      y[g[i][j]]+=f[i][j];
    for(j=0;j<10;j++)
      {
       f[i][j]=y[j];
       y[j]=0;
       g[i][j]=j;
      }
}
inline void change(int i,int j,int k,int l,int r,int x,int y)
{
    int u;
    if(l<=j && k<=r)
      {
       for(u=0;u<10;u++)
         if(g[i][u]==x)
           g[i][u]=y;
       down(i);
      }
    else
      {
       down(i);
       down(2*i);
       down(2*i+1);
       if(l<=(j+k>>1))
         change(i*2,j,j+k>>1,l,r,x,y);
       if(r>(j+k>>1))
         change(i*2+1,(j+k>>1)+1,k,l,r,x,y);
       for(u=0;u<10;u++)
         f[i][u]=f[i*2][u]+f[i*2+1][u];
      }
}
inline void sum(int i,int j,int k,int l,int r)
{
    down(i);
    if(l<=j && k<=r)
      {
       int u;
       for(u=0;u<10;u++)
         x[u]+=f[i][u];
      }
    else
      {
       if(l<=(j+k>>1))
         sum(i*2,j,j+k>>1,l,r);
       if(r>(j+k>>1))
         sum(i*2+1,(j+k>>1)+1,k,l,r);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(p=1;p<n;p*=2);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&j);
       for(k=1;k<=j;k*=10)
         f[p+i-1][j/k%10]+=k;
      }
    for(i=p-1;i>0;i--)
      for(j=0;j<10;j++)
        f[i][j]=f[i*2][j]+f[i*2+1][j];
    for(i=1;i<2*p;i++)
      for(j=0;j<10;j++)
        g[i][j]=j;
    while(m--)
      {
       scanf("%d",&i);
       if(i==1)
         {
          scanf("%d%d%d%d",&i,&j,&k,&l);
          change(1,1,p,i,j,k,l);
         }
       else
         {
          scanf("%d%d",&i,&j);
          sum(1,1,p,i,j);
          for(i=1;i<10;i++)
            w+=x[i]*i;
          printf("%lld\n",w);
          for(i=0;i<10;i++)
            x[i]=0;
          w=0;
         }
      }
	return 0;
}