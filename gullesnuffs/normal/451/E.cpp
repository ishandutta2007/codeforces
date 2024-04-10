#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long f[25];
int hasInv[25];

long long POW(long long n, long long p){
	long long dp[35];
	dp[0]=n;
	long long ret=1;
	for(int i=0; i < 32; ++i){
		dp[i+1]=(dp[i]*dp[i])%MOD;
		if(p&(1LL<<i))
			ret=(ret*dp[i])%MOD;

	}
	return ret;
}

long long inv(long long n){
	if(hasInv[n])
		return hasInv[n];
	return hasInv[n]=POW(n, MOD-2);
}

long long nCr(long long n, long long k){
	long long ret=1;
	for(int i=1; i <= k; ++i){
		ret=(ret*((n+1-i)%MOD))%MOD;
		ret=(ret*inv(i))%MOD;
	}
	return ret;
}

int main(){
	int n;
	long long s;
	scanf("%d%I64d", &n, &s);
	for(int i=0; i < n; ++i)
		scanf("%I64d", f+i);
	long long ans=0;
	for(int i=0; i < (1<<n); ++i){
		long long left=s;
		for(int j=0; j < n; ++j)
			if(i&(1<<j))
				left -= f[j]+1;
		if(left < 0)
			continue;
		ans=(ans+nCr(left+n-1, n-1)*((__builtin_popcount(i)%2)?-1:1))%MOD;
	}
	ans%=MOD;
	while(ans < 0)
		ans += MOD;
	printf("%I64d\n", ans);
}