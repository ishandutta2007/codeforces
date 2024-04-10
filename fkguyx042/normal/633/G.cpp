#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,fa[N],Add[N*4],st[N],ed[N],tot,Q[N],a[N],x,y,type,V,big[N];
bitset<1005>tree[N*4],B,C,D;
vector<int>v[N];
void dfs(int x)
{
	 int i;
	 st[x]=++tot; Q[++Q[0]]=x;
	 for (i=0;i<(int)v[x].size();++i)
	 {  
	      int p=v[x][i];
	      if (fa[x]==p) continue;
	      fa[p]=x;
	      dfs(p);
	}
	ed[x]=tot;
}
int prime(int x)
{
	  int i;
	  for (i=2;i*i<=x;++i) if (x%i==0) return 0;
	  return 1;
}
void build_tree(int l,int r,int t)
{
	 if (l==r) tree[t][a[Q[l]]]=1;
	 else 
	 {
	 	  build_tree(l,mid,ls); build_tree(mid+1,r,rs);
	 	  tree[t]=tree[ls]|tree[rs];
	 }
}
void add(int x,int y)
{
	 v[x].push_back(y);
}
void change(int t,int x)
{
	  tree[t]=((tree[t]<<x)|(tree[t]>>(m-x)))&D;
}
void down(int t)
{
	  if (!Add[t]) return;
	  change(ls,Add[t]); change(rs,Add[t]);
	  (Add[ls]+=Add[t])%=m;
	  (Add[rs]+=Add[t])%=m;
	  Add[t]=0;
}
void update(int ll,int rr,int c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr)
	  {
	  	  change(t,c);
	  	  (Add[t]+=c)%=m;
	  }
	  else 
	  {
	  	   down(t);
	  	   if (ll<=mid) update(ll,rr,c,l,mid,ls);
	  	   if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
	  	   tree[t]=tree[ls]|tree[rs];
	  }
}
void ask(int ll,int rr,int l,int r,int t)
{
	   if (ll<=l&&r<=rr)  B|=tree[t];
	   else 
	   {
	   	   down(t);
	   	   if (ll<=mid) ask(ll,rr,l,mid,ls);
	   	   if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	   }
}
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=0;i<m;++i) D[i]=1;
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i]%=m;
	  for (i=1;i<n;++i)
	  {
	  	  scanf("%d%d",&x,&y);
	  	  add(x,y); add(y,x);
	  }
	  for (i=2;i<=m;++i) big[i]=prime(i);
	  dfs(1); int q;
	  build_tree(1,n,1);
	  scanf("%d",&q);
	  for (;q--;)
	  {
	  	  scanf("%d",&type);
	  	  if (type==1)
	  	  {
			   scanf("%d%d",&V,&x);
			   x%=m;
			   update(st[V],ed[V],x,1,n,1);
		  }
		  else 
		  {
		  	   scanf("%d",&V); B=C;
		  	   ask(st[V],ed[V],1,n,1);
		  	   int ans=0;
		  	   for (i=2;i<m;++i) if (big[i]&&B[i]) ++ans;
		  	   printf("%d\n",ans);
		  }
	  }
}