#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define ls(x) tree[x].l
#define rs(x) tree[x].r
#define mid ((l+r)>>1)

#define N 100005
#define M 10000005
#define K 16

using namespace std;

vector<int>v[N],son[N];
int i,j,m,n,p,k,root[N],fa[N][K+5],tot,deep[N],q,x,y;
struct Tre{int l,r,sum;}tree[M];
int get(int x)
{
	  int i;
	 for (i=1;i<=K;++i)  fa[x][i]=fa[fa[x][i-1]][i-1];
}
void update(int ll,int l,int r,int t,int t1)
{
	  if (l==r) tree[t].sum++;
	  else 
	  {
	  	    tree[t].sum++;
	  	    if (ll<=mid) 
	  	    {
	  	    	  ls(t)=++tot;
	  	    	  tree[tot]=tree[ls(t1)];
	  	    	  update(ll,l,mid,ls(t),ls(t1));
	  	    }
	  	    else 
	  	    {
	  	    	  rs(t)=++tot;
	  	    	  tree[tot]=tree[rs(t1)];
	  	    	  update(ll,mid+1,r,rs(t),rs(t1));
	  	    }
	  }
}
int getfa(int x,int y)
{
	  int i,k;
	  if (deep[x]<deep[y]) swap(x,y);
	  for (i=K,k=deep[x]-deep[y];i>=0;--i)
	    if (k&(1<<i)) x=fa[x][i];
	  if (x==y) return x;
	  for (i=K;i>=0;--i)
	    if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	   return fa[x][0];
}
void dfs(int x)
{
	 int i;
	 get(x);
	 root[x]=++tot;
	 tree[root[x]]=tree[root[fa[x][0]]];
	 for (i=0;i<(int)son[x].size();++i)
	 {
	 	   int Root=++tot; tree[Root]=tree[root[x]];
	 	   update(son[x][i],1,m,Root,root[x]);
	 	   root[x]=Root;
	 }
	 for (i=0;i<(int)v[x].size();++i)
	   if (fa[x][0]!=v[x][i])
	{
		    int p=v[x][i];
		    fa[p][0]=x;
		    deep[p]=deep[x]+1;
		    dfs(p);
	}
}
void ask(int p,int l,int r,int t,int t1,int t2,int t3)
{
	 if (l==r) printf(" %d",l);
	 else 
	 {
	 	   int sum=tree[ls(t)].sum+tree[ls(t1)].sum-tree[ls(t2)].sum-tree[ls(t3)].sum;
	 	   if (sum>=p) ask(p,l,mid,ls(t),ls(t1),ls(t2),ls(t3));
	 	   else ask(p-sum,mid+1,r,rs(t),rs(t1),rs(t2),rs(t3));
	 }
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i=1;i<=m;++i) scanf("%d",&x),son[x].push_back(i); 
	dfs(1);
	for (;q--;)
{
	  scanf("%d%d%d",&x,&y,&k);
	  int lca=getfa(x,y),plca=fa[lca][0];
	  k=min(k,tree[root[x]].sum+tree[root[y]].sum-tree[root[lca]].sum-tree[root[plca]].sum);
	  printf("%d",k);
	  for (i=1;i<=k;++i) ask(i,1,m,root[x],root[y],root[lca],root[plca]);
	  puts("");
}
}