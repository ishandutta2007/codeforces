#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int mod = 1000000007;

int fac[N], ifac[N], inv[N];

inline void init(){
	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	for(int n = 2; n < N; n++){
		fac[n] = n*1LL*fac[n - 1]%mod;
		inv[n] = (mod - mod/n)*1LL*inv[mod%n]%mod;
		ifac[n] = ifac[n - 1]*1LL*inv[n]%mod;
	}
}

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}

inline int ncr(int n, int r){
	if(r < 0 || r > n)return 0;
	return fac[n]*(ifac[r]*1LL*ifac[n - r]%mod)%mod;
}

inline int compute(int n, int k, vector<int> &a){
	vector<int> cnt(k + 1);
	cnt[0] = n/a[0];
	for(int i = 1; i <= k; i++){
		cnt[i] = (n/a[i]) - (n/a[i - 1]);
	}
	int ret = 1;
	for(int i = 0; i <= k; i++){
		ret = ret*(ncr(n - 1, cnt[i] - 1)*1LL*fac[cnt[i]]%mod)%mod;
		n -= cnt[i];
	}
	return ret;
}

inline int uwu(int n){
	int k = 0;
	while((1 << (k + 1)) <= n)k++;

	vector<int> a(k + 1);
	for(int i = 0; i <= k; i++){
		a[i] = 1 << (k - i);
	}
	int ret = compute(n, k, a);
	if(3*(1 << (k - 1)) > n)return ret;

	for(int i = 0; i < k; i++){
		int cur = 3*(1 << (k - 1));
		for(int j = 0; j <= k; j++){
			a[j] = cur;
			if(j == i)cur /= 3;
			else cur >>= 1;
		}
		ret += compute(n, k, a);
		if(ret >= mod)ret -= mod;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	
	int n;
	cin >> n;
	cout << uwu(n) << '\n';

	return 0;
}