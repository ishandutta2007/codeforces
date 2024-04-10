#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int q=1000000007;
int n,m,a[200010],w[200010],g[200010];
L f[200010],s[200010],p;
inline void add(int i,int k)
{
	//cout<<i<<" "<<k<<"!!\n";
	for(;i<=n;i+=i&-i)
	  f[i]+=k;
}
inline L sum(int i)
{
	L k=0;
	for(;i;i^=i&-i)
	  k+=f[i];
	return k;
}
inline void add2(int i,int k)
{
	for(;i<=n;i+=i&-i)
	  g[i]=(g[i]+k)%q;
}
inline int sum2(int i)
{
	L k=0;
	for(;i;i^=i&-i)
	  k+=g[i];
	return k%q;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,l,r;
	L k,u;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&a[i]);
	   a[i]=a[i]+n-i;
	   s[i]=s[i-1]+a[i];
	  }
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&w[i]);
	   add(i,w[i]);
	   add2(i,(L)w[i]*a[i]%q);
	  }
	while(m--)
	  {
	   scanf("%d",&i);
	   if(i<0)
	     {
		  i=-i;
		  scanf("%d",&j);
		  add(i,j-w[i]);
		  add2(i,(L)(j-w[i])*a[i]%q);
		  w[i]=j;
		 }
	   else
	     {
		  scanf("%d",&j);
		  u=sum(i-1);
		  k=sum(j)-u;
		  for(l=i,r=j;l<r;)
		    if((sum(l+r>>1)-u)*2>=k)
		      r=(l+r>>1);
		    else
		      l=(l+r>>1)+1;
		      //cout<<i<<" "<<j<<" "<<l<<"  "<<k<<"!!\n";
		  p=(sum(l)-sum(i-1))%q*a[l]-(sum2(l)-sum2(i-1));
		  p+=(sum2(j)-sum2(l-1))-(sum(j)-sum(l-1))%q*a[l];
		  p=(p%q+q)%q;
		  printf("%lld\n",p);
		 }
	  }
	return 0;
}