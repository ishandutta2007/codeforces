#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 987'898'789;

const int N = 303'303;
int erat[N];
int mu[N];
vector<int> primes;

int cnt[N];

int inv[N];
int C[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	erat[1] = mu[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= N) {
				break;
			}
			erat[i * p] = p;
		}
		mu[i] = erat[i] == erat[i / erat[i]] ? 0 : -mu[i / erat[i]];
	}

	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = mod - inv[mod % i] * 1ll * (mod / i) % mod;
	}

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		cnt[nxt()] += 1;
	}
	{
		int g = 0;
		for (int i = 0; i < N; ++i) {
			if (cnt[i]) {
				g = gcd(g, i);
			}
		}
		if (g > 1) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = i + i; j < N; j += i) {
			cnt[i] += cnt[j];
		}
	}

	int l = 0, r = n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		for (int i = 0; i < m; ++i) {
			C[i] = 0;
		}
		long long cur = 1;
		for (int i = m; i <= n; ++i) {
			C[i] = cur;
			cur = cur * (i + 1) % mod * inv[i - m + 1] % mod;
		}

		long long cn = 0;
		for (int i = 1; i < N; ++i) {
			cn += mu[i] * C[cnt[i]];
		}
		cn %= mod;
		(cn ? r : l) = m;
	}

	cout << r << "\n";

	return 0;
}