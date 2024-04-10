#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, M;
int W[MAXN];
int Q;
vector<int> tot;

int phi(int n)
{
	int result = 1;
	// multiplicativity of phi(n)
	for (int p=2; p*p<=n; ++p)
	{
		if (n % p == 0)
		{
			int d = 1;
			while (n % p == 0)
				n /= p, d *= p;
			result *= (d - d / p);
		}
	}
	if (n > 1)
		result *= (n - 1);
 
	return result;
}

LL modexp(LL a, LL b, LL mod) {
	if (b == 0) return 1 % mod;
	LL ret = modexp((a * a) % mod, b >> 1, mod);
	if (b % 2) ret = (ret * a) % mod;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}

	// phi(phi(phi(....))) takes at most log_3 steps
	// see evan chen blog
	tot.push_back(M);
	while (tot.back() != 1) {
		tot.push_back(phi(tot.back()));
		// cerr << "HI " << tot.back() << endl;
	}
	
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		--l;
		// [l, r)
		bool bad = false;
		r = min(r, l + (int) tot.size());
		LL actual = W[r - 1];
		LL ans = W[r - 1]; // at r - 1
		for (int i = r - 2; i >= l; i--) {

			int idx = i - l;
			int mod = tot[idx];

			ans = modexp(W[i], ans + bad * tot[idx + 1], mod);

			if (!bad) {
				LL base = W[i];
				if (base == 1) actual = 1;
				else {
					LL e = 0, cur = 1;
					while (e < actual) {
						++e;
						cur *= base;
						if (cur >= mod) {
							bad = true;
							break;
						}
					}
					actual = cur;
				}
			}

			if (W[i] == 1) {
				bad = false;
				actual = 1;
			}
		}
		cout << ans % M << '\n';
	}

	cout.flush();
	return 0;
}