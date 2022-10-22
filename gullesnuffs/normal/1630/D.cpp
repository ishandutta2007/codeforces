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

ll solve2(vector<ll> a, int g) {
	vector<vector<ll>> b(g);
	rep(i,0,sz(a))
		b[i%g].push_back(a[i]);
	ll ret = 0;
	rep(i,0,g) {
		sort(all(b[i]));
		for (int j = 0; j+1 < sz(b[i]); j += 2) {
			ret += abs(b[i][j]+b[i][j+1]);
		}
		if (sz(b[i])%2)
			ret += b[i].back();
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i,0,n)
		cin >> a[i];
	vi b(m);
	rep(i,0,m)
		cin >> b[i];
	int g = b[0];
	rep(i,0,m)
		g = __gcd(g, b[i]);
	ll ans = solve2(a, g);
	rep(i,0,g)
		a[i] *= -1;
	ans = max(ans, solve2(a, g));
	cout << ans << endl;
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}