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

const long long maxn = 1000020;
long long fakt[maxn];
long long faktinv[maxn];
int zero = []() -> int{
	fakt[0] = 1;

	for (int i = 1; i < maxn; ++i) {
		fakt[i] = MOD(fakt[i - 1] * i);
	}

	faktinv[maxn - 1] = modInverse(fakt[maxn - 1]);

	for (int i = maxn - 2; i >= 0; --i) {
		faktinv[i] = MOD(faktinv[i + 1] * (i + 1));
	}

	return 0;
}();

long long C(long long n, long long k) {
	if (n < 0 or k < 0 or n < k) {
		return 0;
	}

	return MOD(MOD(fakt[n] * faktinv[k]) * faktinv[n - k]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		long long n, m, k;
		cin >> n >> m >> k;
		debug(n, m, k);
		long long dd = 0;

		for (long long j = 1; j <= m; ++j) {
			long long ff = MOD(j * 2 * k - k);
			dd += MOD(C(n - 1, m - j) * ff);
			dd = MOD(dd);
		}

		cout << MOD(MOD(dd * power(modInverse(2), n - 1)) + mod) << "\n";
	}
}