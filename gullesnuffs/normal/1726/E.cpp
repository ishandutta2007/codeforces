#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> fact_cache;

ll fact(int n) {
	return fact_cache[n];
}

/*ll binom(int n, int k) {
	if (k < 0 || k > n)
		return 0;
	return fact(n)/fact(k)/fact(n-k);
}*/

ll powerMod(ll a, ll x) {
	if (!x)
		return 1;
	if (x%2)
		return (a*(powerMod((a*a)%MOD, x/2)))%MOD;
	return (powerMod((a*a)%MOD, x/2))%MOD;
}

ll pow2(int n) {
	return powerMod(2, n);
}

ll inv(ll a) {
	return powerMod(a, MOD-2);
}

map<int, ll> weird_sum_cache;

ll weird_sum(int n) {
	if (weird_sum_cache.count(n))
		return weird_sum_cache[n];
	if (n <= 2) {
		ll s = 0;
		for (int k = 0; 2*k <= n; k++) {
			s += fact(n)/(fact(n-2*k)*pow2(k)*fact(k));
		}
		weird_sum_cache[n] = s;
		return s;
	}
	ll s = 0;
	s = (weird_sum(n-1)+(n-1)*weird_sum(n-2))%MOD;
	weird_sum_cache[n] = s;
	return s;
}

ll solve2(int n) {
	ll ret = 0;
	rep(k4,0,n+1) {
		if (4*k4 > n)
			continue;
	/*rep(k2,0,n+1) {
		if (2*k2+4*k4 > n)
			continue;*/
		/*ll x = binom(n-2*k4, 2*k4);
		x = x * binom(n-4*k4, 2*k2);
		x = x * (fact(2*k2)/(pow2(k2)*fact(k2)));
		x = x * (fact(2*k4)/(fact(k4)));*/
		ll x = fact(n-2*k4);
		x = (x * inv(fact(k4)))%MOD;
		x = (((x * weird_sum(n-4*k4))%MOD) * inv(fact(n-4*k4)))%MOD;
		/*ll x = fact(n-2*k4);
		x /= fact(n-4*k4-2*k2);
		x /= fact(k2);
		x /= fact(k4);
		x /= pow2(k2);*/
		ret += x;
		ret %= MOD;
		//int k1 = n-4*k4-2*k2;
		/*cerr << k1 << " single, " << k2 << " pairs, " << k4 << " fours" << endl;
		cerr << x << endl << endl;*/
	}
	//}
	return ret;
}

void solve(int n) {
	rep(n,1,20) {
		cerr << weird_sum(n) << ",";
	}
	cerr << endl;
	vector<int> p(n);
	rep(i,0,n)
		p[i] = i;
	int ans = 0;
	do {
		bool ok = true;
		rep(i,0,n) {
			if (abs(p[p[i]]-i) > 1)
				ok = false;
		}
		if (ok) {
			rep(i,0,n) {
				assert(p[p[p[p[i]]]] == i);
			}
		}
		ans += ok;
	} while (next_permutation(all(p)));
	cout << ans << endl;
	assert(solve2(n) == ans);
}

int main() {
	fact_cache.push_back(1);
	rep(n,1,1000005)
		fact_cache.push_back((fact_cache.back()*n)%MOD);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	/*rep(n,1,100) {
		cerr << n << ": ";
		solve(n);
	}*/
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << solve2(n) << endl;
	}
}