#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005
#define M 10000005

#define ls tree[t].l
#define rs tree[t].r
#define mid (((long long)l+(long long)r)>>1ll)

using namespace std;
const int inf=(int)2e9;
struct Node{int l,r,id;}Ques[N];
struct Tre{int sum,add,l,r;}tree[M];
int l[N],p[N],i,j,m,n,k,L,tot=1,ans[N];
inline bool cmp(Node a,Node b)  { return a.l>b.l; }
void down(int t,int len)
{
	 if (!tree[t].add) return;
	 if (!ls) ls=++tot;
	 if (!rs) rs=++tot;
	 tree[ls].add=tree[rs].add=1;
	 tree[ls].sum=(len-(len>>1));
	 tree[rs].sum=len>>1;
	 tree[t].add=0;
}
void update(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr)
	  {
	  	      tree[t].sum=r-l+1;
	  	      tree[t].add=1;
	  }
	  else 
	  {
	  	 down(t,r-l+1);
	  	  if (ll<=mid)
	  	  {
	  	  	  if (!ls) ls=++tot;
	  	  	  update(ll,rr,l,mid,ls);
	  	  }
	  	  if (rr>mid) 
	  	  {
	  	  	  if (!rs) rs=++tot;
	  	  	  update(ll,rr,mid+1,r,rs);
	  	  }
	  	  tree[t].sum=tree[ls].sum+tree[rs].sum;
	  }
}
void ask(int &x,int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) x+=(r-l+1)-tree[t].sum;
	  else 
	  {
	      down(t,r-l+1);
		  if (ll<=mid)
		  {
		     if (!ls) ls=++tot;
			 ask(x,ll,rr,l,mid,ls);
		  }
		  if (rr>mid)
		  {
		  	 if (!rs) rs=++tot;
		  	 ask(x,ll,rr,mid+1,r,rs);
		  }
	 }
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d%d",&l[i],&p[i]);
	 L=n;
	 scanf("%d",&m);
	 for (i=1;i<=m;++i) scanf("%d%d",&Ques[i].l,&Ques[i].r),Ques[i].id=i;
	 sort(Ques+1,Ques+m+1,cmp); L=1;
	 for (i=n;i;--i)
	 {
	 	  update(l[i],l[i]+p[i]-1,1,inf,1);
	 	  while (L<=m&&Ques[L].l==i) ask(ans[Ques[L].id],l[i],l[Ques[L].r],1,inf,1),++L;
     }
     for (i=1;i<=m;++i) printf("%d\n",ans[i]);
}