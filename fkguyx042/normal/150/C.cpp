
#include<cstdio>
#include<algorithm>
#include<cstring>

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 160005
using namespace std;
long long x[N],p[N],ans;
int n,m,c,i,j,a,b;
struct Tre{
	  long long suml,sumr,sum,Max;
}tree[4*N],Ans;
void up(Tre &a,Tre b,Tre c)
{
	  a.sum=b.sum+c.sum;
	  a.Max=max(max(b.Max,c.Max),b.sumr+c.suml);
	  a.suml=max(b.suml,b.sum+c.suml);
	  a.sumr=max(c.sumr,c.sum+b.sumr);
}
void update(int ll,int rr,int l,int r,int  t)
{
	  if (ll<=l&&r<=rr) up(Ans,Ans,tree[t]);
	  else 
	  {
	  	  if (ll<=mid) update(ll,rr,l,mid,ls);
	  	  if (rr>mid)  update(ll,rr,mid+1,r,rs);
	  }
}
void build_tree(int l,int r,int t)
{
	  if (l==r) tree[t].sum=p[l],tree[t].sum,tree[t].Max=tree[t].suml=tree[t].sumr=max(0ll,p[l]);
	  else 
	  {
	  	  build_tree(l,mid,ls); build_tree(mid+1,r,rs);
	      up(tree[t],tree[ls],tree[rs]);
	  }
}
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for (i=1;i<=n;++i) scanf("%I64d",&x[i]),x[i-1]=(x[i]-x[i-1])*50ll;
	for (i=1;i<n;++i) scanf("%I64d",&p[i]),p[i]=p[i]*c,p[i]=x[i]-p[i];
	--n;
	build_tree(1,n,1);
	for (;m--;)
	{
		  scanf("%d%d",&a,&b);
		  Ans.sum=Ans.suml=Ans.sumr=Ans.Max=0;
		  update(a,b-1,1,n,1); ans+=max(0ll,Ans.Max);
	}
	printf("%.10lf\n",1.*ans/100.);
}