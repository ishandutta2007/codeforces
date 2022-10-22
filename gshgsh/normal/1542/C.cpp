#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		ll N=get();int x=2,ans=0;
		ll a=1;while(N){ll y=x/__gcd(1ll*x,a);a*=y;ans=(ans+x*((N-N/y)))%P,N/=y,x++;}
		cout<<ans<<endl;
	}
	return 0;
}