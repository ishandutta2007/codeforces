#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;

int N,n,C[105][105],P[105][2],f[105][105][105];

int main() {
	scanf("%d",&N);
	if (N == 0) { puts("1"); return 0; }
	std::function<int (int)> length = [&] (int x) { return x == 1 ? 1 : length(x / 2) + 1; };
	auto get = [](int S,int i) { return (S >> (i - 1)) & 1; };
	n = length(N);
	for (int i = 0; i <= n; ++ i) {
		C[i][0] = 1; 
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		for (int j = 0; j <= i; ++ j) P[i][j%2] = (P[i][j%2] + C[i][j]) % mod;
	}
	f[n][0][1] = 1;
	for (int i = n; i >= 1; i --) 
	for (int j = 0; j <= n - i; ++ j) 
	for (int s = 0; s < 2; ++ s) {
		// 
		if (s == 0 || (get(N,i) == 1)) 
			f[i-1][j+1][s] = (f[i-1][j+1][s] + f[i][j][s]) % mod;
		//  1
		if (s == 0 || (get(N,i) == 1)) 
			f[i-1][j][s] = (f[i-1][j][s] + (ll) f[i][j][s] * P[j][1] % mod) % mod;
		//  0
		int t = get(N,i) == 1 ? 0 : s;
		f[i-1][j][t] = (f[i-1][j][t] + (ll) f[i][j][s] * P[j][0] % mod) % mod;
	} 
	int ans = 0;
	for (int j = 0; j <= n; ++ j) 
	for (int s = 0; s < 2; ++ s)
		ans = (ans + f[0][j][s]) % mod;
	printf("%d",ans);
	return 0;
}