#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353

char str[3];
int n, cnt, ind, WW, BB, WB, BW, W_, _W, B_, _B, __cnt;
long long ans, inv[200001];

long long power(long long x, int y) {
	long long ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		y /= 2;
	}
	return ans;
}

long long C(int n, int m) {
	if (m < 0 || m > n) return 0;
	long long ret = 1;
	for (int i = 1; i <= m; ++i) {
		inv[i] = i == 1 ? 1 : (MOD - MOD / i) * inv[MOD % i] % MOD;
		ret = ret * (n - i + 1) % MOD * inv[i] % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		if (str[0] == 'W' && str[1] == 'W') --ind, ++WW; else
		if (str[0] == 'W' && str[1] == '?') ++cnt, ++W_; else
		if (str[0] == '?' && str[1] == 'W') ++cnt, ++_W; else
		if (str[0] == 'B' && str[1] == 'B') ++ind, ++BB; else
		if (str[0] == 'B' && str[1] == '?') ++ind, ++cnt, ++B_; else
		if (str[0] == '?' && str[1] == 'B') ++ind, ++cnt, ++_B; else
		if (str[0] == '?' && str[1] == '?') ++ind, cnt += 2, ++__cnt; else
		if (str[0] == 'B' && str[1] == 'W') ++BW; else
		if (str[0] == 'W' && str[1] == 'B') ++WB;
	}
	ans = C(cnt, ind);
	if (WW == 0 && BB == 0) {
		ans -= power(2, __cnt) - (WB == 0 && W_ == 0 && _B == 0) - (BW == 0 && B_ == 0 && _W == 0);
	}
	printf("%lld\n", ((ans % MOD) + MOD) % MOD);
	return 0;
}