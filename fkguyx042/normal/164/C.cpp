#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1005
using namespace std;
int i,j,m,n,p,k,fox[3*N],k1=1,que[3000005],cost[3*N],flow[3*N],vis[3*N],fa[3*N],st,ed;
const int INF=(int)1e5;
struct Q{int l,r,k,id;}A[N];
struct Node {int ed,before,flow,cost;}s[2000005];
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
inline bool cmp(Q a,Q b)
{
	  if (a.l!=b.l) return a.l<b.l;
	  return a.r<b.r;
}
int spfa()
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=100000000;
      memset(cost,-1,sizeof(cost));
      memset(vis,0,sizeof(vis));
      vis[st]=1;
      cost[st]=0;
      for (;l<=r;l++)
       { p=que[l];
         for (i=fox[p];i;i=s[i].before)
           if (s[i].flow)
             if (cost[p]+s[i].cost>cost[s[i].ed])
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
int mincost()
{
	  int ans=0;
	  while (spfa()) ans+=cost[ed]*flow[ed],doit();
	  return ans;
}
int main()
{
	 scanf("%d%d",&n,&k);
	 st=2*n+1; ed=st+1; add(st,ed,INF,0);
	 for(i=1;i<=n;++i) scanf("%d%d%d",&A[i].l,&A[i].r,&A[i].k),add(i,i+n,1,A[i].k),A[i].id=i,add(i+n,ed,INF,0);
	 sort(A+1,A+n+1,cmp);
	 add(st,A[1].id,k,0);
	 for (i=1;i<=n;++i)
	 {
	 	 if (i!=n) add(A[i].id,A[i+1].id,INF,0);
	 	 for (j=1;j<=n;++j) if (A[j].l>=A[i].l+A[i].r) break;
	 	 if (j<=n) add(A[i].id+n,A[j].id,INF,0);
	 }
	 mincost();
	 for (i=1;i<=n;++i)
	 {
	   for (j=fox[i];j;j=s[j].before)
	     if (s[j].ed==i+n) break;
	   if (s[j].flow) printf("0 "); else printf("1 ");
     }
}