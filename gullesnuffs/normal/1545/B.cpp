#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll fac[100005];

ll powerMod(ll a, ll x) {
	if (!x)
		return 1;
	if (x%2)
		return (a*powerMod((a*a)%MOD, x/2))%MOD;
	return (powerMod((a*a)%MOD, x/2))%MOD;
}

ll modInv(ll a) {
	return powerMod(a, MOD-2);
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int empty = 0;
	int pairs = 0;
	rep(i,0,n) {
		if (s[i] == '0')
			++empty;
		else if (i+1 < n && s[i+1] == '1') {
			++pairs;
			++i;
		}
	}
	ll ans = fac[empty+pairs];
	ans = (ans*modInv(fac[empty]))%MOD;
	ans = (ans*modInv(fac[pairs]))%MOD;
	cout << ans << endl;
}

int main() {
	fac[0] = 1;
	rep(i,1,100005)
		fac[i] = (fac[i-1]*i)%MOD;
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}