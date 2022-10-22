#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll powMod(ll a, ll x) {
	if (!x)
		return 1;
	if (x%2)
		return (a*powMod((a*a)%MOD, x/2))%MOD;
	return powMod((a*a)%MOD, x/2);
}

void solve() {
	ll n, k;
	cin >> n >> k;
	ll ways = 1;
	ll ans = 0;
	rep(i,0,k) {
		if (n%2) {
			ways *= powMod(2, n-1)+1;
		} else {
			ans += ways*powMod(2, n*(k-i-1));
			ways *= powMod(2, n-1)-1;
		}
		ways %= MOD;
		ans %= MOD;
	}
	ans += ways;
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}