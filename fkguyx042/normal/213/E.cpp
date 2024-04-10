#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

#define mo 233333333
#define Mo 998244353

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)

#define seed 1000003
#define Seed 2333333

#define N 200005
#define M 200005

using namespace std;
int i,j,m,n,p,k,pow[N],Pow[N],a[N],b[N],c[N];
int hash,Hash,ans;
struct Tre{int suml,sumr,sum,hash,Hash;}tree[4*N];
void up(Tre &a,Tre &b,Tre &c)
{
	 if (!b.sum) a=c;
	 else if (!c.sum) a=b;
	 else 
	 {
	    a.sum=b.sum+c.sum;
	    a.suml=b.suml;
	    a.sumr=c.sumr;
	    a.hash=(1ll*b.hash*pow[c.sum]%mo+c.hash)%mo;
		a.hash=(a.hash+1ll*(b.sumr-c.suml+mo)*pow[c.sum-1]%mo)%mo;
		a.Hash=(1ll*b.Hash*Pow[c.sum]%Mo+c.Hash)%Mo;
		a.Hash=(a.Hash+1ll*(b.sumr-c.suml+Mo)*Pow[c.sum-1]%Mo)%Mo;
	 }
}
void update(int ll,int c,int l,int r,int t)
{
	  if (l==r)
	  {
	  	  tree[t].suml=tree[t].sumr=c;
	  	  tree[t].sum=(c>0);
	  }
	  else 
	  {
	  	  if (ll<=mid) update(ll,c,l,mid,ls); else update(ll,c,mid+1,r,rs);
	  	  up(tree[t],tree[ls],tree[rs]);
	  }
}
int main()
{
	 scanf("%d%d",&n,&m);
	 pow[0]=Pow[0]=1;
	 for (i=1;i<=n;++i) pow[i]=1ll*pow[i-1]*seed%mo,
	 Pow[i]=1ll*Pow[i-1]*Seed%Mo;
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=1;i<=m;++i) scanf("%d",&b[i]);
	 if (n==1) printf("%d\n",m);
	 else 
	 {
	 	for (i=1;i<n;++i)
	 	{
	 		  hash=(1ll*hash*seed%mo+(a[i]-a[i+1]+mo))%mo;
	 		  Hash=(1ll*Hash*Seed%Mo+(a[i]-a[i+1]+Mo))%Mo;
	 	}
	 	for (i=1;i<=m;++i) c[b[i]]=i;
	 	for (i=1;i<n;++i) update(c[i],i,1,m,1);
	 	for (i=1;i<=m;++i)
	 	 if (i+n-1<=m)
	 	{
	 		   update(c[i+n-1],i+n-1,1,m,1);
	 		   if (tree[1].hash==hash&&tree[1].Hash==Hash) ++ans;
	 		   update(c[i],0,1,m,1);
	 	}
	 	printf("%d\n",ans);
     }
}