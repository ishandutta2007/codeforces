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

#define N 300005

using namespace std;
const long long inf=(long long)1e16;
int i,j,m,n,p,k,x,y,z,l[N],r[N],c[N],ans,L,R;
long long f[N],cost[N];
struct Tre{int sum,add,id;}tree[5*N];
vector<int>sum[N],v[N];
void down(int t)
{
	  tree[ls].sum+=tree[t].add;
	  tree[rs].sum+=tree[t].add;
	  tree[ls].add+=tree[t].add;
	  tree[rs].add+=tree[t].add;
	  tree[t].add=0;
}
void up(Tre &a,Tre &b,Tre &c)
{
	  if (b.sum>c.sum) a=b; else a=c;
	  a.add=0;
}
void build_tree(int l,int r,int t)
{
	  if (l==r) tree[t].sum=0,tree[t].id=l;
	  else 
	  {
	  	  build_tree(l,mid,ls);
	  	  build_tree(mid+1,r,rs);
	  	  up(tree[t],tree[ls],tree[rs]);
	  }
}
void update(int ll,int rr,int c,int l,int r,int t)
{
	    if (ll<=l&&r<=rr) tree[t].sum+=c,tree[t].add+=c;
	    else 
	    {
	    	  down(t);
	    	  if (ll<=mid) update(ll,rr,c,l,mid,ls);
	    	  if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
	    	  up(tree[t],tree[ls],tree[rs]);
	    }
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d%d%d",&x,&y,&z),v[x].push_back(y),sum[x].push_back(z),v[y+1].push_back(-y),sum[y+1].push_back(z),
	  l[i]=x,r[i]=y,c[i]=z;
	  build_tree(1,N,1);
	  for (i=1;i<N;++i)
	  {
	  	    for (j=0;j<(int)v[i].size();++j)
	  	        if (v[i][j]>0)
	  	            update(v[i][j],sum[i][j],1,1,N,1);
	  	        else update(-v[i][j],sum[i][j],-1,1,N,1);
	        if (tree[1].sum>ans) ans=tree[1].sum,L=i,R=tree[1].id;
	  }
	  printf("%d\n",ans);
	  for (i=1;i<=n;++i) if (l[i]<=L&&L<=r[i]&&r[i]<=R&&R<=c[i]) printf("%d ",i);
}