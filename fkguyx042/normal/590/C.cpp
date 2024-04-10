#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1005
#define M 1000005
#define seed 23333
#define Mo 998244353

using namespace std;
const int x[4]={0,0,-1,1};
const int y[4]={1,-1,0,0};
int i,j,m,n,p,k,Qx[M],Qy[M];
const int inf=(int)1e7;
char c[N][N];
int a[N][N],dis[4][N][N],dist[N][N];
bool check(int x,int y,int C)
{
  if (x<0||x>=n||y<0||y>=m||dis[C][x][y]!=inf*2||c[x][y]=='#') return 0;
  return 1;
}
void get(int C)
{
   int i,j,p,l=1,r=0;
   for (i=0;i<n;++i)
     for (j=0;j<m;++j) dis[C][i][j]=inf*2;
   for (i=0;i<n;++i)
     for (j=0;j<m;++j)
        if (c[i][j]==C+'0')
        {
        	 Qx[++r]=i;
        	 Qy[r]=j;
        	 dis[C][i][j]=0;
        }
  for (;l<=r;++l)
  {
  	 int ax=Qx[l],ay=Qy[l];
  	 for (i=0;i<4;++i)
  	  if (check(ax+x[i],ay+y[i],C))
  	  {
  	  	   dis[C][ax+x[i]][ay+y[i]]=dis[C][ax][ay]+1;
  	  	   Qx[++r]=ax+x[i];
  	  	   Qy[r]=ay+y[i];
  	  }
  }
  for (i=1;i<=3;++i)
    if (i!=C)
    {
      dist[C][i]=inf;
      for (j=0;j<n;++j)
        for (k=0;k<m;++k)
           if (c[j][k]=='0'+i)
             dist[C][i]=min(dist[C][i],dis[C][j][k]-1);
    }
}
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=0;i<n;++i)
	  {
	  	  scanf("%s",c[i]);
	  }
	  for (i=1;i<=3;++i) get(i);
      int ans=inf;
	  for (i=0;i<n;++i)
	    for (j=0;j<m;++j)
	       if (c[i][j]!='#')
	       {
	       	  if (c[i][j]=='.') ans=min(ans,dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-2);
	       	  else ans=min(ans,dis[1][i][j]+dis[2][i][j]+dis[3][i][j]);
	       }
	  ans=min(ans,dist[1][2]+dist[1][3]);
	  ans=min(ans,dist[1][2]+dist[2][3]);
	  ans=min(ans,dist[3][2]+dist[1][3]);
	  if (ans==inf) printf("-1\n");
	  else printf("%d\n",ans);
}