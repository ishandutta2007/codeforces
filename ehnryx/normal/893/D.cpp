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

	int ans = 0;
	int input = 0;
	int n, d;
	cin >> n >> d;

	int balance[n+1];
	int change[n+1];
	int room[n+1];
	balance[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> change[i];
		balance[i] = balance[i-1] + change[i];
	}

	if (balance[n] > d) {
		goto bad;
	}

	room[n] = d - balance[n];
	for (int i = n-1; i >= 0; i--) {
		room[i] = min(room[i+1], d-balance[i]);
		if (room[i] < 0) {
			goto bad;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (change[i] == 0 && balance[i] + input < 0) {
			ans++;
			input = room[i];
			if (balance[i] + input < 0) {
				goto bad;
			}
		}
	}

	cout << ans << nl;

	return 0;

bad:
	cout << -1 << nl;

	return 0;
}