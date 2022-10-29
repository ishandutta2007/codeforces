#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 150005
#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,tot,x,h,l,r,z;
double ans,sum;
struct Node{int l,r;double sum;}tree[N*40];
void ask(int ll,int l,int r,int t)
{
	 sum*=tree[t].sum;
	 if (l==r) return;
	 if (ll<=mid) ask(ll,l,mid,ls);
	 else ask(ll,mid+1,r,rs);
}
void update(int ll,int rr,double c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) tree[t].sum*=c;
	  else 
	  {
	  	  if (ll<=mid) 
	  	  {
	  	  	 if (!ls) ls=++tot;
	  	  	 update(ll,rr,c,l,mid,ls);
	  	  }
	  	  if (rr>mid)
	  	  {
	  	  	 if (!rs) rs=++tot;
	  	  	 update(ll,rr,c,mid+1,r,rs);
	  	  }
	  }
}
int main()
{
	 scanf("%d%d",&n,&m);
	 tot=1;
	 for (i=0;i<N*40;++i) tree[i].sum=1.;
	 for (;n--;)
  {
  	  scanf("%d%d%d%d",&x,&h,&l,&r);
  	  update(x-h,x-1,1-1.*l/100.,-inf,inf,1);
  	  update(x+1,x+h,1-1.*r/100.,-inf,inf,1);
  }
     for (;m--;)
  {
  	  scanf("%d%d",&x,&z);
      sum=1.;
  	  ask(x,-inf,inf,1);
  	  ans+=sum*z;
  }
  printf("%.10lf\n",ans);
}