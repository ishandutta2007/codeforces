#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,x,y,k1,tot;
struct Node{int ed,before,bh;}s[200001];
int fox[200001],top[100001];
struct Tre{int add,sum;}Tree[400001];
int bh[100001],fa[100001],son[100001],size[100001],wz[100001],deep[100001];
void down(int t)
{ if (!Tree[t].add) return;
  Tree[ls].sum+=Tree[t].add;
  Tree[rs].sum+=Tree[t].add;
  Tree[ls].add+=Tree[t].add;
  Tree[rs].add+=Tree[t].add; 
  Tree[t].add=0;
}
void add(int x,int y,int bh) {s[++k1].ed=y; s[k1].before=fox[x]; s[k1].bh=bh; fox[x]=k1; }
void dfs(int x,int f,int dep)
{  fa[x]=f; int i;
    deep[x]=dep;
   for (i=fox[x];i;i=s[i].before)
     if (s[i].ed!=fa[x])
     {   bh[s[i].bh]=s[i].ed;
         dfs(s[i].ed,x,dep+1);
           size[x]+=size[s[i].ed];
          if (!son[x]||size[son[x]]<size[s[i].ed]) son[x]=s[i].ed;
    }
size[x]++;
}
void update(int ll,int rr,int c,int l,int r,int t)
{ if (ll<=l&&r<=rr) {  Tree[t].add+=c; Tree[t].sum+=c; return; }
   down(t);
  if (ll<=mid) update(ll,rr,c,l,mid,ls);
  if (rr>mid) update(ll,rr,c,mid+1,r,rs);
}
int ask(int ll,int l,int r,int t)
{  if (l==r)  return Tree[t].sum;
down(t); 
   if (ll<=mid) return ask(ll,l,mid,ls);
   else return ask(ll,mid+1,r,rs);
}
void Dfs(int x,int tp)
{  top[x]=tp;  wz[x]=++tot;
if (son[x]) Dfs(son[x],tp);
int i;
  for (i=fox[x];i;i=s[i].before)
     if (son[x]!=s[i].ed&&s[i].ed!=fa[x])
       Dfs(s[i].ed,s[i].ed);
}
void Do(int x,int y)
{ for (;top[x]!=top[y];)
   {  if (deep[top[x]]>deep[top[y]]) swap(x,y);
      update(wz[top[y]],wz[y],1,1,n,1); y=fa[top[y]];
   }
  if (deep[x]>deep[y]) swap(x,y);
  update(wz[x],wz[y],1,1,n,1); 
  update(wz[x],wz[x],-1,1,n,1);
}
int main()
{ scanf("%d",&n);
   for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y,i),add(y,x,i);
   dfs(1,0,0);
   Dfs(1,1);
   scanf("%d",&m);
   for (i=1;i<=m;i++) 
   { scanf("%d%d",&x,&y);
     Do(x,y);
   }   
  for (i=1;i<n;i++) printf("%d\n",ask(wz[bh[i]],1,n,1));
}