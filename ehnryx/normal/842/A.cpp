#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define ldouble long double
#define nl '\n'
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for (int i = 1; k*i <= 1e7; i++) {
		if (l <= i*k && i*k <= r && x <= i && i <= y) {
			cout << "YES" << nl;
			return 0;
		}
	}
	cout << "NO" << nl;

	return 0;
}