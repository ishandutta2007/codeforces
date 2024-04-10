#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 400005
#define M 20000005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)1e9+5;
int i,j,m,n,p,k,a[N],root[N],Root[N],tot,big[N],x,y,b[N],f[N];
struct Node{int sum,l,r;}tree[M];
vector<int>v[N];
int ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) return tree[t].sum;
	  else 
	  {
	  	  int S=0;
	      if (ll<=mid) S=max(S,ask(ll,rr,l,mid,ls));
		  if (rr>mid)  S=max(S,ask(ll,rr,mid+1,r,rs));
		  return S;
	  }
}
void update(int ll,int c,int l,int r,int t,int t1)
{
	  if (l==r) tree[t].sum=c;
	  else 
	  {
	  	  if (ll<=mid)
	  	  {
	  	  	  ls=++tot;
	  	  	  tree[ls]=tree[Ls];
	  	  	  update(ll,c,l,mid,ls,Ls);
	  	  }
	  	  else 
	  	  {
	  	  	  rs=++tot;
	  	  	  tree[rs]=tree[Rs];
	  	  	  update(ll,c,mid+1,r,rs,Rs);
	  	  }
	  	  tree[t].sum=max(tree[ls].sum,tree[rs].sum);
	  	  
	  }
}
int down(int x)
{
	  int l=1,r=b[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (b[Mid]<=x) l=mid; else r=mid;
	  }
	  return l;
}
int up(int x)
{
	  int l=1,r=b[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (b[Mid]>=x) r=mid; else l=mid;
	  }
	  return r;
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),b[++b[0]]=a[i];
	 b[++b[0]]=0; b[++b[0]]=inf;
	 sort(b+1,b+b[0]+1); b[0]=unique(b+1,b+b[0]+1)-(b+1); 
	 for (i=1;i<=n;++i)
	 {
	 	 root[i]=++tot;
	 	 tree[root[i]]=tree[root[i-1]];
	 	 update(down(a[i]),ask(1,down(a[i]-1),1,b[0],root[i-1])+1,1,b[0],root[i],root[i-1]);
	 }
	 for (i=n;i;--i)
	 {
	 	  Root[i]=++tot;
	 	  tree[Root[i]]=tree[Root[i+1]];
	 	  update(up(a[i]),ask(up(a[i]+1),b[0],1,b[0],Root[i+1])+1,1,b[0],Root[i],Root[i+1]);
	 }
	 int rans=tree[root[n]].sum;
	 for (i=1;i<=n;++i) 
	 	   if (ask(1,down(a[i]-1),1,b[0],root[i-1])+ask(up(a[i]+1),b[0],1,b[0],Root[i+1])+1==rans) 
	 	   {
	 	   	   f[i]=ask(1,down(a[i]-1),1,b[0],root[i-1])+1;
	 	   	   v[f[i]].push_back(i);
	 	   }
	 for (i=1;i<=rans;++i)
	   if (v[i].size()==1) big[v[i][0]]=1;
	 for (;m--;)
	 {
	    scanf("%d%d",&x,&y);
		printf("%d\n",max(rans-big[x],ask(1,down(y-1),1,b[0],root[x-1])+ask(up(y+1),b[0],1,b[0],Root[x+1])+1));	
	 }
}