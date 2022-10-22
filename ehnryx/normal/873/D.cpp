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

void solve(int start, int n, int k) {
	if (k == 0) {
		for (int i = 0; i < n; i++)
			cout << start+i << " ";
		return;
	}
	k -= 2;
	int half = n/2;
	int left = min(k, 2*half-2);
	solve(start + n - half, half, left);
	solve(start, n - half, k - left);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	if (k % 2 == 0) {
		cout << -1 << nl;
	} else if (k >= 2*n) {
		cout << -1 << nl;
	} else {
		solve(1, n, k-1);
		cout << nl;
	}

	return 0;
}