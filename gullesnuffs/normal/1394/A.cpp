#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n, d, m;
	cin >> n >> d >> m;
	vector<ll> a(n);
	vector<ll> small, large;
	rep(i,0,n) {
		cin >> a[i];
		if (a[i] > m)
			large.push_back(a[i]);
		else
			small.push_back(a[i]);
	}
	sort(all(small));
	reverse(all(small));
	sort(all(large));
	reverse(all(large));
	ll sum = 0;
	ll prevSmall = sz(small);
	for (ll x : small)
		sum += x;
	ll ans = 0;
	for (int numLarge = 0; numLarge <= sz(large); numLarge++) {
		if (numLarge > 0)
			sum += large[numLarge-1];
		ll numSmall = min(ll(sz(small)), min(n, n-1-(numLarge-1)*(d+1)));
		if (numSmall < 0)
			continue;
		while (prevSmall > numSmall) {
			sum -= small[--prevSmall];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}