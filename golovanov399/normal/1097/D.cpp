#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;
const int N = 100;
using Matrix = array<array<int, N>, N>;
long long inv[N + 1];

Matrix mult(Matrix a, Matrix b) {
	Matrix c;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			long long tmp = 0;
			for (int k = 0; k < N; ++k) {
				tmp += a[i][k] * 1ll * b[k][j] % mod;
			}
			c[i][j] = tmp % mod;
		}
	}
	return c;
}

Matrix pw(Matrix a, int k) {
	Matrix res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			res[i][j] = (i == j);
		}
	}
	while (k) {
		if (k & 1) {
			res = mult(res, a);
		}
		k >>= 1;
		a = mult(a, a);
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long n;
	int k;
	cin >> n >> k;

	vector<long long> p;
	vector<int> d;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i != 0) {
			continue;
		}
		p.push_back(i);
		d.push_back(0);
		while (n % i == 0) {
			d.back() += 1;
			n /= i;
		}
	}
	if (n > 0) {
		p.push_back(n);
		d.push_back(1);
	}

	inv[1] = 1;
	for (int i = 2; i <= N; ++i) {
		inv[i] = mod - 1ll * inv[mod % i] * (mod / i) % mod;
	}

	Matrix m;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j <= i) {
				m[i][j] = inv[i + 1];
			} else {
				m[i][j] = 0;
			}
		}
	}

	m = pw(m, k);
	long long ans = 1;
	for (int i = 0; i < (int)p.size(); ++i) {
		long long tmp = 0, cur = 1;
		for (int j = 0; j <= d[i]; ++j) {
			tmp += m[d[i]][j] * cur % mod;
			cur = cur * (p[i] % mod) % mod;
		}
		ans = ans * (tmp % mod) % mod;
	}
	cout << ans << "\n";

	return 0;
}