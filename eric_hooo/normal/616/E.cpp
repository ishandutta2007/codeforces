#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 1000000007;
const int inv2 = 500000004;

int main () {
	long long n, m; cin >> n >> m;
	long long ans = n % mod * (m % mod) % mod;
	if (m > n) m = n;
	for (long long l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		long long cl = l, cr = min(r, m);
		if (cl <= cr) {
			ans = (ans - ((cl + cr) % mod) * ((cr - cl + 1) % mod) % mod * inv2 % mod * (n / l % mod) % mod + mod) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}