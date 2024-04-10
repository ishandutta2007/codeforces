#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)

using namespace std;
int i,j,m,n,p,k,h,len,end[N],a[N],b[N],ans;
inline bool cmp(int a,int b) { return a>b; }
int tree[4*N],add[4*N];
void build_tree(int l,int r,int t)
{
	  if (l==r) tree[t]=-(len-l+1);
	  else 
	  {
	  	  build_tree(l,mid,ls);
	  	  build_tree(mid+1,r,rs);
	  	  tree[t]=tree[ls];
	  }
}
void down(int t)
{
	 tree[ls]+=add[t]; tree[rs]+=add[t]; add[ls]+=add[t]; add[rs]+=add[t]; add[t]=0;
}
void ins(int ll,int rr,int c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) tree[t]+=c,add[t]+=c;
	  else 
	  {
	  	   down(t);
	  	   if (ll<=mid) ins(ll,rr,c,l,mid,ls);
	  	   if (rr>mid)  ins(ll,rr,c,mid+1,r,rs);
	  	   tree[t]=min(tree[ls],tree[rs]);
	  }
}
int main()
{
	 scanf("%d%d%d",&n,&len,&h);
	 for (i=1;i<=len;++i) scanf("%d",&a[i]);
	 for (i=1;i<=n;++i)   scanf("%d",&b[i]);
	 sort(a+1,a+len+1,cmp);
	 for (i=1;i<=n;++i)
	 {
	 	  if (a[1]+b[i]<h) { end[i]=0; continue; }
	 	  int l=1,r=len+1,Mid=0;
	 	  for (;(l+r)>>1!=Mid;)
	 	  {
	 	  	 Mid=(l+r)>>1;
	 	  	 if (a[Mid]+b[i]>=h) l=Mid; else r=Mid;
	 	  }
	 	  end[i]=l;
	 }
	 build_tree(1,len,1);
	 for (i=1;i<len;++i) 
	   if (end[i]) ins(1,end[i],1,1,len,1);
	 for (;i<=n;++i)
	 {
	 	    if (end[i-len]) ins(1,end[i-len],-1,1,len,1);
	 	    if (end[i])     ins(1,end[i],1,1,len,1);
	 	    if (tree[1]>=0) ++ans;
	 }
	 printf("%d\n",ans);
}