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

#define N 500005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,r[N],a[N],b[N],c[N],id[N],next[N],sum[N],f[N],R[N];
inline bool cmp(int a,int b) { return r[a]>r[b]; }
struct Tre{int sum,id;}tree[4*N],ans;
void up(Tre &a,Tre b,Tre c)
{
	 if (b.sum<c.sum) a.sum=b.sum,a.id=b.id;
	             else a.sum=c.sum,a.id=c.id;
}
void ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) up(ans,ans,tree[t]);
	  else 
	  {
	  	  if (ll<=mid) ask(ll,rr,l,mid,ls);
	  	  if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	  }
}
void build_tree(int l,int r,int t)
{
	 if (l==r)
	 {
	 	  tree[t].id=l;
	 	  tree[t].sum=inf;
	 }
	 else 
	 {
	 	  build_tree(l,mid,ls);
	 	  build_tree(mid+1,r,rs);
	 	  up(tree[t],tree[ls],tree[rs]);
	 }
}
void modify(int ll,int c,int l,int r,int t)
{
	 if (l==r) tree[t].sum=c;
	 else 
	 {
	 	  if (ll<=mid) modify(ll,c,l,mid,ls);
	 	  else modify(ll,c,mid+1,r,rs);
	 	  up(tree[t],tree[ls],tree[rs]);
	 }
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),b[++b[0]]=a[i];
	  sort(b+1,b+n+1);
	  b[0]=unique(b+1,b+n+1)-(b+1);
	  for (i=1;i<=n;++i) a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
	  for (i=n;i;--i) { if (c[a[i]]) r[i]=c[a[i]]; c[a[i]]=i; }
	  for (i=1;i<=n;++i) id[i]=i; sort(id+1,id+n+1,cmp);
	  for (i=1;i<=n;++i) if (r[r[r[i]]]) next[i]=r[i],sum[i]=r[r[r[i]]]+1;
	  build_tree(1,n,1);
	  for (i=1;i<=n;++i)
	   if (r[id[i]])
	   {
	   	   ans.sum=inf;
	   	   if (id[i]+1<=r[id[i]]-1) ask(id[i]+1,r[id[i]]-1,1,n,1);
	   	   if (ans.sum!=inf)
	   	   {
	   	   	  if (!sum[id[i]]||sum[id[i]]>ans.sum+1)
	   	   	{
	   	   	  next[id[i]]=ans.id;
	   	   	   sum[id[i]]=ans.sum+1;
	   	     }
	   	   }
	   	   modify(id[i],r[id[i]],1,n,1);
	   }
       f[n+1]=0; R[n+1]=0; id[n+1]=n+1;
	   for (i=n;i;--i)
	   {
	       if (!next[i]) R[i]=R[i+1],id[i]=id[i+1];
	       else 
	       {
	       	    f[i]=R[sum[i]]+1;
	       	    sum[i]=id[sum[i]];
	       	    R[i]=R[i+1];
	       	    id[i]=id[i+1];
	       	    if (f[i]>R[i]) { R[i]=f[i]; id[i]=i; }
	       }
	   }
	   int ans=0,ned=0;
	   for (i=1;i<=n;++i) if (f[i]>ans) { ans=f[i]; ned=i; }
	   if (ans==0) puts("0");
	   else 
	   {
	   	  printf("%d\n",4*ans);
	   	  for (;ned!=n+1;ned=sum[ned]) printf("%d %d %d %d ",b[a[ned]],b[a[next[ned]]],b[a[ned]],b[a[next[ned]]]);
	   }
}