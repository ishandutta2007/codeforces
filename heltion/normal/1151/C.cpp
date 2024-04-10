#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
constexpr LL mod = 1e9 + 7;
LL g(LL n){
	LL s[2] = {1, 2}, res = 0;
	for(LL k = 1, u = 0; n; k <<= 1, u ^= 1){
		LL h = min(k, n);
		res += (s[u] + s[u] + h * 2 - 2) % mod * (h % mod) % mod * (mod + 1) / 2 % mod;
		s[u] += h * 2;
		n -= h;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	LL r, l;
	cin >> l >> r;
	cout << (g(r) - g(l - 1) + mod) % mod;
}