#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
constexpr LL mod = 998244353;
int b[maxn];
LL f[2][maxn];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod) if(r & 1)
		res = res * a % mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	f[0][0] = 1;
	for(int i = 1; i <= n; i += 1){
		f[0][i] = (f[0][i - 1]  * (k - 2) + f[1][i - 1]) % mod;
		f[1][i] = (f[0][i - 1] * (k - 1)) % mod;
	}
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	LL ans = 1;
	int Last = 0, num = 0;
	for(int i = 1; i <= n; i += 2) {
		if(b[i] == - 1) num += 1;
		else{
			if(not Last) ans = ans * power(k - 1, num) % mod;
			else if(Last == b[i]) ans = ans * f[1][num] % mod;
			else ans = ans * f[0][num] % mod;
			num = 0;
			Last = b[i];
		}
	}
	if(Last) ans = ans * power(k - 1, num) % mod;
	else ans = ans * power(k - 1, num - 1) * k % mod;
	Last = 0, num = 0;
	for(int i = 2; i <= n; i += 2) {
		if(b[i] == - 1) num += 1;
		else{
			if(not Last) ans = ans * power(k - 1, num) % mod;
			else if(Last == b[i]) ans = ans * f[1][num] % mod;
			else ans = ans * f[0][num] % mod;
			num = 0;
			Last = b[i];
		}
	}
	if(Last) ans = ans * power(k - 1, num) % mod;
	else ans = ans * power(k - 1, num - 1) * k % mod;
	cout << ans;
}