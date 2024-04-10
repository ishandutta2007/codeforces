#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long a[30], inv[30];

long long power(long long a, long long b){
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long C(long long a, long long b){
	long long ans = 1;
	for (int i = 1; i <= b; i++){
		ans = ans * ((a - i + 1) % mod) % mod;
	}
	return ans * inv[b] % mod;
}

int main(){
	int n; long long s;
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	inv[0] = 1;
	for (int i = 1; i <= n; i++){
		inv[i] = inv[i - 1] * power(i, mod - 2) % mod;
	}
	long long ans = 0;
	for (int mask = 0; mask < (1 << n); mask++){
		long long sum = 0, cnt = 0;
		for (int i = 0; i < n; i++){
			if (mask >> i & 1) sum += a[i] + 1, cnt++;
		}
		if (sum > s) continue;
		ans = (ans + (cnt & 1 ? -1 : 1) * C(n + s - sum - 1, n - 1) + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}