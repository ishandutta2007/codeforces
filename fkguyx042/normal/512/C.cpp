#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[201],sum,k1,dis[205],cost[205],flow[205],ps,sky,fox[205],que[205],st,ed,vis[205],fa[205],x,R,J;
struct Node{int ed,before,cost,flow;}s[100001];
int Now[205];
bool prime(int x)
{int i;
  for (i=2;i*i<=x;i++) if (x%i==0) return false;
  return true;
}
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
void dfs(int x)
{  int i;
   vis[x]=1;
   que[++que[0]]=x;
   if (x==J) for (i=1;i<=n;i++) if (a[i]==1&&!Now[i]) que[++que[0]]=i;
   for (i=fox[x];i;i=s[i].before)
     if (s[i].ed<=n&&s[i].flow==(1-(a[x]&1))&&!vis[s[i].ed])
     { vis[s[i].ed]=1;
       dfs(s[i].ed);
     }
}
void print()
{  for (i=fox[st];i;i=s[i].before)
    if (!s[i].flow&&a[s[i].ed]==1)  { J=s[i].ed; break; }
   for (i=fox[st];i;i=s[i].before) 
    if (!s[i].flow) Now[s[i].ed]=1;
    int All=0;
    memset(vis,0,sizeof(vis));
   for (i=fox[st];i;i=s[i].before)
   if (!s[i].flow&&!vis[s[i].ed]&&s[i].ed<=n)
  {  memset(que,0,sizeof(que));
  	  dfs(s[i].ed);
  	All++;
  }
  printf("%d\n",All);
  memset(vis,0,sizeof(vis));
for (i=fox[st];i;i=s[i].before)
   if (!s[i].flow&&!vis[s[i].ed]&&s[i].ed<=n)
  {  memset(que,0,sizeof(que));
  	  dfs(s[i].ed); 
  	 for (j=0;j<=que[0];j++) printf("%d ",que[j]);
  	 printf("\n");
  }
  exit(0);
}
void Print()
{  int All=0; J=0;
    memset(vis,0,sizeof(vis));
   for (i=1;i<=n;i++) 
    if ((a[i]&1)&&!vis[i]&&a[i]!=1)
  {  memset(que,0,sizeof(que));
  	  dfs(i);
  	All++;
  }
  printf("%d\n",All+1);
  memset(vis,0,sizeof(vis));
  for (i=1;i<=n;i++) 
    if ((a[i]&1)&&!vis[i]&&a[i]!=1)
  {  memset(que,0,sizeof(que));
  	  dfs(i); 
  	 for (j=0;j<=que[0];j++) printf("%d ",que[j]);
  	 printf("\n");
  }
  printf("%d ",sum);
  for (i=1;i<=n;i++) if (a[i]==1) printf("%d ",i);
  printf("\n");
  exit(0);
}
void pt()
{   int All=0;
    J=0;
    memset(vis,0,sizeof(vis));
   //for (i=1;i<=n;i++)
   // if ((a[i]&1)&&!vis[i])
  for (i=fox[st];i;i=s[i].before)
   if (!s[i].flow&&!vis[s[i].ed]&&s[i].ed<=n)
  {  memset(que,0,sizeof(que));
  	  dfs(s[i].ed);
  	All++;
  }
  printf("%d\n",All+1);
  memset(vis,0,sizeof(vis));
 for (i=fox[st];i;i=s[i].before)
   if (!s[i].flow&&!vis[s[i].ed]&&s[i].ed<=n)
  {  memset(que,0,sizeof(que));
  	  dfs(s[i].ed); 
  	 for (j=0;j<=que[0];j++) printf("%d ",que[j]);
  	 printf("\n");
  } x=0;
  for(i=1;i<=n;i++) if (!vis[i]) x++;
  printf("%d ",x);
  for (i=1;i<=n;i++) if (!vis[i]) printf("%d ",i);
  printf("\n");
  exit(0);
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
{ int ans=0; for (;spfa();) 
{ ans+=flow[ed]; doit(); } 
return ans; }
void get_first()
{ int flag=0;
  st=n+1; ed=st+1; k1=1;
  for (i=1;i<=n;i++)
    if (a[i]&1)
  { add(st,i,2,0);
    for (j=1;j<=n;j++)
      if (((a[j]&1)==0)&&prime(a[i]+a[j])) add(i,j,1,(a[i]==1&&flag)?(++R)*10000:0);
     if (a[i]==1&&!flag) flag=1,ps=i;
  }
  else add(i,ed,2,0);
  if (mincost()!=2*k) return;
  for (i=fox[st];i;i=s[i].before)
    if (s[i].ed==ps||a[s[i].ed]!=1)
      if (s[i].flow!=0) return;
  print();
}
void get_second()
{  st=n+1; ed=st+1; k1=1; 
  memset(fox,0,sizeof(fox)); memset(s,0,sizeof(s));
  if (sum<3) return;
  if ((n-sum)&1) return;
  for (i=1;i<=n;i++) 
    if (a[i]&1)
	{  if (a[i]!=1) 
	    {  add(st,i,2,0);
	        for (j=1;j<=n;j++) if ((a[j]&1)==0&&prime(a[i]+a[j])) add(i,j,1,0);
	    }
    }
	    else sky++,add(i,ed,2,0);
    if ((n-sum-sky)!=sky) return;
    if (mincost()!=2*sky) return;
    Print();
}
void get_third()
{  st=n+1; ed=st+1; k1=1;
   memset(fox,0,sizeof(fox)); memset(s,0,sizeof(s));
   if (sum<2) return;
   if ((n-sum-1)&1) return;
   x=0;
   for (i=1;i<=n;i++) if (a[i]&1&&a[i]!=1) x++;
   if (x+1!=(n-sum-x)) return;
   for (i=1;i<=n;i++) if (a[i]&1&&a[i]!=1)
   { add(st,i,2,0);  
      for (j=1;j<=n;j++)
       if ((a[j]&1)==0&&prime(a[i]+a[j]))  add(i,j,1,0);
   } else add(i,ed,2,0);
   add(st,ed+1,2,0);
   for (i=1;i<=n;i++) if ((a[i]&1)==0&&prime(a[i]+1)) add(ed+1,i,2,0);
   if (mincost()!=2*(x+1)) return;
   pt();
}
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 for (i=1;i<=n;i++) if (a[i]==1) sum++; 
 for (i=1;i<=n;i++) if (a[i]&1) k++; k=n-k;
 get_first();
 if (sum>2)
 get_second();
 if (sum>1)
 get_third();
 printf("Impossible\n");
}