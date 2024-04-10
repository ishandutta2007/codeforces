#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 200005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

using namespace std;
long long ans;
int i,j,m,n,p,k,a[N],b[N];
struct Node{int x,y;}A[N];
int tree[N*4],add[N*4];
vector<int>v[N];

void build_tree(int l,int r,int t)
{
	  tree[t]=r-l+1;
	  if (l==r) return;
	  build_tree(l,mid,ls); build_tree(mid+1,r,rs);
}
void down(int t,int len)
{
	 if (!add[t]) return;
	 tree[ls]=(len-(len>>1))-tree[ls];
	 tree[rs]=(len>>1)-tree[rs];
	 add[ls]^=1; add[rs]^=1; add[t]^=1;
}
void reserve(int ll,int rr,int l,int r,int t)
{
	 if (ll<=l&&r<=rr) 
	 {
	 	   
           tree[t]=r-l+1-tree[t];
	 	   add[t]^=1;
	 }
	 else 
	 {
	 	  down(t,r-l+1);
	 	  if (ll<=mid) reserve(ll,rr,l,mid,ls);
	 	  if (rr>mid)  reserve(ll,rr,mid+1,r,rs);
	 	  tree[t]=tree[ls]+tree[rs];
	 }
}
int ask(int ll,int rr,int l,int r,int t)
{
	if (ll<=l&&r<=rr) return tree[t];
	else 
	{
		 down(t,r-l+1);
		 int sum=0;
		 if (ll<=mid) sum+=ask(ll,rr,l,mid,ls);
		 if (rr>mid)  sum+=ask(ll,rr,mid+1,r,rs);
		 return sum;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[n+1]=(1e9)+1;
	for (i=1;i<=m;++i)
  {
  	 scanf("%d%d",&A[i].x,&A[i].y);
  	 int end=lower_bound(a+1,a+n+2,A[i].y+1)-a;
  	 int str=lower_bound(a+1,a+n+2,A[i].x)-a;
  	 A[i].x=lower_bound(a+1,a+n+2,A[i].x)-a;
  	 A[i].y=upper_bound(a+1,a+n+2,A[i].y)-(a+1);
  	 v[str].push_back(i);
  	 v[end].push_back(i);
  }
  ans=1ll*n*(n-1)*(n-2)/6;
  build_tree(1,n,1);
   for (i=1;i<=n;++i)
   {
   	  for (j=0;j<(int)v[i].size();++j)
   	    {
   	    	 p=v[i][j];
		     if (A[p].x<=A[p].y) 
			   reserve(A[p].x,A[p].y,1,n,1);
		}
	   int sum=0;
	   if (i>1)
	    sum=ask(1,i-1,1,n,1);
	   if (i<n)
	    sum+=n-i-ask(i+1,n,1,n,1);
	   ans-=1ll*sum*(sum-1)/2;
   }
  printf("%I64d\n",ans);
}