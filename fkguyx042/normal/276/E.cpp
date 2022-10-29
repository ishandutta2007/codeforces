#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,x,y,k1,tot,v,d,Rx,Ry,X;
int Tree[400001];
struct Tre{int sum,add;}tree[400001];
int deep[100001],Maxdeep[100001],fox[100001];
int fa[100001][21],son[100001][21],Rt[100001];
struct Node{int ed,before;}s[200001];
void add(int x,int y) { s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
void Got(int x)
{ int i; for (i=1;i<=(int)log2(deep[x]);i++)
            fa[x][i]=fa[fa[x][i-1]][i-1];
}
void Todo(int x)
{int i; for (i=1;i<=(int)log2(Maxdeep[x]-deep[x]);i++)
          son[x][i]=son[son[x][i-1]][i-1];
}
void down(int t)
{ if (!tree[t].add) return;
tree[ls].add+=tree[t].add;
tree[rs].add+=tree[t].add;
tree[ls].sum+=tree[t].add;
tree[rs].sum+=tree[t].add;
tree[t].add=0;
}
void dfs(int x)
{  deep[x]=deep[fa[x][0]]+1;
    if (x==1) deep[x]--;
    Rt[x]=++tot;
    Got(x);
   int i;
     for (i=fox[x];i;i=s[i].before)
      if (s[i].ed!=fa[x][0])
      {     fa[s[i].ed][0]=x;
           dfs(s[i].ed);
           Maxdeep[x]=Maxdeep[s[i].ed];
           if (x!=1) son[x][0]=s[i].ed,Todo(x);
      }
    Maxdeep[x]=max(Maxdeep[x],deep[x]);
}       
int Gotson(int x,int k)
{  int i;
  for (i=20;i>=0;i--)
    if (k>=(1<<i))
       { k-=(1<<i);
          x=son[x][i];
       }
  return x;
}
int Gotfa(int x,int k)
{  int i;
  for (i=20;i>=0;i--)
    if (k>=(1<<i))
       { k-=(1<<i);
          x=fa[x][i];
       }
  return x;
}
int ask(int ll,int l,int r,int t)
{ if (l==r) return tree[t].sum;
   down(t);
   if (ll<=mid) return ask(ll,l,mid,ls);
   else return ask(ll,mid+1,r,rs);
}
void update(int ll,int rr,int x,int l,int r,int t)
{  if (ll<=l&&r<=rr) { tree[t].sum+=x; tree[t].add+=x; return; }
    down(t);
    if (ll<=mid) update(ll,rr,x,l,mid,ls);
    if (rr>mid) update(ll,rr,x,mid+1,r,rs);
}
int lowbit(int x) { return x&-x;}
void insert(int x,int y)
{ for (;x<=n;x+=lowbit(x)) Tree[x]+=y; }
int Query(int x)
{ int sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
int main()
{ scanf("%d%d",&n,&m);
 for (i=1;i<n;i++)
 {   scanf("%d%d",&x,&y);
     add(x,y);add(y,x);
 }
 dfs(1);
 for (i=1;i<=m;i++)
 {  scanf("%d",&x);
    if (x==0)
    {    scanf("%d%d%d",&v,&x,&d);
        if (v!=1)
        {   if (d>=deep[v]) 
           {  insert(n-(d-deep[v]+1)+1,x);
              int R=d-deep[v];R++;
              if (R<=min(Maxdeep[v],deep[v]+d))
              {  Ry=Gotson(v,min(Maxdeep[v]-deep[v],d));
                 if (R<deep[v]) Rx=Gotfa(v,deep[v]-R);
                 else  Rx=Gotson(v,R-deep[v]); 
                update(Rt[Rx],Rt[Ry],x,1,n,1);
           }
           } 
          else  {
        int R=min(Maxdeep[v]-deep[v],d);
        update(Rt[v],Rt[Gotson(v,R)],x,1,n,1);
        R=min(deep[v]-1,d);
        update(Rt[Gotfa(v,R)],Rt[v],x,1,n,1);
        update(Rt[v],Rt[v],-x,1,n,1);
        }
      }
        else  insert(n-(d+1)+1,x);         
    }
    else { scanf("%d",&v);
           printf("%d\n",ask(Rt[v],1,n,1)+(X=Query(n-(deep[v]+1)+1)));
}
}
}