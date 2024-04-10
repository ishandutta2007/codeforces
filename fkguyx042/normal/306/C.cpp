#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 10005

using namespace std;
int i,j,m,n,p,k,fac[N],w,b;
const int Mo=(int)1e9+9;
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
int C(int x,int y)
{
	  return 1ll*fac[x]*power(fac[y],Mo-2)%Mo*power(fac[x-y],Mo-2)%Mo;
}
int main()
{ 
  fac[0]=1;
  for (i=1;i<N;++i) fac[i]=1ll*fac[i-1]*i%Mo;
  scanf("%d%d%d",&n,&w,&b);
  int ans=1ll*fac[w]*fac[b]%Mo*(w-1)%Mo*C(w+b-3,n-3)%Mo;
  printf("%d\n",ans);
}