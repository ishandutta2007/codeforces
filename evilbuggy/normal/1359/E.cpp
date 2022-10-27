#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 998244353;
const int N = 500005;

ll fac[N], ifac[N], inv[N];

void pre(){
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2; i < N; i++){
		fac[i] = i*fac[i - 1]%mod;
		inv[i] = (mod - mod/i)*inv[mod%i]%mod;
		ifac[i] = ifac[i - 1]*inv[i]%mod;
	}
}

inline ll ncr(int n, int r){
	if(r < 0 || r > n || n < 0)return 0;
	return fac[n]*(ifac[r]*ifac[n - r]%mod)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int n, k;
	cin>>n>>k;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += ncr(n/i - 1, k - 1);
		// cout<<i<<" "<<ncr(n/i - 1, k - 1)<<endl;
		if(ans >= mod)ans -= mod;
	}
	cout<<ans<<endl;

	return 0;
}