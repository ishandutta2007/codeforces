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
1
?W
*/
/*input
2
??
W?
*/
/*input
4
BB
??
W?
??
*/

const long long mod = 998244353;
const long long maxn = 200020;
long long fakt[maxn];
long long faktinv[maxn];
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

long long C(long long n, long long k) {
	if (n < 0 or k < 0 or n < k) {
		return 0;
	}

	return MOD(MOD(fakt[n] * faktinv[k]) * faktinv[n - k]);
}

int main() {
	fakt[0] = 1;

	for (int i = 1; i < maxn; ++i) {
		fakt[i] = MOD(fakt[i - 1] * i);
	}

	faktinv[maxn - 1] = modInverse(fakt[maxn - 1]);

	for (int i = maxn - 2; i >= 0; --i) {
		faktinv[i] = MOD(faktinv[i + 1] * (i + 1));
	}

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	map<string, long long> a;
	map<char, long long> pirm, antr;
	long long n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string x;
		cin >> x;
		a[x]++;
		pirm[x[0]]++;
		antr[x[1]]++;
	}

	if (pirm['W'] + antr['W'] > n or pirm['B'] + antr['B'] > n) {
		cout << "0";
		exit(0);
	}

	long long ans = C(pirm['?'] + antr['?'], n - pirm['W'] - antr['W']);

	if (a["BB"] == 0 and a["WW"] == 0) {
		ans -= power(2, a["??"]);

		if (a["?W"] + a["BW"] + a["??"] + a["B?"] == n) {
			ans++;
		}

		if (a["?B"] + a["WB"] + a["??"] + a["W?"] == n) {
			ans++;
		}
	}

	ans = MOD(MOD(ans) + mod);

	cout << ans;
}