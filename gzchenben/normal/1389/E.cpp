#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
long long n,m,w,l;
long long gcd(long long x,long long y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&w);
		l=min(n,m);
		w=w/gcd(m-1,w);
		long long tx=l/w;
		long long f1=l%w;
		long long f2=w-f1;
		printf("%lld\n",f1*tx*(tx+1)/2+f2*tx*(tx-1)/2);
	}
}