#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 300005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,Pow[N],a[N],sum,sum2,flag;
struct Node{int hash[2];}tree[4*N];
void up(Node &a,Node b,Node c,int len)
{
	 a.hash[0]=(1ll*b.hash[0]*Pow[len>>1]%Mo+c.hash[0])%Mo;
	 a.hash[1]=(1ll*c.hash[1]*Pow[len-(len>>1)]%Mo+b.hash[1])%Mo;
}
void modify(int ll,int l,int r,int t)
{
	 if (l==r) tree[t].hash[0]=tree[t].hash[1]=1;
	 else 
	 {
	 	 if (ll<=mid) modify(ll,l,mid,ls);
	 	 else modify(ll,mid+1,r,rs);
	 	 up(tree[t],tree[ls],tree[rs],r-l+1);
     }
}
void ask(int ll,int rr,int &x,int l,int r,int t)
{
	 if (ll<=l&&r<=rr) x=(1ll*x*Pow[r-l+1]%Mo+tree[t].hash[1])%Mo;
	 else 
	 {
	 	 if (rr>mid) ask(ll,rr,x,mid+1,r,rs);
	 	 if (ll<=mid) ask(ll,rr,x,l,mid,ls);
     }
}
void Ask(int ll,int rr,int &x,int l,int r,int t)
{
	 if (ll<=l&&r<=rr) x=(1ll*x*Pow[r-l+1]%Mo+tree[t].hash[0])%Mo;
	 else 
	 {
	 	 if (ll<=mid) Ask(ll,rr,x,l,mid,ls);
	 	 if (rr>mid)  Ask(ll,rr,x,mid+1,r,rs);
	 }
}
int main()
{
	 int T=1;
	 for (;T--;)
	 {
	 	 Pow[0]=1; for (i=1;i<N;++i) Pow[i]=1ll*Pow[i-1]*seed%Mo;
	 	 scanf("%d",&n); flag=0;
	 	 memset(tree,0,sizeof(tree));
	 	 for (i=1;i<=n;++i) 
	 	 {
	 	 	  scanf("%d",&a[i]);
	 	 	  modify(a[i],1,n,1);
	 	 	  int l=min(a[i]-1,n-a[i]);
	 	 	  if (!l) continue;
	 	 	  ask(a[i]-l,a[i]-1,sum=0,1,n,1);
			  Ask(a[i]+1,a[i]+l,sum2=0,1,n,1);
			  if (sum!=sum2) flag=1;
		 }
		 printf(flag?"YES\n":"NO\n");
	}
}