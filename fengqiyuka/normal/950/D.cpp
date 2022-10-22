#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
	ll n;scanf("%lld",&n);
	ll mid=(n+1)/2;
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		ll x;scanf("%lld",&x);
		if(x%2==1) printf("%lld\n",(x+1)/2);
		else
		{
			x=n-x/2;
			while(x%2==0&&x!=0) x/=2;
			printf("%lld\n",n-x/2);
		}
	}
	return 0;
}