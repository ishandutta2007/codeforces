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

	int n, k;
	cin >> n >> k;
	cout << "YES" << nl;

	char grid[4][n];
	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			grid[i][j] = '.';
		}
	}

	if (k%2 == 0) {
		for (int i=1; i<=k/2; i++) {
			grid[1][i] = grid[2][i] = '#';
		}
	}
	else if (k < n) {
		for (int i=0; i<=k/2; i++) {
			grid[1][n/2+i] = grid[1][n/2-i] = '#';
		}
	} else {
		grid[2][1] = grid[2][n-2] = '#';
		for (int i=1; i<=n-2; i++) {
			grid[1][i] = '#';
		}
		for (int i=0; i<k-n; i++) {
			grid[2][2+i] = '#';
		}
	}

	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			cout << grid[i][j];
		}
		cout << nl;
	}

	return 0;
}