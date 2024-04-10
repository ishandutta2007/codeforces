#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

int qpw(int a, int b) {
	a %= M;
	if (b < 0) {
		(b %= M - 1) += M - 1;
	}
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % M) {
		if (b & 1) {
			c = 1ll * c * a % M;
		}
	}
	return c;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<LL> s(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> fct(n + 1), ifc(n + 1);
	fct[0] = 1;
	for (int i = 1; i <= n; i++) {
		fct[i] = 1ll * fct[i - 1] * i % M;
	}
	ifc[n] = qpw(fct[n], -1);
	for (int i = n - 1; i >= 0; i--) {
		ifc[i] = ifc[i + 1] * (i + 1ll) % M;
	}
	auto C = [&](int n, int m) -> int {
		if (n < 0 || m < 0 || n - m < 0) {
			return 0;
		}
		return 1ll * fct[n] * ifc[m] % M * ifc[n - m] % M;
	};
	map<LL, pair<int, int>> cnt;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		++cnt[s[i]].first;
	}
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[n - i + 1];
		++cnt[s[i]].second;
	}
	LL tot = s[n];
	int presum = 1;
	for (auto [v, p] : cnt) {
		if (v + v < tot) {
			presum = 1ll * C(p.first + p.second, p.first) * presum % M;
		} else if (v + v == tot) {
			int len = p.first;
			if (v == 0) {
				--len;
			}
			presum = 1ll * presum * qpw(2, len) % M;
		}
	}
	printf("%d\n", (presum % M + M) % M);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}