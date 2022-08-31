#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

long long pw(long long a, long long b){
    long long res = 1;
    while (b){
        if (b & 1ll)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

long long inv(long long x){
    return pw(x, mod - 2);
}

int main(){

	long long ans = 1;

	int n;
	cin >> n;
	vector<long long> fact(2 * n + 2), ifact(2 * n + 2);
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < 2 * n + 2; i++){
		fact[i] = fact[i - 1] * i % mod;
		ifact[i] = inv(fact[i]);
	}
	for (int i = 1; i <= n; i++){
		long long c2n1n = fact[2 * i + 1] * ifact[i] % mod * ifact[i + 1] % mod, c2nn = fact[2 * i] * ifact[i] % mod * ifact[i] % mod;
		ans += (c2n1n * 2 - c2nn + mod) % mod;
	}

	cout << ans % mod << "\n";

	return 0;
}