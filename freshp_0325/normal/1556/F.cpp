#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
LL inv[2000005],a[15],n,dp[(1<<15)],cnt1,cnt2,p[15],q[15];
int main(){
	inv[1]=1;
	for(LL i=2;i<=2000000;++i)	inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
	scanf("%lld",&n);
	for(LL i=0;i<n;++i)	scanf("%lld",&a[i]);
	for(LL S=1;S<(1<<n);++S)
	{
		dp[S]=1;
		for(LL T=S&(S-1);T;T=S&(T-1))
		{
			LL Ts=T^S;
			cnt1=cnt2=0;
			for(LL i=0;i<n;++i)
			{
				if((T>>i)&1)	p[++cnt1]=i;
				if((Ts>>i)&1)	q[++cnt2]=i;
			}
			LL st=1;
			for(LL i=1;i<=cnt1;++i)	for(LL j=1;j<=cnt2;++j)	st=st*a[p[i]]%MOD*inv[a[p[i]]+a[q[j]]]%MOD;
			st=MOD-st;
			st=st*dp[T]%MOD;
			dp[S]=(dp[S]+st)%MOD;
		}
	}
	LL ans=0;
	for(LL S=1;S<(1<<n);++S)
	{
		cnt1=cnt2=0;
		for(LL i=0;i<n;++i)
		{
			if((S>>i)&1)	p[++cnt1]=i;
			else	q[++cnt2]=i;
		}
		LL st=1;
		for(LL i=1;i<=cnt1;++i)	for(LL j=1;j<=cnt2;++j)	st=st*a[p[i]]%MOD*inv[a[p[i]]+a[q[j]]]%MOD;
		ans=(ans+st*dp[S]%MOD*cnt1%MOD)%MOD;
	}
	printf("%lld",ans);
	return 0;
}