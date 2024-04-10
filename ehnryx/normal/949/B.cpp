#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll solve(ll n, ll x) {
	if (n == 1) return 1;
	if (x % 2 == 1) return (x+1)/2;

	if (n % 2 == 0) {
		return solve(n/2, x/2) + n/2;
	} else {
		return solve(n/2 + 1, x/2 + 1) + n/2;
	}
}

int main() {
	//ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	ll n, q, x;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << solve(n, x) << nl;
	}

	return 0;
}