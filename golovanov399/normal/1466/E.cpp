#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 1'000'000'007;

const int L = 62;
int cnt[L];
long long p[L + L];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		long long x;
		scanf("%lld", &x);
		// x = (long long)(rand()) << 30 | (rand());
		a[i] = x;
		for (int j = 0; j < L; ++j) {
			if (x & (1ll << j)) {
				cnt[j] += 1;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			ans += (1ll * cnt[i] * cnt[i] * n) % mod * p[i + j] % mod;
		}
	}

	vector<long long> to_add(L + L);

	for (int j = 0; j < n; ++j) {
		vector<int> good, bad;
		for (int b = 0; b < L; ++b) {
			if (a[j] & (1ll << b)) {
				good.push_back(b);
			} else {
				bad.push_back(b);
			}
		}
		for (int i : good) {
			for (int k : bad) {
				to_add[i + k] += (1ll * cnt[i] * (n - cnt[k]));
				// ans -= (1ll * cnt[i] * (n - cnt[k])) % mod * p[i + k] % mod;
			}
		}
	}
	for (int i = 0; i < L + L; ++i) {
		ans -= to_add[i] % mod * p[i] % mod;
	}
	ans %= mod;
	if (ans < 0) {
		ans += mod;
	}
	cout << ans % mod << "\n";
}

int main() {
	p[0] = 1;
	for (int i = 1; i < L + L; ++i) {
		p[i] = p[i - 1] * 2 % mod;
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}