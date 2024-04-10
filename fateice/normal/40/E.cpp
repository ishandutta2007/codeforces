#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define L long long
using namespace std;
int n,m,t,a[200010],b[1010],c[1010][15],d[15],e[15],f[2][1050],g[2][1050],w,p,o=1,q=998244353;
vector<int> x[200010],y[200010];
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
	//freopen("matrix.in","r",stdin);
	//freopen("matrix.out","w",stdout);
	int i,j,k,l,u,v;
	scanf("%d%d%d",&n,&m,&t);
	if(n+m&1)
	  {
       printf("0\n");
       return 0;
      }
	for(i=1;i<=t;i++)
	  {
       scanf("%d%d%d",&j,&k,&l);
       //if(n>m)
         //swap(j,k);
       if(l==-1)
         l=1;
       else
         l=0;
       x[k].push_back(j);
       y[k].push_back(l);
      }
    //if(n>m)
      //swap(n,m);
    scanf("%d",&q);
    for(i=2,k=1;i<=m;i++)
      if(x[i].size()<x[k].size())
        k=i;
    w=x[k].size();
    if(w>10)
      while(1);
    for(i=0;i<w;i++)
      a[x[k][i]]=i+1;
    for(i=1;i<=m;i++)
      if(i!=k)
        {
         for(j=0,l=u=0;j<x[i].size();j++)
           if(!a[x[i][j]])
             {
              l++;
              u^=y[i][j];
             }
         if(l==n-w)
           {
            b[++p]=u;
            for(j=1;j<=w;j++)
              c[p][j]=-1;
            for(j=0;j<x[i].size();j++)
              if(a[x[i][j]])
                c[p][a[x[i][j]]]=y[i][j];
           }
         else
           {
            o=(L)o*power(2,n-w-l-1)%q;
            for(j=1;j<=w;j++)
              d[j]++;
            for(j=0;j<x[i].size();j++)
              if(a[x[i][j]])
                {
                 d[a[x[i][j]]]--;
                 e[a[x[i][j]]]^=y[i][j];
                }
           }
        }
    for(i=0,j=0;i<w;i++)
      j^=(y[k][i]^e[i+1]^1)<<i;
    l=1;
    a[1]=j;
    u=1;
    for(i=1;i<=w;i++)
      if(d[i])
        {
         for(j=1;j<=l;j++)
           a[j+l]=a[j]^(1<<i-1);
         l<<=1;
         u=(L)u*power(2,d[i]-1)%q;
        }
    for(i=1;i<=l;i++)
      f[1][a[i]]=u;
    for(i=1;i<=p;i++)
      {
       for(j=0;j<(1<<w);j++)
         {
          f[b[i]][j]=f[1][j];
          f[b[i]^1][j]=0;
         }
       for(j=1;j<=w;j++)
         {
          for(l=0;l<=1;l++)
            for(u=0;u<(1<<w);u++)
              for(v=(c[i][j]==1?1:0);v<=(c[i][j]==0?0:1);v++)
                g[l][u]=(g[l][u]+f[l^v][u^(v<<j-1)])%q;
          for(l=0;l<=1;l++)
            for(u=0;u<(1<<w);u++)
              {
               f[l][u]=g[l][u];
               g[l][u]=0;
              }
         }
      }
    printf("%d\n",int((L)f[1][0]*o%q));
	return 0;
}