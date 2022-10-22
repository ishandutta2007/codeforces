#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	ll x, k;
	cin >> n >> x >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll lower = ((a[i]-1)/x + k) * x;
		ll upper = lower + x-1;
		lower = max(lower, a[i]);
		ans += upper_bound(a.begin(), a.end(), upper) - lower_bound(a.begin(), a.end(), lower);
	}
	cout << ans << nl;

	return 0;
}