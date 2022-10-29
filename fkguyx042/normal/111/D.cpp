#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 2005
#define M 1000005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,fac[M],rev[M],f[N],ans;
int cal(int x,int y)
{
	 if (x<y) return 0;
	 return 1ll*fac[x]*rev[y]%Mo*rev[x-y]%Mo;
}
int power(int x,int y)
{
	 int sum=1;
	 for (;y;y>>=1)
	 {
	 	 if (y&1) sum=1ll*sum*x%Mo;
	 	 x=1ll*x*x%Mo;
	 }
	 return sum;
}
void pre()
{
	  int i,j;
	  fac[0]=fac[1]=1;
	  for (i=2;i<M;++i) fac[i]=1ll*fac[i-1]*i%Mo;
	  rev[M-1]=power(fac[M-1],Mo-2);
	  for (i=M-2;i>=0;--i) rev[i]=1ll*rev[i+1]*(i+1)%Mo;
	  f[1]=1;
	  for (i=2;i<N;++i) 
	  {
	  	  f[i]=power(i,n); 
	  	  for (j=1;j<i;++j) f[i]=(f[i]-1ll*cal(i,j)*f[j]%Mo+Mo)%Mo;
	  }
}
int main()
{
	 scanf("%d%d%d",&n,&m,&k);
	 if (m==1) printf("%d\n",power(k,n*m));
	 else 
	 {
	 	  pre();
	 	  for (i=0;i<=k&&i<=n;++i)
	 	  {
	 	  	 int y=power(i,n*(m-2));
	 	     for (j=0;j<=k&&i+j<=n;++j)
	 	    {
	 	    	 int x=1ll*f[i+j]*f[i+j]%Mo*cal(k,i)%Mo*cal(k-i,j)%Mo*cal(k-i-j,j)%Mo;
	 	    	 ans=(ans+1ll*x*y%Mo)%Mo;
	 	    }
	 	   }
	 	 printf("%d\n",ans);
	 }
}