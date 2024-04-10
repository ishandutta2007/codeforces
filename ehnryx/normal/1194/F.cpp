#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
int t[N];
ll fact[N], invf[N], two[N];

ll power(ll b, ll e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}
ll inverse(ll n) {
	return power(n, MOD-2);
}
ll ncr(ll n, ll r) {
	if (r<0 || r>n) return 0;
	return fact[n] * (invf[r]*invf[n-r] % MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	fact[0] = invf[0] = 1;
	two[0] = 1;
	FOR(i,1,N-1) {
		fact[i] = i * fact[i-1] % MOD;
		invf[i] = inverse(fact[i]);
		two[i] = 2 * two[i-1] % MOD;
	}

	int n; ll T;
	cin >> n >> T;
	For(i,n) {
		cin >> t[i];
	}

	ll tot = 0;
	int id = 0;
	while (id<n && tot+t[id]<=T) {
		tot += t[id++];
	}

	ll ans = 0;
	FOR(add,0,id) {
		if (tot+add > T) {
			if (id == 0) break;
			assert(add>0);
			ll prob = inverse(two[id]) * ncr(id-1,add-1) % MOD;
			ans += (id-1) * prob % MOD;
			tot -= t[--id];
		}
		ll prob = inverse(two[id]) * ncr(id,add) % MOD;
		ans += id * prob % MOD;
	}
	cout << ans % MOD << nl;

	return 0;
}