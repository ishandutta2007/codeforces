#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	if(k >= n)return cout << 0, 0;
	const int mod = 998244353;
	vector<long long> fac(n + 1, 1);
	for(int i = 1; i <= n; ++i){
		fac[i] = (fac[i - 1] * i)%mod;
	}
	auto fp = [&](long long b, long long pw){
		long long r = 1;
		for(; pw; pw>>=1, b = (b * b)%mod){
			if(pw&1)r = (r * b)%mod;
		}
		return r;
	};
	auto C = [&](int b, int t){
		if(t > b)return 0ll;
		return fac[b]*fp(fac[b - t], mod - 2)%mod*fp(fac[t], mod - 2)%mod;
	};
	int ct = n - k;
	long long ans = 0;
	for(int i = 0; i <=	 ct; ++i){
		ans = (ans + (i&1 ? -1 : 1)*C(ct, i)%mod*fp(ct - i, n)%mod)%mod;
	}
	cout << (ans*C(n, ct)%mod*(2 - !k) + (long long)mod*mod)%mod;
}