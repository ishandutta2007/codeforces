#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define Ls (t<<1)
#define Rs ((t<<1)+1)
#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1000005
#define M 15000005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,Orz[N],sa[N],sum[N],tot,T[N*4],x;
int s[N],Rank[N],wcy[N*2],High[N],root[N];
struct Tre{int l,r,sum;}tree[M];
char c[N];
long long ans;
void Sort(int j)
{
	   int i;
	   memset(sum,0,sizeof(sum));
	   for (i=1;i<=n;++i) sum[Rank[i+j]]++;
	   for (i=1;i<N;++i) sum[i]+=sum[i-1];
	   for (i=n;i;--i) Orz[sum[Rank[i+j]]--]=i;
	   memset(sum,0,sizeof(sum));
	   for (i=1;i<=n;++i) sum[Rank[i]]++;
	   for (i=1;i<N;++i) sum[i]+=sum[i-1];
	   for (i=n;i;--i) sa[sum[Rank[Orz[i]]]--]=Orz[i];
}
void get_SA()
{
	 int i,j;
	 for (i=1;i<=n;++i) wcy[i]=c[i-1]=='('?0:1;
	 for (i=1;i<=n;++i) sum[wcy[i]]++;
	 for (i=1;i<N;++i) sum[i]+=sum[i-1];
	 for (i=n;i;--i) 
	 sa[sum[wcy[i]]--]=i;
	 Rank[sa[1]]=1;
	 for (i=2,p=1;i<=n;++i)
	 {
	     if (wcy[sa[i]]!=wcy[sa[i-1]]) ++p;
		 Rank[sa[i]]=p;
	 }
	 for (j=1;j<=n;j<<=1)
	 {
	 	   Sort(j);
	 	   wcy[sa[1]]=1;
	 	   for (i=2,p=1;i<=n;++i)
	 	   {
	 	   	   if (Rank[sa[i]]!=Rank[sa[i-1]]||Rank[sa[i]+j]!=Rank[sa[i-1]+j]) ++p;
	 	   	   wcy[sa[i]]=p;
	 	   }
	 	   for (i=1;i<=n;++i) Rank[i]=wcy[i];
	 }
}
void get_High()
{
     int i,j;
	 for (i=1,j=0;i<=n;++i)
	 {
	     if (Rank[i]==1) continue;
		 while (c[i+j-1]==c[sa[Rank[i]-1]+j-1]) ++j;
		 High[Rank[i]]=j;
		 if (j) --j;
	 }
}
void build_tree(int l,int r,int t)
{
	  if (l==r) T[t]=s[l];
	  else 
	  {  
	      build_tree(l,mid,Ls); build_tree(mid+1,r,Rs);
	      T[t]=min(T[Ls],T[Rs]);
	  }
}
void update(int ll,int l,int r,int t,int t1)
{
	  if (l==r) tree[t].sum++;
	  else 
	  {
	  	    if (ll<=mid) 
	  	    {
	  	    	  ls=++tot;
	  	    	  tree[ls]=tree[tree[t1].l];
	  	    	  update(ll,l,mid,ls,tree[t1].l);
	  	    }
	  	    else 
	  	    {
	  	    	   rs=++tot;
	  	    	   tree[rs]=tree[tree[t1].r];
	  	    	   update(ll,mid+1,r,rs,tree[t1].r);
	  	    }
	  	    tree[t].sum=tree[ls].sum+tree[rs].sum;
	  }
}
int ask(int ll,int l,int r,int t,int t1)
{
	  if (l==r) return tree[t].sum-tree[t1].sum;
	  else 
	  {  
	       if (ll<=mid)  return ask(ll,l,mid,ls,tree[t1].l);
	       else return ask(ll,mid+1,r,rs,tree[t1].r);
	  }
}
int Find(int c,int ll,int rr,int l,int r,int t)
{
	   if (T[t]>=c) return 0;
	   if (l==r) return x=l,1;
	   else 
	   {
	   	     if (ll<=mid&&Find(c,ll,rr,l,mid,Ls)) return 1;
	   	     if (rr>mid&&Find(c,ll,rr,mid+1,r,Rs)) return 1;
	   	     return 0;
	   }
}
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (i=1;i<=n;++i) if (c[i-1]=='(') s[i]=s[i-1]+1; else s[i]=s[i-1]-1;
	get_SA(); get_High();
	for (i=1;i<=n;++i)
	{
		  root[i]=++tot; tree[root[i]]=tree[root[i-1]];
		  update(s[i],-n,n,root[i],root[i-1]);
	}
	build_tree(1,n,1);
	for (i=1;i<=n;++i) 
	{
		   x=n+1; Find(s[i-1],i,n,1,n,1);
		   ans+=ask(s[i-1],-n,n,root[x-1],root[i-1]);
		   if (Rank[i]==1) continue;
		   ans-=ask(s[i-1],-n,n,root[min(x-1,i+High[Rank[i]]-1)],root[i-1]);
	}
	printf("%I64d\n",ans);
}