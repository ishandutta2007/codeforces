#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
int cnt[N];

const int mod = 998244353;
long long inv[N];

int main() {
	int n = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(nxt());
		generate(all(a[i]), nxt);
		for (auto x : a[i]) {
			++cnt[x];
		}
	}

	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int x : a[i]) {
			ans += inv[n] * inv[a[i].size()] % mod * inv[n] % mod * cnt[x] % mod;
		}
	}
	cout << ans % mod << "\n";

	return 0;
}