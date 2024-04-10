#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

ll modPow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, m;
	cin>>n>>m;
	ll ans = modPow(2, m) - 1;
	ans = modPow(ans, n);
	cout<<ans<<endl;

	return 0;
}