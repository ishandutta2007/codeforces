#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1,K1,t,Rt,q,x,y,v;
int Tree[100001],Ans[100001];
struct Node{int ed,before,sum;}s[5000001];
Node S[200001],R[5000001];
int fox[2000001],vis[100001],prime[100001],Rox[100001],Fox[100001],deep[100001];
void Add(int x,int y) { R[++Rt].ed=y; R[Rt].before=Rox[x]; Rox[x]=Rt; }
void add(int x,int y) { S[++k1].ed=y; S[k1].before=Fox[x]; Fox[x]=k1; }
void Upd(int x,int y,int z) {s[++K1].ed=y; s[K1].before=fox[x];s[K1].sum=z; fox[x]=K1;}
void Got(int x)
{  int i;
   int y=Tree[x];
   Rox[x]=0;
   for (i=2;i*i<=y;i++)
     if (y%i==0) {
    Add(x,i);
	while (y%i==0) y/=i;}
    if (y>1) Add(x,y);
}
void Dfs(int x,int dep)
{  vis[x]=1;
   deep[x]=dep;
   int i;
   for (i=Fox[x];i;i=S[i].before)
     if (!vis[S[i].ed]) Dfs(S[i].ed,dep+1);
}
void dfs(int x)
{  int i;
     vis[x]=1;
     Ans[x]=-1;
    for (i=Rox[x];i;i=R[i].before)
      if (fox[R[i].ed])  
        if (Ans[x]==-1||deep[s[fox[R[i].ed]].sum]>deep[Ans[x]]) Ans[x]=s[fox[R[i].ed]].sum;
    for (i=Rox[x];i;i=R[i].before)
	  Upd(R[i].ed,Tree[x],x);
    for (i=Fox[x];i;i=S[i].before)
      if (!vis[S[i].ed])
       dfs(S[i].ed);
    for (i=Rox[x];i;i=R[i].before)
  fox[R[i].ed]=s[fox[R[i].ed]].before;
}
int main()
{ scanf("%d%d",&n,&q);
  for (i=1;i<=n;i++) scanf("%d",&Tree[i]);
  for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
  memset(vis,0,sizeof(vis));K1=0;
  for (i=1;i<=n;i++) Got(i);
  Dfs(1,0);
  memset(vis,0,sizeof(vis));
  dfs(1);
  for (;q--;)
  {  scanf("%d",&t);
   if (t==2)
   { scanf("%d",&p);
     scanf("%d",&Tree[p]);K1=0; Got(p);
     memset(fox,0,sizeof(fox));
	 memset(vis,0,sizeof(vis));
	 dfs(1);
   }
   else { scanf("%d",&v);
     printf("%d\n",Ans[v]);
}
}
}