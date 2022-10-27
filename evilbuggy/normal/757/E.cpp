#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1111111;
const int mod = 1000000007;

ll fac[N], ifac[N], inv[N];
int lpf[N];

inline ll modPow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

void pre(){
	fac[0] = ifac[0] = 1;
	fac[1] = inv[1] = ifac[1] = 1;
	for(int i = 2; i < N; i++){
		fac[i] = fac[i-1]*i%mod;
		inv[i] = (mod - ((mod/i)*inv[mod%i]%mod))%mod;
		ifac[i] = ifac[i-1]*inv[i]%mod;
	}
	memset(lpf, -1, sizeof(lpf));
	for(int n = 2; n < N; n++){
		if(lpf[n] == -1){
			for(int m = n; m < N; m += n){
				if(lpf[m] == -1)lpf[m] = n;
			}
		}
	}
}

inline ll ncr(int n, int r){
	return (fac[n]*ifac[n-r]%mod)*ifac[r]%mod;
}

inline ll func(int a, int r){
	if(r == 0)return 2;
	ll ret = ncr(a + r - 1, r) + ncr(a + r, r);
	if(ret >= mod)ret -= mod;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int q, n, r;
	cin>>q;
	while(q--){
		cin>>r>>n;
		ll ans = 1;
		while(n > 1){
			int cnt = 0;
			int x = lpf[n];
			while(n%x == 0){
				n /= x;
				cnt++;
			}
			(ans *= func(cnt, r)) %= mod;
		}
		cout<<ans<<'\n';
	}

	return 0;
}