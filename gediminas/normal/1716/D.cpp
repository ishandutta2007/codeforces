#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long sqrtn = 700;
const long long maxn = 200000;
const long long mod = 998244353;
#define MOD(x) ((x)%mod)
long long power(long long x, long long n) {
	long long i = 1;
	long long d = x;
	long long ats = 1;

	while (n > 0) {
		if (n & i) {
			n ^= i;
			ats *= d;
			ats %= mod;
		}

		i <<= 1;
		d = (d * d) % mod;
	}

	return ats;
}

long long modInverse(long long a) {
	return power(a, mod - 2);
}

/*input
8 1
*/
/*input
10 2
*/
/*input
200000 1
*/
long long din[2][maxn + 1] = {};
long long ans[maxn + 1] = {};


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, k;
	cin >> n >> k;
	din[0][0] = 1;

	for (int i = 0; i < sqrtn; ++i) {
		int st = i + k;
		int X = i % 2;
		int Y = 1 - X;

		for (int j = 0; j <= n; ++j) {
			ans[j] += din[Y][j];
			ans[j] %= mod;
			din[Y][j] = 0;
		}

		for (int j = 0; j < n; ++j) {
			int t = j + st;

			if (t <= n) {
				din[Y][t] += din[X][j] + din[Y][j];
				din[Y][t] %= mod;
			}
		}
	}

	for (int j = 0; j <= n; ++j) {
		ans[j] += din[n % 2][j];
		ans[j] %= mod;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i + 1] << " ";
	}
}