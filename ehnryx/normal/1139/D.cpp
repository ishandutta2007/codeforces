#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;

const ll MOD = 1e9+7;

ll power(ll b, int e) {
  ll res = 1;
  for ( ; e>0; e/=2) {
    if (e&1) res = res*b % MOD;
    b = b*b % MOD;
  }
  return res;
}

ll inverse(ll x) {
	return power(x, MOD-2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;

	int primes[m+1];
	primes[1] = 0;
	for (int i=2; i<=m; i++) {
		primes[i] = 1;
		int lim = sqrt(i);
		for (int j=2; j<=lim; j++) {
			if (i%(j*j) == 0) {
				primes[i] = -1;
				break;
			}
			if (i%j == 0) {
				primes[i] = primes[j] + primes[i/j];
			}
		}
	}

	auto frac = [&] (ll n, ll d) {
		return n*inverse(d) % MOD;
	};

	ll dp[m+1];
	dp[1] = 0;
	for (int i=2; i<=m; i++) {
		vector<int> divs;
		int lim = sqrt(i);
		for (int j=1; j<=lim; j++) {
			if (i%j == 0) {
				divs.push_back(j);
				if (j*j != i) {
					divs.push_back(i/j);
				}
			}
		}

		//cerr << nl << "DO " << i << endl;

		ll denom = inverse(1-frac(m/i, m));
		ll res = 0;
		for (int d : divs) {
			if (d == i) continue;
			//cerr << " @@ " << d << endl;
			int cnt = 0;
			for (int u : divs) {
				if (u%d == 0) {
					int pfs = primes[u/d];
					if (pfs == -1) {
					} else if (pfs%2 == 0) {
						//cerr << "incl " << u << " +" << m/u << endl;
						cnt += m/u;
					} else {
						//cerr << "excl " << u << " -" << m/u << endl;
						cnt -= m/u;
					}
				}
			}
			//cerr << d << " from " << i << " cnt: " << cnt << endl;
			res += frac(cnt, m) * dp[d] % MOD;
		}
		dp[i] = (1 + res%MOD) * denom % MOD;
	}

	ll ans = 0;
	for (int i=1; i<=m; i++) {
		ans += dp[i] * frac(1,m) % MOD;
	}
	cout << (1 + ans%MOD + MOD) % MOD << nl;

	return 0;
}