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

#define N 200005

using namespace std;
const long long inf=(long long)1e16;
int i,j,m,n,p,k,x,y,z;
long long f[N],cost[N];
struct Tre{long long sum,add;}tree[4*N];
vector<int>sum[N],v[N];
void down(int t)
{
	  tree[ls].sum+=tree[t].add;
	  tree[rs].sum+=tree[t].add;
	  tree[ls].add+=tree[t].add;
	  tree[rs].add+=tree[t].add;
	  tree[t].add=0;
}
void update(int ll,int rr,long long c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) tree[t].sum+=c,tree[t].add+=c;
	  else 
	  {
	  	   down(t);
	  	   if (ll<=mid) update(ll,rr,c,l,mid,ls);
	  	   if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
	  	   tree[t].sum=max(tree[ls].sum,tree[rs].sum);
	  }
}
void ask(long long &x,int ll,int rr,int l,int r,int t)
{
	   if (ll<=l&&r<=rr) x=max(x,tree[t].sum);
	   else 
	   {
	   	  down(t);
	   	  if (ll<=mid) ask(x,ll,rr,l,mid,ls);
	   	  if (rr>mid)  ask(x,ll,rr,mid+1,r,rs);
	   }
}
int main()
{
	   scanf("%d%d",&n,&m);
	   for (i=1;i<=n;++i) scanf("%I64d",&cost[i]),cost[i]+=cost[i-1];
	   for (i=1;i<=m;++i)
	   {
	   	  scanf("%d%d%d",&x,&y,&z);
	   	  v[y].push_back(x);
	   	  sum[y].push_back(z);
	   }
	   for (i=1;i<=n;++i)
	   {
	   	 f[i]=f[i-1];
	   	 for (j=0;j<(int)v[i].size();++j) update(0,v[i][j]-1,sum[i][j],0,n,1);
	   	 long long ans=-(long long)1e16;
	   	 ask(ans,0,i-1,0,n,1);
	   	 f[i]=max(f[i],ans-cost[i]);
	   	 update(i,i,f[i]+cost[i],0,n,1);
	   }
	   printf("%I64d\n",f[n]);
}