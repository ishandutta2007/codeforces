#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,id[105][105],Id[105],tot,a[505],b[505];
int st,ed;
double cost[6001],ans;
int Flow;
struct node{int ed,before,flow; double cost;
}s[4000001];
int fox[6001],vis[6001];
int flow[6001],fa[6001],que[1000001];
int k1=1;  
void add(int p1,int p2,int flow,double cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
double sqr(int x)
{ return 1.0*x*x; }
int spfa()
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=100000000;
      //memset(cost,60,sizeof(cost));
      for (i=1;i<=2*n+2;i++) cost[i]=1e18;
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
          s[p].flow--;
          s[p^1].flow++;
        }
}
void mincost()
{for (;spfa();) { Flow+=flow[ed]; ans+=cost[ed]; doit();
  } 
}
int main()
{    scanf("%d",&n);
     st=2*n+1; ed=st+1;
     for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
     for (i=1;i<=n;i++) add(st,2*i-1,2,0),add(2*i,ed,1,0);
     for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
         if (b[i]>b[j]) add(2*i-1,2*j,1,(double)sqrt(sqr(b[i]-b[j])+sqr(a[i]-a[j])));
     mincost();
     if (Flow!=n-1) printf("-1\n"); else printf("%.10lf\n",ans);
}