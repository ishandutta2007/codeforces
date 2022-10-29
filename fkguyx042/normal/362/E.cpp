#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,x,a[55][55];
int ans,Flow,LastFlow;
struct node{int ed,before,cost,flow;
}s[4000001];
int fox[6001],vis[6001],st,ed;
int cost[6001],flow[6001],fa[6001],que[1000001];
int k1=1;  
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
int spfa(int P)
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=(P==1)?10000000:1;
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
int mincost(int p)
{ for (;spfa(p);) {
       Flow+=flow[ed]; 
       ans+=cost[ed]*flow[ed]; if (ans>k) return LastFlow;
       LastFlow=Flow;
        doit();
  } 
  return Flow;
}
int main()
{ 
     scanf("%d%d",&n,&k);
     st=n+1; ed=st+1;
     add(st,1,INF,0);
     add(n,ed,INF,0);
     for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
      { 
             scanf("%d",&x); a[i][j]=x;
             if (x) 
             {   
                  add(i,j,x,0);
 //                 add(i,j,k,1);
             }
      }
    mincost(1);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (a[i][j]) add(i,j,k,1);
      printf("%d\n",mincost(0));
    // for (;;);
}