#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1000005;
const ll mod = 1000000007;

ll fac[maxn], ifac[maxn];
ll dp[maxn], sdp[maxn];

void pre(){
	fac[0] = ifac[0] = 1;
	for(int i = 1; i < maxn; i++){
		fac[i] = (fac[i-1]*i)%mod;
		if(i != 1)ifac[i] = (mod - ifac[mod%i]*(mod/i)%mod)%mod;
		else ifac[i] = 1;
	}
	for(int i = 1; i < maxn; i++){
		(ifac[i] *= ifac[i-1]) %= mod;
	}
}

int main(){
	pre();
	int n, k;
	cin>>n>>k;
	dp[0] = 1;
	sdp[0] = 1;
	for(int i = 1; i <= n; i++){
		ll tmp = sdp[i-1];
		if(i-k-1 >= 0)tmp += mod - sdp[i-k-1];
		tmp %= mod;
		(tmp *= fac[i-1]) %= mod;
		dp[i] = tmp;
		(tmp *= ifac[i]) %= mod;
		sdp[i] = (sdp[i-1] + tmp)%mod;
	}
	ll ans = sdp[n-1]*fac[n-1]%mod;
	ans = (fac[n] + mod - ans)%mod;
	cout<<ans<<endl;
}