#include <bits/stdc++.h>
using namespace std;


const int mod  = 1000000007;
const int inv3 =  333333336;
const int inv2 =  500000004;
int n;

void solve() {
	int sign = -1;

	scanf("%d", &n);
	long long pot = 2;

	for (int i = 0; i < n; i++) {
		long long k;
		scanf("%lld", &k);

		if (k % 2 == 0) sign = 1;
		
		long long ans = 1;
		while (k) {
			if (k&1) ans = (ans*pot) % mod;
			pot = (pot*pot) % mod;
			k >>= 1;
		}

		pot = ans;
	}

	pot = (pot * inv2) % mod;
	long long den = pot;
	pot = (pot + sign + mod) % mod;
	pot = (pot * inv3) % mod;

	printf("%lld/%lld\n", pot, den);
}

int main() {
    solve();
}