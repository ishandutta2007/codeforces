#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define Ls (t<<1)
#define Rs ((t<<1)|1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 400005
#define M 200005
#define W 8000005
#define seed 23333
#define Mo 998244353

using namespace std;
int root[N],tot,q,l,r,L,R,ls[W],rs[W],id[W],tree[W];
int i,j,m,n,p,k,b[N],h[N],syc[N],c[N],sum[M+5],sa[N],rank[N],Orz[N],high[N];
void Sort(int j)
{
	  int i;
	  memset(sum,0,sizeof(sum));
	  for (i=1;i<=c[0];++i) sum[rank[i+j]]++;
	  for (i=1;i<=M;++i) sum[i]+=sum[i-1];
	  for (i=c[0];i;--i) Orz[sum[rank[i+j]]--]=i;
	  memset(sum,0,sizeof(sum));
	  for (i=1;i<=c[0];++i) sum[rank[i]]++;
	  for (i=1;i<=M;++i) sum[i]+=sum[i-1];
	  for (i=c[0];i;--i) sa[sum[rank[Orz[i]]]--]=Orz[i];
}
void get_sa()
{
	  int i,j;
	  for (i=1;i<=c[0];++i) syc[i]=c[i];
	  for (i=1;i<=c[0];++i) sum[syc[i]]++;
	  for (i=1;i<=M;++i) sum[i]+=sum[i-1];
	  for (i=c[0];i;--i) sa[sum[syc[i]]--]=i;
	  rank[sa[1]]=1;
	  for (i=2,p=1;i<=c[0];++i)
	 {
	 	   if (c[sa[i]]!=c[sa[i-1]]) ++p;
		   rank[sa[i]]=p;
	 }
	  for (j=1;j<=c[0];j<<=1)
	  {
	  	   Sort(j);
	  	   syc[sa[1]]=1;
	  	   for (i=2,p=1;i<=c[0];++i)
	  	   {
	  	   	  if (rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+j]!=rank[sa[i-1]+j]) ++p;
	  	   	  syc[sa[i]]=p;
	  	   }
	  	   for (i=1;i<=c[0];++i) rank[i]=syc[i];
	  }
}
void get_high()
{
	int i,j;
	for (i=1,j=0;i<=c[0];++i)
	{
		   if (rank[i]==1) continue;
		   while (c[i+j]==c[sa[rank[i]-1]+j]) ++j;
		   high[rank[i]]=j; if (j) --j;
	}
}
void cop(int x,int y)
{
	  ls[x]=ls[y]; rs[x]=rs[y]; id[x]=id[y];
}
void update(int ll,int l,int r,int t,int T)
{
    if (l==r) id[t]++;
    else 
    {
    	  if(ll<=mid) 
    	  {
    	  	  ls[t]=++tot;
    	  	  cop(ls[t],ls[T]);
    	  	  update(ll,l,mid,ls[t],ls[T]);
    	  }
    	  else 
    	  {
    	  	  rs[t]=++tot;
    	  	  cop(rs[t],rs[T]);
    	  	  update(ll,mid+1,r,rs[t],rs[T]);
    	  }
    	  id[t]=id[ls[t]]+id[rs[t]];
    }
}
int ask(int ll,int rr,int l,int r,int t,int T)
{  
   if (ll<=l&&r<=rr) return id[t]-id[T];
   else 
   {
   	    int S=0;
   	    if (ll<=mid) S+=ask(ll,rr,l,mid,ls[t],ls[T]);
   	    if (rr>mid)  S+=ask(ll,rr,mid+1,r,rs[t],rs[T]);
   	    return S;
   }
}  	
int askl(int c,int ll,int rr,int l,int r,int t)
{
	  if (tree[t]>=c) return 0;
	  if (l==r) 
	  {
	  L=l;return 1;
	  }
	  else if (ll<=l&&r<=rr) return askl(c,ll,rr,mid+1,r,Rs)||askl(c,ll,rr,l,mid,Ls);
	  else 
	  {
	  	   if (rr>mid&&askl(c,ll,rr,mid+1,r,Rs)) return 1;
	  	   if (ll<=mid&&askl(c,ll,rr,l,mid,Ls)) return 1;
	  	   return 0;
	  }
}
int askr(int c,int ll,int rr,int l,int r,int t)
{
	  if (tree[t]>=c) return 0;
	  if (l==r) 
	  { 
	  R=l-1; return 1; 
	  }
	  else if (ll<=l&&r<=rr) return askr(c,ll,rr,l,mid,Ls)||askr(c,ll,rr,mid+1,r,Rs);
	  else 
	  {
	  	   if (ll<=mid&&askr(c,ll,rr,l,mid,Ls)) return 1;
	  	   if (rr>mid&&askr(c,ll,rr,mid+1,r,Rs)) return 1;
	  	   return 0;
	  }
}
void work(int x,int y)
{
	   askl(y,1,rank[x],1,c[0],1);
	   if (rank[x]!=c[0])
	   R=c[0],askr(y,rank[x]+1,c[0],1,c[0],1);
	   else R=c[0];
}
void build_tree(int l,int r,int t)
{
	  if (l==r) tree[t]=high[l];
	  else
	  {
	  	  build_tree(l,mid,Ls); build_tree(mid+1,r,Rs);
	  	  tree[t]=min(tree[Ls],tree[Rs]);
	  }
}
int main()
{
//	  freopen("1.in","r",stdin);
//	  freopen("1.out","w",stdout);
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&h[i]);
	  for (i=1;i<n;++i) c[++c[0]]=h[i]-h[i+1]; c[++c[0]]=(int)1e9+5;
	  for (i=1;i<n;++i) c[++c[0]]=h[i+1]-h[i];
	  memcpy(b,c,sizeof(b));
	  sort(b+1,b+b[0]+1); b[0]=unique(b+1,b+b[0]+1)-(b+1);
	  for (i=1;i<=c[0];++i) c[i]=lower_bound(b+1,b+b[0]+1,c[i])-b;
	  get_sa(); get_high(); build_tree(1,c[0],1);
	  for (i=1;i<=c[0];++i)
	  {
	  	    root[i]=++tot;
	  	    cop(root[i],root[i-1]);
			update(rank[i],1,c[0],root[i],root[i-1]);
	  }
	  scanf("%d",&q);
	  for (;q--;)
	  {
	      scanf("%d%d",&l,&r);  if (l==r) { printf("%d\n",n-1); continue; }
	      r--;
		  work(l,r-l+1);	
	      int lx=l-(r-l+1)-1,ans=0;
          if (lx>=1) ans+=ask(L,R,1,c[0],root[lx+n],root[n]);
          if (r+1	<n)   ans+=ask(L,R,1,c[0],root[c[0]],root[r+n+1]);
          printf("%d\n",ans);
	  }
}