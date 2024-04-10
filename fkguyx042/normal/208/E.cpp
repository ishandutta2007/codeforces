#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls Tree[t].l
#define rs Tree[t].r
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,root[200001],tot,vis[200001],st[200001],ed[200001],top,fox[200001],k1;
int fa[200001][21],deep[100001],x,y,ans;
struct Node{int l,r,sum;}Tree[5000001];
struct Bian{int ed,before;}s[1000001];
void add(int x,int y)
 {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
void update(int ll,int l,int r,int t)
{  if (l==r) Tree[t].sum++;
   else {  if (ll<=mid)
              { if (!ls) ls=++tot; update(ll,l,mid,ls); }
              else { if (!rs) rs=++tot; update(ll,mid+1,r,rs); }
        Tree[t].sum=Tree[ls].sum+Tree[rs].sum;
       }
}
void ask(int Q,int ll,int rr,int l,int r,int t)
{ if (ll<=l&&r<=rr) ans+=Q*Tree[t].sum;
 else { if (ll<=mid) ask(Q,ll,rr,l,mid,ls);
        if (rr>mid)  ask(Q,ll,rr,mid+1,r,rs);
      }
}
void Get(int x)
{ int i;
  for (i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1]; 
}
int get(int x,int y)
{  for (i=20;i>=0;i--)
    if (y>=(1<<i)) x=fa[x][i],y-=(1<<i);
    return x;
}
void dfs(int x)
{  vis[x]=1;
   st[x]=++top;
   Get(x);
   int i;
    for (i=fox[x];i;i=s[i].before)
     if (!vis[s[i].ed])
      { deep[s[i].ed]=deep[x]+1; fa[s[i].ed][0]=x;
        dfs(s[i].ed);
      }
    ed[x]=top;
}  
int main()
{ 
    scanf("%d",&n);
   for (i=0;i<=n;i++) root[i]=++tot;
   for (i=1;i<=n;i++)
   { scanf("%d",&x);  if (x>0) add(x,i),fa[i][0]=x; } 
  for (i=1;i<=n;i++)
    if(!fa[i][0]) dfs(i);
  for (i=1;i<=n;i++)
    update(st[i],1,n,root[deep[i]]);
scanf("%d",&m);
 for (;m--;)
 { scanf("%d%d",&x,&y);
   int lca=get(x,y);
   if (lca==0) { printf("0 "); continue; }
   ans=0;
   ask(1,st[lca],ed[lca],1,n,root[deep[x]]);
   //lca=get(x,y-1);
   //ask(-1,st[lca],ed[lca],1,n,root[deep[x]]);
   printf("%d ",ans-1);
 }
}