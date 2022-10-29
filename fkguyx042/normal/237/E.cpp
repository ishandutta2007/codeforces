#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,id[105][105],Id[105],tot,Rp[105];
int st,ed,a[105];
char S[105],c[105][105];
int ans,Flow;
struct node{int ed,before,cost,flow;
}s[4000001];
int fox[6001],vis[6001];
int cost[6001],flow[6001],fa[6001],que[1000001];
int k1=1;  
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
          s[p].flow--;
          s[p^1].flow++;
        }
}
void mincost()
{for (;spfa();) { Flow+=flow[ed]; ans+=cost[ed]; doit();
  } 
}
int main()
{ scanf("%s",S);
  for (i=0;i<strlen(S);i++) Id[i]=++tot;
  scanf("%d",&n);
  for (i=0;i<n;i++)
{    
    scanf("%s",&c[i]);
    scanf("%d",&a[i]);
    Rp[i]=++tot;
    for (j=0;j<strlen(c[i]);j++)
      id[i][j]=++tot;
}
 st=++tot;
 ed=++tot; 
 for (i=0;i<strlen(S);i++) add(Id[i],ed,1,0);
 for (i=0;i<n;i++)
{   
    add(st,Rp[i],a[i],0);
    for (j=0;j<strlen(c[i]);j++)
      add(Rp[i],id[i][j],1,i+1);
    for (j=0;j<strlen(c[i]);j++)
      for (k=0;k<strlen(S);k++)
        if (c[i][j]==S[k]) 
        add(id[i][j],Id[k],1,0);
}
mincost();
if (Flow!=strlen(S)) printf("-1\n"); else printf("%d\n",ans);
}