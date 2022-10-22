#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[110000],qz[110000];bool bk[110000];
ll mymax(ll x,ll y) {return x>y?x:y;}
ll mymin(ll x,ll y) {return x<y?x:y;}
int main()
{
	ll dd,b,n;scanf("%lld%lld%lld",&n,&dd,&b);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	qz[0]=0;for(ll i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	ll sum1,sum2;sum1=sum2=0;
	for(ll i=1;i<=n/2;i++)
	{
		ll j=n-i+1;
		if(qz[mymin(n,i+i*dd)]>=sum1*b+b) sum1++;
		if(qz[n]-qz[mymax(1,j-i*dd)-1]>=sum2*b+b) sum2++;
	}
	printf("%lld\n",n/2-mymin(sum1,sum2));
	return 0;
}