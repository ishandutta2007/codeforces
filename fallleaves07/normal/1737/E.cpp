#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 1e9 + 7, inv2 = (M + 1) >> 1;

void solve() {
	int n;
	cin >> n;
	vector<int> f(n + 1), pw(n + 1);
	int sum = 2, inv = 1;
	f[n] = 2, pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = (pw[i - 1] << 1) % M;
		inv = 1ll * inv * inv2 % M;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = ((i + 1) << 1) - 1; j >= (i << 1); j--) {
			if (j <= n) {
				sum = (sum - f[j]) % M;
			}
		}
		f[i] = sum, sum = (sum + f[i]) % M;
	}
	for (int i = 1; i <= n; i++) {
		int ans = 1ll * f[i] * pw[i >> 1] % M * inv % M;
		printf("%d\n", (ans % M + M) % M);
	}
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