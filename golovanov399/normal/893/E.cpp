#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
int erat[N];

const int mod = 1000000007;
int fact[N];
int invfact[N];

long long pw(long long a, long long b) {
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

long long C(int n, int k) {
	return fact[n] * 1ll * invfact[n - k] % mod * invfact[k] % mod;
}

int main() {
	for (int i = 2; i < N; ++i) {
		if (erat[i]) {
			continue;
		}
		erat[i] = i;
		if (1.0 * i * i < N + N) {
			for (int j = i * i; j < N; j += i) {
				if (erat[j] == 0) {
					erat[j] = i;
				}
			}
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = 1ll * i * fact[i - 1] % mod;
	}
	invfact[N - 1] = pw(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) {
		invfact[i] = 1ll * invfact[i + 1] * (i + 1) % mod;
	}

	int q = nxt();
	while (q--) {
		int x = nxt(), y = nxt();
		long long ans = 1;
		int last = 0;
		int cnt = 0;
		while (x > 1) {
			int p = erat[x];
			if (p == last) {
				++cnt;
			} else {
				ans = ans * C(cnt + y - 1, cnt) % mod;
				cnt = 1;
			}
			last = p;
			x /= p;
		}
		ans = ans * C(cnt + y - 1, cnt) % mod;
		ans = ans * pw(2, y - 1) % mod;
		printf("%lld\n", ans);
	}

	return 0;
}