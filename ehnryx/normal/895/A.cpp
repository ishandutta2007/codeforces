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
	cin >> n;

	int a[2*n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[n+i] = a[i];
	}

	int ans = INF;
	int pref[2*n+1];
	pref[0] = 0;
	for (int i = 1; i < 2*n; i++) {
		pref[i] = pref[i-1] + a[i-1];
		for (int j = 0; j <= i; j++) {
			ans = min(ans, abs(pref[i] - pref[j] - 180));
		}
	}
	cout << 2*ans << nl;

	return 0;
}