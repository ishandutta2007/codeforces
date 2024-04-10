#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define fi first
#define se second
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
vector<pair<int,int> >v[100005];
int i,j,m,n,p,k,f[100005],sum[100005],fa[100005],size[100005],son[100005];
int ux,vx,x,y,deep[100005],top[100005],st[100005],ed[100005],tot,q,Tot;
int ans[100005];
struct Que{int x,y,id,sum,dex;}Q[300005];
struct Tre{int l,r,sum,len;}Tree[1000005],Left,Right;
void add(int x,int y,int z){ v[x].push_back(make_pair(y,z)); }
void dfs(int x)
{
     int i;
     for (i=0;i<v[x].size();++i)
      {
         int p=v[x][i].fi;
         if (fa[x]!=p)
         {
                       sum[p]=v[x][i].se;
                       fa[p]=x;
                       deep[p]=deep[x]+1;
                       dfs(p);
                       size[x]+=size[p];
                       if (!son[x]||size[son[x]]<size[p]) son[x]=p;
         }
      }
      size[x]++;
}
void Dfs(int x,int tp)
{
      top[x]=tp;
      st[x]=++tot;
      if (son[x]) Dfs(son[x],tp);
      int i;
      for (i=0;i<v[x].size();++i)
      {
           int p=v[x][i].fi;
           if (p!=fa[x]&&p!=son[x]) Dfs(p,p);
      }
      ed[x]=tot;
}
inline bool cmp(Que A,Que B)
{
        if (A.dex!=B.dex) return A.dex<B.dex;
        return A.id>B.id;
}
void up(Tre &a,Tre b,Tre c)
{
       a.len=b.len+c.len;
       a.l=b.l;
       if (b.l==b.len) a.l+=c.l;
       a.r=c.r;
       if (c.r==c.len) a.r+=b.r;
       a.sum=b.sum+c.sum;
       if (b.r&&c.l)
       a.sum-=f[b.r]+f[c.l]-f[b.r+c.l];
}
void change(int ll,int l,int r,int t)
{
      if (l==r) Tree[t].l=Tree[t].r=Tree[t].sum=0;
      else 
      {
            if (ll<=mid) change(ll,l,mid,ls);
            else change(ll,mid+1,r,rs);
            up(Tree[t],Tree[ls],Tree[rs]);
      }
}
void Ask(int ll,int rr,int l,int r,int t,int type)
{
      if (ll<=l&&r<=rr)
      {
        if (!type){ 
                      swap(Tree[t].l,Tree[t].r);
                      up(Left,Left,Tree[t]);
                      swap(Tree[t].l,Tree[t].r);
        }
        else up(Right,Tree[t],Right);
      }
      else 
      {
            if (rr>mid) Ask(ll,rr,mid+1,r,rs,type);
            if (ll<=mid) Ask(ll,rr,l,mid,ls,type);
      }
}
int ask(int x,int y)
{
       Left.l=Left.r=Left.sum=Left.len=0;
       Right.l=Right.r=Right.sum=Right.len=0;
       for (;top[x]!=top[y];)
       {
             if (deep[top[x]]<deep[top[y]])
             {
                 Ask(st[top[y]],st[y],1,n,1,1);
                 y=fa[top[y]];
             }
             else 
             {
                Ask(st[top[x]],st[x],1,n,1,0);
                x=fa[top[x]];
             }
       }
       if (x!=y)
       {
                if (deep[x]<deep[y])
                {
                                    x=son[x];
                                    Ask(st[x],st[y],1,n,1,1);
                }
                else 
                {
                                    y=son[y];
                                    Ask(st[y],st[x],1,n,1,0);
                }
       }
       up(Left,Left,Right);
       return Left.sum;
}
void build_tree(int l,int r,int t)
{
      if (l==r) Tree[t].len=1,Tree[t].l=Tree[t].r=1,Tree[t].sum=f[1];
      else
      {
         build_tree(l,mid,ls);
         build_tree(mid+1,r,rs);
         up(Tree[t],Tree[ls],Tree[rs]);
      }
}
int main()
{
    scanf("%d%d",&n,&q);
    for (i=1;i<n;++i) scanf("%d",&f[i]);
    for (i=1;i<n;++i)
    { 
        scanf("%d%d%d",&ux,&vx,&x);
        add(ux,vx,x);
        add(vx,ux,x);
    }
    build_tree(1,n,1);
    dfs(1);
    Dfs(1,1);
    for (i=1;i<=n;++i) Q[++Tot].id=0,Q[Tot].sum=i,Q[Tot].dex=sum[i];
    for (i=1;i<=q;++i)
    {
        Q[++Tot].id=1;
        scanf("%d%d%d",&Q[Tot].x,&Q[Tot].y,&Q[Tot].dex);
        Q[Tot].sum=i;
    }
    sort(Q+1,Q+Tot+1,cmp);
    for (i=1;i<=Tot;++i)
     if (!Q[i].id)
        change(st[Q[i].sum],1,n,1);
      else 
      ans[Q[i].sum]=ask(Q[i].x,Q[i].y);
    for (i=1;i<=q;++i) printf("%d\n",ans[i]);
}