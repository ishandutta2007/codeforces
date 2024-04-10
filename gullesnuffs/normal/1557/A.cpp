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

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll tot = 0;
	ll maxval = -2e9;
	rep(i,0,n) {
		cin >> a[i];
		tot += a[i];
		maxval = max(maxval, a[i]);
	}
	double b = (tot-maxval)/(n-1.0);
	double ans = b + maxval;
	cout << setprecision(9) << fixed << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}