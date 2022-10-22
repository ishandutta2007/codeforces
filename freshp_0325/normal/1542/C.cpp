#include<bits/stdc++.h>
typedef long long LL;
const LL MOD=1e9+7;
LL gcd(LL a,LL b){return !b?a:gcd(b,a%b);}
LL pre[105],pos;
int main(){
	pre[1]=1;
	for(LL i=2;;++i)
	{
		pre[i]=i/gcd(pre[i-1],i)*pre[i-1];
//		printf("%lld\n",pre[i]);
		if(pre[i]>1e16)
		{
			pos=i;
			break;
		}
	}
	LL T;
	scanf("%lld",&T);
	while(T-->0)
	{
		LL n;
		scanf("%lld",&n);
		LL ans=n%MOD;
		for(LL i=1;i<=pos;++i)	(ans+=n/pre[i]%MOD)%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}