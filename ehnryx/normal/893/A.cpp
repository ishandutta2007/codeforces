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

	bitset<4> on[107];
	int a[105];

	int n;
	cin >> n;

	on[0][1] = on[0][2] = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (on[i-1][a[i]]) {
			for (int j = 1; j <= 3; j++)
				on[i][j] = !on[i-1][j];
			on[i][a[i]] = true;
		}
		else {
			goto bad;
		}
	}
	cout << "YES" << nl;

	return 0;

bad:
	cout << "NO" << nl;

	return 0;
}