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
	ll n, k;
	cin >> n >> k;
	vector<ll> b(n);
	rep(i,0,n)
		cin >> b[i];
	ll diff = 0;
	ll a = 0;
	ll ans = 0;
	vector<ll> ddiff(n);
	for (ll i = n-1; i >= 0; --i) {
		a += diff;
		diff += ddiff[i];
		if (a < b[i]) {
			ll maxval = min(k, i+1);
			ll num = (b[i]-a+maxval-1)/maxval;
			ans += num;
			a += maxval*num;
			diff -= num;
			if (i-maxval >= 0) {
				ddiff[i-maxval] += num;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	solve();
}