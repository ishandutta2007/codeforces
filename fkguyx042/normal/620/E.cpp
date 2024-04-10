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

#define N 400005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
vector<int>v[N];
int i,j,m,n,p,k,col[N],vis[N],st[N],ed[N],tot,x,y;
int type,u,c;
long long tree[N*4],Add[N*4];
void add(int x,int y) { v[x].push_back(y); }
void down(int t)
{
	  if(!Add[t]) return;
	  tree[ls]=Add[ls]=tree[rs]=Add[rs]=Add[t];
	  Add[t]=0;
}
void dfs(int x)
{  
   int i;
   vis[x]=1; st[x]=++tot;
   for (i=0;i<(int)v[x].size();++i)
     if (!vis[v[x][i]]) dfs(v[x][i]);
   ed[x]=tot;
}
void update(long long c,int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) Add[t]=tree[t]=c;
	  else 
	  {
	  	  down(t);
	  	  if(ll<=mid) update(c,ll,rr,l,mid,ls);
	  	  if(rr>mid)  update(c,ll,rr,mid+1,r,rs);
	  	  tree[t]=tree[ls]|tree[rs];
	  }
}
long long ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) return tree[t];
	  else
	  {
	  	 down(t); long long S=0;
	  	 if(ll<=mid) S|=ask(ll,rr,l,mid,ls);
	  	 if(rr>mid)  S|=ask(ll,rr,mid+1,r,rs);
	  	 return S;
	  }
}
int Mc(long long c)
{
	  int sum=0;
	  while (c) sum+=c&1ll,c>>=1ll;
	  return sum;
}
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=n;++i) scanf("%d",&col[i]); 
	  for (i=1;i<n;++i)
	  {
	  	  scanf("%d%d",&x,&y);
	  	  add(x,y); add(y,x);
	  }
	  dfs(1);
	  for (i=1;i<=n;++i) update(1ll<<col[i],st[i],st[i],1,n,1);
	  for (;m--;)
	  {
	  	  scanf("%d%d",&type,&u);
		  if (type==1)
		  {
		     scanf("%d",&c);
			 update(1ll<<c,st[u],ed[u],1,n,1);
		  }
		  else printf("%d\n",Mc(ask(st[u],ed[u],1,n,1)));
	  }
}