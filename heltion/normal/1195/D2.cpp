//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
void no(){cout << "NO"; exit(0);}
constexpr LL mod = 998244353;
LL a[maxn], c[maxn], p[maxn];
LL len(LL n){
	LL res = 0;
	for(; n; n /= 10) res += 1;
	return res;
}
LL cal(LL x, int n){
	LL res = 0;
	for(int i = 1; x; x /= 10, i += 1){
		LL d = x % 10;
		if(i <= n) res += d * p[2 * i - 2] % mod;
		else res += d * p[2 * n + i - n - 1] % mod;
		if(i <= n) res += d * p[2 * i - 1] % mod;
		else res += d * p[2 * n + i - n - 1] % mod;
	}
	res %= mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		c[len(a[i])] += 1;
	}
	for(int i = 0; i < maxn; i += 1) p[i] = i ? p[i - 1] * 10 % mod : 1;
	LL ans = 0;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= 10; j += 1){
			//cout << a[i] << " " << j << " " << cal(a[i], j) << "\n";
			ans += cal(a[i], j) * c[j] % mod;
			ans %= mod;
		}
	cout << ans;
	return 0;
}