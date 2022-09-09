//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
void no(){cout << "NO"; exit(0);}
constexpr int mod = 998244353;
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	LL ans = 0;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1)
		for(LL p = 1; a[i]; a[i] /= 10, p = p * 100 % mod){
			ans += a[i] % 10 * 11 * p % mod;
			ans %= mod;
		}
	cout << ans * n % mod;
	return 0;
}