#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL f[200005];
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
int main(){
	f[1]=f[2]=1;
	for(LL i=3;i<=200000;++i)	f[i]=(f[i-2]+f[i-1])%MOD;
	int n;
	scanf("%d",&n);
	printf("%lld",f[n]*QuickPow(QuickPow(2,n),MOD-2)%MOD);
	return 0;
}