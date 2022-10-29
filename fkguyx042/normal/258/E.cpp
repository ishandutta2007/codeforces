#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int st[100001],ed[100001],fox[100001],vis[100001],sky[1000001],Ans[1000001];
struct Node{int ed,before;}s[1000001],syc[1000001];
struct Tre{int sum,cover;}Tree[8000001];
int Q[100001][3];
int i,j,m,n,p,k,k1,x,y,K,tot;
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
void Add(int x,int y)
{ syc[++K].ed=y; syc[K].before=sky[x]; sky[x]=K;}
void insert(int ll,int rr,int c,int l,int r,int t)
{  if (ll<=l&&r<=rr) { Tree[t].cover+=c;
        if (Tree[t].cover) Tree[t].sum=r-l+1;
        else Tree[t].sum=(l==r)?0:Tree[ls].sum+Tree[rs].sum;
}
   else { if (ll<=mid) insert(ll,rr,c,l,mid,ls);
          if (rr>mid)  insert(ll,rr,c,mid+1,r,rs);
          if (Tree[t].cover) Tree[t].sum=r-l+1;
          else Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
        }
}
void Dfs(int x)
{ vis[x]=1;
  st[x]=++tot;
  int i;
  for (i=fox[x];i;i=s[i].before)
  if (!vis[s[i].ed]) Dfs(s[i].ed);
  ed[x]=tot;
}
void dfs(int x)
{  vis[x]=1;
   int i,j;
   for (i=sky[x];i;i=syc[i].before) {
         int sum=syc[i].ed;
         insert(st[Q[sum][0]],ed[Q[sum][0]],1,1,n,1);
         insert(st[Q[sum][1]],ed[Q[sum][1]],1,1,n,1);
     }
   Ans[x]=Tree[1].sum-1;
   if (Ans[x]==-1) Ans[x]++;
   for (i=fox[x];i;i=s[i].before) 
   if (!vis[s[i].ed]) dfs(s[i].ed);
  for (i=sky[x];i;i=syc[i].before) {
         int sum=syc[i].ed;
         insert(st[Q[sum][0]],ed[Q[sum][0]],-1,1,n,1);
         insert(st[Q[sum][1]],ed[Q[sum][1]],-1,1,n,1);
     }
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
  Dfs(1);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&x,&y);
    Add(x,i);Add(y,i);
    Q[i][0]=x;
    Q[i][1]=y;
  }
  memset(vis,0,sizeof(vis));
  dfs(1);
  for (i=1;i<=n;i++) printf("%d ",Ans[i]);
}