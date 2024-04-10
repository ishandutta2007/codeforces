#include<bits/stdc++.h> 
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
constexpr LL mod = 1000000007;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL f[maxn], uf[maxn];
LL c(int m, int n){
	if(m < n) return 0;
	return f[m] * uf[n] % mod * uf[m - n] % mod;
}
int mu[maxn];
vector<int> d[maxn];
int main(){
	for(int i = 0; i < maxn; i += 1)
		uf[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
	mu[1] = 1;
	for(int i = 1; i < maxn; i += 1){
		for(int j = 1; i * j < maxn; j += 1)
			d[i * j].push_back(i);
		if(i > 1) {
			if(i / d[i][1] % d[i][1]) mu[i] = mod - mu[i / d[i][1]];
			else mu[i] = 0;
		}
	}
	int q;
	cin >> q;
	while(q --){
		int f, n;
		cin >> n >> f;
		LL ans = 0;
		for(int x : d[n]) ans = (ans + mu[x] * c(n / x - 1, f - 1)) % mod;
		cout << ans << endl;
	}
}