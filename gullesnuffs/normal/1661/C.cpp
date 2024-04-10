#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve(vector<ll> h, ll target) {
	ll ones = 0, twos = 0;
	for (ll H : h) {
		ll t = (target-H)/2;
		ll o = target-H-2*t;
		ones += o;
		twos += t;
	}
	if (ones > twos) {
		return ones*2-1;
	}
	if (ones == twos) {
		return ones+twos;
	}
	ll twos_to_split = (twos-ones+1)/3;
	twos -= twos_to_split;
	ones += 2*twos_to_split;
	if (ones > twos) {
		return ones*2-1;
	} else {
		return twos*2;
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> h(n);
	ll target = 0;
	rep(i,0,n) {
		cin >> h[i];
		target = max(target, h[i]);
	}
	ll ans = 1e18;
	for (ll t = target; t <= target+2; t++) {
		ans = min(ans, solve(h, t));
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}