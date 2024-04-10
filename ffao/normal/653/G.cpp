#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

void prime_sieve(int *p, int up_to);
void precompute_inv(long long *r, int up_to, int mod);

 
int a[310000];
int p[310000];
long long C[310000];
long long sumC[310000];
long long inv[310000];
const int mod = 1000000007;
long long coef_left[310000];
long long coef_right[310000];

vector<int> ps[310000];
int n;

void solve() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &a[i]);
	prime_sieve(p, 301000);
	precompute_inv(inv, 301000, mod);

	C[0] = 1;
	for (int k = 1; k <= n-1; k++) {
		C[k] = (C[k-1] * 1ll * (n-k)) % mod;
		C[k] = (C[k] * 1ll * inv[k]) % mod;
	}

	sumC[0] = 1;
	for (int k = 1; k <= n-1; k++) {
		sumC[k] = (sumC[k-1] + C[k]) % mod;
	}

	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n-i-1;
		coef_left[i] = sumC[r];
		coef_right[i] = sumC[l];
		//printf("%d -> %lld %lld\n", i,coef_left[i], coef_right[i]);
	}

	for (int i = 0; i < n; i++) {
		while (a[i] != 1) {
			int pf = p[a[i]];
			int ct = 0;
			if (pf == 0) pf = a[i];
			while (a[i] % pf == 0) {
				a[i] /= pf;
				ct++;
			}
			ps[pf].push_back(ct);
		}
	}

	long long ans = 0;
	for (int i = 2; i <= 300000; i++) {
		if (!ps[i].empty()) {
			sort(ps[i].begin(), ps[i].end());
			int aa = 0;
			for (int j = ps[i].size()-1; j >= 0; j--) {
				ans = (ans + coef_left[aa] * 1ll * ps[i][j]) % mod;
				ans = (ans - coef_right[aa] * 1ll * ps[i][j]) % mod;
				if (ans < 0) ans += mod;
				aa++;
			}
		}
	}

	printf("%lld\n", ans);
}

int main() {
    solve();
}

void prime_sieve(int *p, int up_to) {
	for (int i = 2; i*i <= up_to; i++) {
		if (!p[i]) {
			for (int j = i*i; j <= up_to; j+=i) p[j] = i;
		}
	}
}


void precompute_inv(long long *r, int up_to, int mod) {
	int m = mod;
	r[1] = 1; 
	for (int i=2; i<=up_to; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;
}