//Author: Heltion
//Date: 2019-06-03
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 1200000;
constexpr LL mod = 1e9 + 7;
LL f[maxn], uf[maxn];
LL a[100], c[100];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL C(LL m, LL n){
	if(n > m or n < 0) return 0;
	return f[m] * uf[n] % mod * uf[m - n] % mod;
}
LL solve(int m){
	LL p = 0, res = 1;
	for(int i = m; i >= 1; i -= 1){
		LL pres = (C(c[i] + p, p) - C(c[i] + p - 1, p - 1) + mod) % mod * f[c[i]] % mod;
		p += c[i];
		res = res * pres % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i <= n + 1; i += 1) uf[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
	LL k = 1, m = 1;
	while(k * 2 <= n){
		k *= 2;
		m += 1;
	}
	for(int i = 1; i <= m; i += 1) a[i] = i == 1 ? k : a[i - 1] / 2;
	for(int i = 1, p = 0; i <= m; i += 1){
		c[i] = n / a[i] - p;
		p += c[i];
	}
	LL ans = solve(m);
	if(m >= 2 and m / 2 * 3 <= n){
		for(int i = 1; i < m; i += 1){
			a[i] = a[i] / 2 * 3;
			for(int j = i - 1; j; j -= 1) a[j] = a[j + 1] * 2;
			for(int j = 1, p = 0; j <= m; j += 1){
				c[j] = n / a[j] - p;
				p += c[j];
			}
			ans = (ans + solve(m)) % mod;
		}
	}
	cout << ans;
	return 0;
}