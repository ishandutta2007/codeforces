#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
int pr[N];
int phi[N];

long long pw(long long a, long long b, long long mod) {
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

long long inv(long long a, long long b) {
	return pw(a, phi[b] - 1, b);
}

int g;
long long K, L;

// pair<long long, long long> euc(int x, int y) {
// 	if (y == 0) {
// 		return {1, 0};
// 	}
// 	auto p = euc(y, x % y);
// 	return {p.second, -p.second * (x / y) + p.first};
// }

int xui[N + N];

long long get_cool(int n, int m, int x, int y) {
	if (x % g != y % g) {
		return -1;
	}

	long long res = ((y - x) / g) % (m/g);
	if (res < 0) {
		res += (m/g);
	}
	long long k = xui[res];
	long long d = k * n + x;

	// cerr << n << " " << m << " " << x << " " << y << " " << d << "\n";

	return d;
}

int main(){

	pr[1] = 1;
	for (int i = 2; i < N; i++) {
		if (pr[i] == 0) {
			pr[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (pr[j] == 0) {
						pr[j] = i;
					}
				}
			}
		}
	}

	phi[1] = 1;
	for (int i = 2; i < N; i++) {
		if (pr[i / pr[i]] == pr[i]) {
			phi[i] = phi[i / pr[i]] * pr[i];
		} else {
			phi[i] = phi[i / pr[i]] * (pr[i] - 1);
		}
	}

	int n = nxt(), m = nxt();
	g = 2 * __gcd(n, m);
	int k = nxt();

	for (int i = 0; i < N; i++) {
		xui[i] = -1;
	}
	int ng = 2 * n / g;
	int mg = 2 * m / g;
	for (int i = 0; i < mg; i++) {
		long long d = 1ll * ng * i;
		if (xui[d % mg] == -1) {
			xui[d % mg] = i;
		}
	}

	cout.sync_with_stdio(0);

	while (k--) {
		int x = nxt(), y = nxt();
		long long t = -1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long long tmp = get_cool(2 * n, 2 * m, x + 2 * i * (n - x), y + 2 * j * (m - y));
				if ((tmp > -1) && (tmp < t || t == -1)) {
					t = tmp;
				}
			}
		}

		cout << t << "\n";
	}

	return 0;
}