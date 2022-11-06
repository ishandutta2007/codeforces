#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 100010
#define mod 1000000007
using namespace std;
int cnt[N];
ll ksm(ll a,ll b=mod-2)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	int u;
        scanf("%d",&u);
        if(u>0) ++cnt[u];
    }
	int ans=0;
	for(int i=1;i<=n;i++)
	if(cnt[i]) ans=(ans+ksm(2,cnt[i])-1)%mod;
	printf("%lld\n",(ksm(2,n-1)-1-ans+mod)%mod);
	return 0;
}