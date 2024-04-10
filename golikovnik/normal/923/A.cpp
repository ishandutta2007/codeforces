#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

const int N = 1e6 + 20;
int pr[N];
bool is_prime[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int x2; cin >> x2;
	memset(is_prime, 1, sizeof(is_prime));
	for (int i = 2; i < N; ++i) {
		if (is_prime[i]) {
			if (1LL * i * i >= N) continue;
			for (int j = i * i; j < N; j += i) {
				is_prime[j] = 0;
				pr[j] = i;
			}
		}
	}
	auto get = [&](int n) {
		int res = 0;
		while (!is_prime[n]) {
			res = max(res, pr[n]);
			n /= pr[n];
		}
		return max(res, n);
	};
	int ans = N;
	for (int x1 = x2 - get(x2) + 1; x1 <= x2; ++x1) {
		if (!is_prime[x1])
			ans = min(ans, x1 - get(x1) + 1);
	}
	cout << ans << "\n";
	return 0;
}