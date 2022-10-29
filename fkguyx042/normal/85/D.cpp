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
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 4000005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,x,tot=1;
struct Tre{long long sum[5];int l,r,num;}tree[M];
char c[10];
void up(Tre &a,Tre b,Tre c)
{
	  int i;
	  for (i=0;i<5;++i) a.sum[i]=b.sum[i];
	  a.num=b.num+c.num;
	  for (i=0;i<5;++i) a.sum[(i+b.num)%5]+=c.sum[i];
}
void update(int ll,int c,int l,int r,int t)
{
	  if (l==r) tree[t].sum[1]+=c,tree[t].num+=(c>0?1:-1);
	  else 
	  {
	  	    if (ll<=mid) 
			  { 
			      if (!ls) ls=++tot;
			      update(ll,c,l,mid,ls);
			  }
	  	    else 
			  {
			  	  if (!rs) rs=++tot;
			     update(ll,c,mid+1,r,rs);
			  }
	  	    up(tree[t],tree[ls],tree[rs]);
	  }
}
int main()
{
	 scanf("%d",&n);
	 for (;n--;)
	 {
	 	   scanf("%s",c);
	 	   if (c[0]=='s') printf("%I64d\n",tree[1].sum[3]);
		   else if (c[0]=='a') scanf("%d",&x),update(x,x,1,inf,1);
		   else if (c[0]=='d') scanf("%d",&x),update(x,-x,1,inf,1);
     }
}