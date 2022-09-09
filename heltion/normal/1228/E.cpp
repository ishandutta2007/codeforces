//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 300;
constexpr LL mod = 1000000007;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL c[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, k;
	cin >> n >> k;
	for(int i = 0; i < maxn; i += 1)
		for(int j = 0; j <= i; j += 1)
			c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % mod : 1LL;
	LL ans = 0;
	for(int i = 0; i <= n; i += 1)
		for(int j = 0; j <= n; j += 1){
			LL ch = i * n + j * n - i * j;
			LL ex = n * n - ch;
			LL pans = power(k - 1, ch) * power(k, ex) % mod;
			pans = pans * c[n][i] % mod * c[n][j] % mod;
			if((i + j) & 1) ans += mod - pans;
			else ans += pans;
			ans %= mod;
		}
	cout << ans;
	return 0;
}