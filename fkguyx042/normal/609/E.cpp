#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 200005

using namespace std;
int tot,n,m,i,fa[N],size[N],son[N],sum[N],tree[N*4],top[N],deep[N],st[N];
long long ans,Ans[N];
struct Node{int x,y,z,id;}b[N];
map<int,int>mp[N];
vector<int>v[N];
inline bool cmp(Node a,Node b) { return a.z<b.z; }
int get(int x) { return fa[x]==x?x:fa[x]=get(fa[x]); }
void dfs(int x)
{
  int i;
  for (i=0;i<(int)v[x].size();++i)
  {
        int p=v[x][i];
        if (fa[x]==p) continue;
        sum[p]=mp[x][p];
        fa[p]=x; deep[p]=deep[x]+1; dfs(p);
        size[x]+=size[p]; if (!son[x]||size[son[x]]<size[p]) son[x]=p;
  }
  size[x]++;
}
void add(int x,int y)
{
 v[x].push_back(y); v[y].push_back(x); 
}
void Dfs(int x,int tp)
{
   top[x]=tp;
   st[x]=++tot;
   if (son[x]) Dfs(son[x],tp);
   int i;
   for (i=0;i<(int)v[x].size();++i)
     if (v[x][i]!=fa[x]&&v[x][i]!=son[x]) Dfs(v[x][i],v[x][i]);
}
void update(int ll,int c,int l,int r,int t)
{
   if (l==r) tree[t]=c;
   else 
   {
     if (ll<=mid) update(ll,c,l,mid,ls);
     else update(ll,c,mid+1,r,rs);
     tree[t]=max(tree[ls],tree[rs]);
   }
}
int ask(int ll,int rr,int l,int r,int t)
{
   if (ll<=l&&r<=rr) return tree[t];
   else 
   {
      int sum=0;
      if (ll<=mid) sum=max(sum,ask(ll,rr,l,mid,ls));
      if (rr>mid)  sum=max(sum,ask(ll,rr,mid+1,r,rs));
      return sum;
   }
}
int main()
{
   //freopen("1.in","r",stdin);
   scanf("%d%d",&n,&m);
   for (i=1;i<=m;++i) 
           scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z),b[i].id=i;
   sort(b+1,b+m+1,cmp);
   for (i=1;i<=n;++i) fa[i]=i;
   for (i=1;i<=m;++i)
   {  
       int x=b[i].x,y=b[i].y;
       if (get(x)!=get(y))
       {
           mp[x][y]=mp[y][x]=b[i].z;
           fa[get(x)]=get(y);
           add(x,y);
           ans+=b[i].z;
       }   
    }
    memset(fa,0,sizeof(fa));
    dfs(1);
    Dfs(1,1);
    for (i=1;i<=n;++i) update(st[i],sum[i],1,n,1);
    for (i=1;i<=m;++i)
    {
        int x=b[i].x,y=b[i].y,sum=0;
        while (top[x]!=top[y])
        {
                 if (deep[top[x]]<deep[top[y]]) swap(x,y);
                 sum=max(sum,ask(st[top[x]],st[x],1,n,1));
                 x=fa[top[x]];
        }
        if (deep[x]<deep[y]) swap(x,y);
        if (x!=y)
        {
            y=son[y];
            sum=max(sum,ask(st[y],st[x],1,n,1));
        }
        Ans[b[i].id]=ans-sum+b[i].z;
     }
     for (i=1;i<=m;++i) printf("%I64d\n",Ans[i]);     
}