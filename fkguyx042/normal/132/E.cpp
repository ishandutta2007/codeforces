#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int ans,Ans;
struct node{int ed,before,cost,flow,remain;
}s[3000001];
int fox[6001],vis[6001],st,ed;
int cost[6001],flow[6001],fa[6001],que[1000001],a[6001],A[6001],Last[55];
int k1=1;  
int i,j,m,n,p,k;
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; s[k1].remain=flow;
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
int spfa()
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=10000000;
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
{ for (;spfa();) {
       ans+=cost[ed]*flow[ed]; 
        doit();
  } 
  return ans;
}
void Go()
{    int i,j;
    for (j=fox[st];j;j=s[j].before)
       if (!s[j].flow)
    { 
          int x=s[j].ed;
          int R=s[j].ed;
          while (x!=ed)
        { 
              if (x>2*n)
            {  
                for (i=fox[x];i;i=s[i].before)
                  if (s[i].flow!=s[i].remain&&s[i].ed<=n)
                  {   s[i].flow++;
                      x=s[i].ed;
                      A[s[i].ed]=R-2*n;
                      break;
                  }
                  else if (!s[i].flow&&s[i].ed==ed)
                {   x=ed; break; }
            }
            else  if (x<=n)    x=x+n;
			else 
			{ 
			     for (i=fox[x];i;i=s[i].before)
			       if (s[i].flow!=s[i].remain&&s[i].ed+n>x)
			     {
			     	  A[s[i].ed]=R-2*n;
			     	  x=s[i].ed;
			     	  s[i].flow++;
			     	  break;
			     }
			}
        }
     }
}
int bit(int x)
{  int sm=0;
  for (;x;x>>=1) sm+=x&1;
  return sm;
}
int main()
{ 
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    st=2*n+m+1; ed=st+1;
    for (i=1;i<=m;i++) add(st,2*n+i,1,0);
       for (j=1;j<=n;j++)
    { 
       add(j,j+n,1,-1000000);
       add(j+n,ed,1,0);
    }
    for (i=1;i<=m;i++) for (j=1;j<=n;j++) add(i+2*n,j,1,bit(a[j]));
    for (i=1;i<=m;i++) add(i+2*n,ed,1,0);
    for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
     {   
     	  if (a[i]==a[j]) add(i+n,j,INF,0);
     	  else add(i+n,j,INF,bit(a[j]));
     }
    Ans=mincost()+n*1000000;
    Go();
    int sum=0;
    //for (i=1;i<=n;i++) if (A[i]) sum++;
        for (i=1;i<=n;i++)
   { 
       if (Last[A[i]]!=a[i]) sum++;
       Last[A[i]]=a[i];
   }
    printf("%d %d\n",sum+n,Ans);
    memset(Last,0,sizeof(Last));
    for (i=1;i<=n;i++)
   { 
       if (Last[A[i]]!=a[i]) printf("%c=%d\n",'a'+A[i]-1,a[i]);
       Last[A[i]]=a[i];
       printf("print(%c)\n",'a'+A[i]-1);
   }
  //  print();
}