#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	ll ans = 0;
	int x, d;
	for (int i=0; i<m; i++) {
		cin >> x >> d;
		ans += (ll)n*x;
		if (d >= 0) {
			ans += (ll)d * (n-1)*n/2;
		} else {
			int h = n/2;
			ans += (ll)d * (h+1)*h/2;
			h = n-h;
			ans += (ll)d * (h-1)*h/2;
		}
	}

	cout << (ld)ans/n << nl;

	return 0;
}