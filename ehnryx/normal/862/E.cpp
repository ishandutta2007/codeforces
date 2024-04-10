#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	ll a[n];
	ll b[m];
	ll asum = 0;
	ll bsumpref = 0;
	set<ll> bsum;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i%2 == 0) asum += a[i];
		else asum -= a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (i%2 == 0) bsumpref += b[i];
		else bsumpref -= b[i];
		if (i >= n) {
			if ((i-n)%2 == 0) bsumpref -= b[i-n];
			else bsumpref += b[i-n];
		}
		// store bsumpref
		if (i >= n-1) {
			if ((i-n+1)%2 == 0) bsum.insert(bsumpref);
			else bsum.insert(-bsumpref);
		}
	}

	set<ll>::iterator ans;
	ans = bsum.lower_bound(asum);
	if (ans == bsum.end()) {
		cout << abs(asum - *prev(ans)) << nl;
	} else if (ans == bsum.begin()) {
		cout << abs(asum - *ans) << nl;
	} else {
		cout << min(abs(asum - *ans), abs(asum - *prev(ans))) << nl;
	}

	int left, right;
	ll upd;
	for (int i = 0; i < q; i++) {
		cin >> left >> right >> upd;
		if ((right-left+1) % 2 != 0) {
			if (left % 2 == 1) asum += upd;
			else asum -= upd;
		}
		ans = bsum.lower_bound(asum);
		if (ans == bsum.end()) {
			cout << abs(asum - *prev(ans)) << nl;
		} else if (ans == bsum.begin()) {
			cout << abs(asum - *ans) << nl;
		} else {
			cout << min(abs(asum - *ans), abs(asum - *prev(ans))) << nl;
		}
	}

	return 0;
}