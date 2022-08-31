#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

constexpr int mod = 1'000'000'007;
const int L = 40;
const int N = 333'333;

int p2[N];
int cnt[L];

void solve() {
	p2[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = p2[i - 1] * 2 % mod;
	}

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		cnt[__builtin_ctz(x)] += 1;
	}
	long long ans = p2[n] - 1;
	int total = n;
	for (int i = 1; i < L; ++i) {
		total -= cnt[i - 1];
		if (!cnt[i]) {
			continue;
		}
		ans -= p2[total] * 1ll * (mod + 1) / 2 % mod;
	}
	ans %= mod;
	if (ans < 0) {
		ans += mod;
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}