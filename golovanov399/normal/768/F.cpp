#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

long long pw(long long a, long long b) {
	a %= mod;
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

const int N = 111111;
int fact[N];
int inv[N];
int invfact[N];

long long C(long long n, long long k) {
	if (k < 0 || k > n) {
		return 0;
	}
	// cerr << "C(" << n << ", " << k << ") = " << 1ll * fact[n] * invfact[k] % mod * invfact[n - k] % mod << "\n";
	return 1ll * fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

int main(){

	fact[0] = invfact[0] = 1;
	inv[1] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		if (i > 1) {
			inv[i] = mod - (1ll * mod / i * inv[mod % i]) % mod;
		}
		invfact[i] = 1ll * invfact[i - 1] * inv[i] % mod;
	}
	for (int i = 1; i < 100; ++i) {
		assert(1ll * i * inv[i] % mod == 1);
	}

	long long f = nxt(), w = nxt(), h = nxt();

	if (f == 0) {
		puts(w > h ? "1" : "0");
		return 0;
	}
	if (w == 0) {
		puts("1");
		return 0;
	}

	long long total = 0;
	long long succ = 0;
	for (int k = 1; k <= w && k <= f; ++k) {
		total += 2ll * C(f - 1, k - 1) % mod * C(w - 1, k - 1) % mod;
		succ += 2ll * C(f - 1, k - 1) % mod * C(w - k * h - 1, k - 1) % mod;
		// cerr << k << " " << k << "\n";
		// cerr << succ << "/" << total << "\n";
	}
	for (int k = 1; k <= w && k + 1 <= f; ++k) {
		total += 1ll * C(f - 1, k) % mod * C(w - 1, k - 1) % mod;
		succ += 1ll * C(f - 1, k) % mod * C(w - k * h - 1, k - 1) % mod;
		// cerr << k + 1 << " " << k << "\n";
		// cerr << succ << "/" << total << "\n";
	}
	for (int k = 1; k + 1 <= w && k <= f; ++k) {
		total += 1ll * C(f - 1, k - 1) % mod * C(w - 1, k) % mod;
		succ += 1ll * C(f - 1, k - 1) % mod * C(w - (k + 1) * h - 1, k) % mod;
		// cerr << k << " " << k + 1 << "\n";
		// cerr << succ << "/" << total << "\n";
	}

	cout << succ % mod * pw(total, mod - 2) % mod << "\n";

	return 0;
}