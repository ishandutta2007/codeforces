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

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int n, m;
	n = m = 50;
	char grid[n][m];

	--a;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			grid[i][j] = 'A';
		}
	}

	--b;
	for (int i=0; i<23; i++) {
		for (int j=0; j<23; j++) {
			grid[i][j] = 'B';
		}
	}

	for (int i=0; i<21 && a; i += 2) {
		for (int j=0; j<21 && a; j += 2) {
			--a;
			grid[i][j] = 'A';
		}
	}

	for (int i=0; i<21 && b; i += 2) {
		for (int j=26; j<50 && b; j += 2) {
			--b;
			grid[i][j] = 'B';
		}
	}

	for (int i=26; i<50 && c; i += 2) {
		for (int j=26; j<50 && c; j += 2) {
			--c;
			grid[i][j] = 'C';
		}
	}

	for (int i=26; i<50 && d; i += 2) {
		for (int j=0; j<21 && d; j += 2) {
			--d;
			grid[i][j] = 'D';
		}
	}

	cout << n << " " << m << nl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << grid[i][j];
		}
		cout << nl;
	}

	return 0;
}