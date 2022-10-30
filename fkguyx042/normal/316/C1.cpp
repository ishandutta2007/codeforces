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

#define N 6505
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const int x[4]={-1,1,0,0};
const int y[4]={0,0,-1,1};
int i,j,m,n,p,k,st,ed,a[105][105];
int fox[N],k1=1,que[N],flow[N],cost[N],vis[N],fa[N];
struct Node{int ed,before,flow,cost;}s[M];
int ID(int x,int y)
{
	  return (x-1)*m+y;
}
int check(int x,int y)
{
	  if (x<1||y<1||x>n||y>m) return 0;
	  return 1;
}
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
int spfa()
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=100000000;
      memset(cost,60,sizeof(cost));
      memset(vis,0,sizeof(vis));
      vis[st]=1;
      cost[st]=0;
      for (;l<=r;l++)
       { p=que[l];
         for (i=fox[p];i;i=s[i].before)
           if (s[i].flow)
             if (cost[p]+s[i].cost<cost[s[i].ed])
               {  cost[s[i].ed]=s[i].cost+cost[p];
                   flow[s[i].ed]=min(flow[p],s[i].flow);
                   fa[s[i].ed]=i;
                   if (!vis[s[i].ed]) {vis[s[i].ed]^=1; que[++r]=s[i].ed;
                   }
               }
               vis[p]^=1;
       }
    if (flow[ed]==-1) return 0; return 1;
 }
void doit()
{ int i,p;
      for (i=ed;i!=st;i=s[p^1].ed)
        { p=fa[i];
          s[p].flow-=flow[ed];
          s[p^1].flow+=flow[ed];
        }
}
int mincost()
{
  int ans=0;
  for (;spfa();) { ans+=cost[ed]*flow[ed]; doit(); }
  return ans; 
}
int main()
{
	  scanf("%d%d",&n,&m); st=n*m+1; ed=st+1;
	  for (i=1;i<=n;++i)
	    for (j=1;j<=m;++j)
	      {
	      	    scanf("%d",&a[i][j]);
	      	    if ((i+j)&1) add(st,ID(i,j),1,0);
	      	    else add(ID(i,j),ed,1,0);
	      }
	  for (i=1;i<=n;++i)
	    for (j=1;j<=m;++j)
	      if ((i+j)&1)
	      {
	      	     for (k=0;k<4;++k)
	      	       if (check(i+x[k],j+y[k])) add(ID(i,j),ID(i+x[k],j+y[k]),1,a[i][j]!=a[i+x[k]][j+y[k]]);
	      }
	  printf("%d\n",mincost());
}