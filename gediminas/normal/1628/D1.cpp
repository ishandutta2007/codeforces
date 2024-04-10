#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
7
3 3 2
2 1 10
6 3 10
6 4 10
100 1 1
4 4 0
69 4 20
*/

const long long mod = 1000000007;
#define MOD(x) ((x)%mod)
long long power(long long x, long long n) {
	int i = 0;
	long long d = x;
	long long ats = 1;

	while (n > 0) {
		if (n & (1ll << i)) {
			n ^= (1ll << i);
			ats *= d;
			ats %= mod;
		}

		i++;
		d = (d * d) % mod;
	}

	return ats;
}
long long modInverse(long long a) {
	return power(a, mod - 2);
}

pair<long long, long long> avg(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second < b.second) {
		swap(a, b);
	}

	b.first = MOD(b.first * power(2, a.second - b.second));
	return {MOD(a.first + b.first), a.second + 1};
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		long long n, m, k;
		cin >> n >> m >> k;
		debug(n, m, k);
		pair<long long, long long> din[n + 1][m + 1];

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (j == 0) {
					din[i][j] = {0, 0};
				}
				else if (j == i) {
					din[i][j] = {MOD(j * k), 0};
				}
				else if (j > i) {
					break;
				}
				else {
					auto t = din[i - 1][j - 1];
					din[i][j] = avg(din[i - 1][j], t);
				}

				// debug(i, j, din[i][j]);
			}
		}

		cout << MOD(MOD(din[n][m].first * power(modInverse(2), din[n][m].second)) + mod) << "\n";
	}
}