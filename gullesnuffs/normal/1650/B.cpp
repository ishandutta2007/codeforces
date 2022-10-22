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

ll f(ll a, ll x) {
	return (x/a)+(x%a);
}

void solve() {
	ll l, r, a;
	cin >> l >> r >> a;
	ll ans = f(a, r);
	ll x = (r/a)*a-1;
	if (x >= l) {
		ans = max(ans, f(a, x));
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