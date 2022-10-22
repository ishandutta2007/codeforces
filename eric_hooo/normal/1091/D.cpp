#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long fac[1000010], power[1000010], inv[1000010];

int main(){
	int n;
	scanf("%d", &n);
	inv[0] = 1, inv[1] = 1;
	for (int i = 2; i <= n; i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= n; i++){
		inv[i] = inv[i] * inv[i - 1] % mod;
	}
	fac[0] = 1;
	long long res = 0;
	for (int i = 1; i <= n; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	power[0] = 1;
	for (int i = 1; i <= n; i++){
		power[i] = power[i - 1] * n % mod;
	}
	res = fac[n];
	for (int i = 1; i <= n; i++){
//		cout << i << " " << fac[n] * inv[n - i] % mod * fac[n - i] % mod << endl;
		res = (res + fac[n] * inv[n - i] % mod * ((fac[n - i] - 1 + mod) % mod) % mod) % mod;
	}
	printf("%I64d\n", res);
	return 0;
}