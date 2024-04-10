#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int top[500001],st[500001],ed[500001],fa[500001],son[500001],size[500001],x,y;
int i,j,m,n,p,k,fox[500001],k1,tot;
struct Node{int ed,before;}s[1000001];
struct Tre{int sum,add;}Tree[2000001];
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x];fox[x]=k1; }
void dfs(int x,int f)
{  fa[x]=f; int i;
   for (i=fox[x];i;i=s[i].before)
   if (s[i].ed!=fa[x]){ dfs(s[i].ed,x); size[x]+=size[s[i].ed];
     if (!son[x]||size[son[x]]<size[s[i].ed]) son[x]=s[i].ed;
  }
  size[x]++;
}
void down(int t)
{ if (Tree[t].add==-1) return;
  Tree[ls].add=Tree[rs].add=Tree[t].add;
  Tree[ls].sum=Tree[rs].sum=Tree[t].add;
  Tree[t].add=-1;
}
void Dfs(int x,int tp)
{    top[x]=tp;
     st[x]=++tot;
     if (son[x]) Dfs(son[x],tp); int i;
     for (i=fox[x];i;i=s[i].before)
      if (son[x]!=s[i].ed&&fa[x]!=s[i].ed)
        Dfs(s[i].ed,s[i].ed);
      ed[x]=tot;
}
void Up(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) Tree[t].sum=Tree[t].add=1;
  else {
          down(t);
          if (ll<=mid) Up(ll,rr,l,mid,ls);
          if (rr>mid)  Up(ll,rr,mid+1,r,rs);
          Tree[t].sum=Tree[ls].sum&Tree[rs].sum;
       }
}
void Tp(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) Tree[t].sum=Tree[t].add=0;
  else {
          down(t);
          if (ll<=mid) Tp(ll,rr,l,mid,ls);
          if (rr>mid)  Tp(ll,rr,mid+1,r,rs);
          Tree[t].sum=Tree[ls].sum&Tree[rs].sum;
       }
}
int Ask(int ll,int l,int r,int t)
{ if (l==r) return Tree[t].sum;
  down(t);
  if (ll<=mid) return Ask(ll,l,mid,ls); else return Ask(ll,mid+1,r,rs);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=2000000;i++) Tree[i].add=-1;
  for (i=1;i<n;i++)
  { scanf("%d%d",&x,&y);
    add(x,y),add(y,x);
  } 
  dfs(1,-1);
  Dfs(1,1);
  scanf("%d",&m);
  for (i=1;i<=m;i++)
{ scanf("%d%d",&x,&y);
  if(x==1)
    Up(st[y],ed[y],1,n,1);
  else if (x==2)
  {  for (;top[y]!=1;y=fa[top[y]]) Tp(st[top[y]],st[y],1,n,1);
     Tp(st[1],st[y],1,n,1);
  }
  else {
    printf("%d\n",Ask(st[y],1,n,1));
}
}
}