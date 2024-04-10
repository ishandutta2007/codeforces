#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

const long long mod=1e9+7;
long long p4[100010], p7[100010], pp2[100010], dp[100010], sum[100010], pp4[100010], pp7[100010];
char l[100010], r[100010];

long long solve(char *n) {
	int len=strlen(n);
	long long s=0, ans=0, last=pp7[len-1];
	for (int i=0; i<len; i++) ans=(ans+dp[i])%mod;
	for (int i=0; i<len; i++) {
		if (n[i]=='4') {
			s=(s+p4[len-i])%mod;
		} else {
			ans=(ans+(pp4[len-i]+s)*last)%mod;
			last=(pp7[len-i-1]+s+p4[len-i])%mod;
			long long s2=(s+p4[len-i])%mod;
			long long tt=(2*sum[len-i-1]-pp4[len-i-1]-pp7[len-i-1])%mod;
			while (tt<0) tt+=mod;
			ans=(ans+dp[len-i-1]+s2*tt+(((s2*s2)%mod)*(pp2[len-i-1]-1))%mod)%mod;
			s=(s+p7[len-i])%mod;
		}
	}
	ans=(ans+s*last)%mod;
	return ans;
}

int main() {
	cin >> l >> r;
	p4[1]=4, p7[1]=7;
	pp2[0]=1, pp2[1]=2;
	for (int i=2; i<100010; i++) p4[i]=(p4[i-1]*10)%mod, p7[i]=(p7[i-1]*10)%mod, pp2[i]=(pp2[i-1]*2)%mod;
	dp[0]=0, dp[1]=4*7;
	sum[0]=0, sum[1]=4+7;
	for (int i=2, sum7=7, sum4=4; i<100010; sum7=(sum7+p7[i])%mod, sum4=(sum4+p4[i])%mod, i++) {
		sum[i]=(2*sum[i-1]+p4[i]*pp2[i-1]+p7[i]*pp2[i-1])%mod;
		long long tt=(2*sum[i-1]-sum7-sum4)%mod;
		while (tt<0) tt+=mod;
		dp[i]=(2*dp[i-1]+((p4[i]+p7[i])*tt)%mod
				+(((p4[i]*p4[i])%mod)*(pp2[i-1]-1))%mod
				+(((p7[i]*p7[i])%mod)*(pp2[i-1]-1))%mod
				+((sum7+p4[i])*(sum4+p7[i]))%mod)%mod;
		pp4[i-1]=sum4;
		pp7[i-1]=sum7;
	}
	long long ans=(solve(r)-solve(l))%mod;
	while (ans<0) ans+=mod;
	cout << ans;
	return 0;
}