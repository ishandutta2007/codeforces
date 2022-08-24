#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 5555555;
int erat[N];
int f[N];

const int mod = 1000000007;

int main() {
	for (int n = 2; n < N; ++n) {
		if (erat[n] == 0) {
			erat[n] = n;
			if (1.0 * n * n < N + N) {
				for (int i = n * n; i < N; i += n) {
					if (erat[i] == 0) {
						erat[i] = n;
					}
				}
			}
		}
	}

	for (int i = 2; i < N; ++i) {
		int d = erat[i];
		f[i] = (f[i / d] + 1ll * (i / d) * (1ll * d * (d - 1) / 2 % mod)) % mod;
	}

	long long ans = 0;
	long long cur = 1;
	int t = nxt(), l = nxt(), r = nxt();
	for (itn i = l; i <= r; ++i) {
		ans += f[i] * cur % mod;
		cur = cur * t % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}