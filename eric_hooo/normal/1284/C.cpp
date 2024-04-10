#include <bits/stdc++.h>
using namespace std;

long long pw[300010];

int main () {
	int n, mod; cin >> n >> mod;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = pw[i - 1] * i % mod;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + pw[i] * pw[n - i] % mod * (n - i + 1) % mod * (n - i + 1) % mod) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}