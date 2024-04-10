#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 20;
int a[N][N];

bool solve(int n, int m, int x, int y) {
	for (int i=0; i<n; i++) {
		swap(a[i][x], a[i][y]);
	}
	for (int i=0; i<n; i++) {
		int bad = 0;
		for (int j=0; j<m; j++) {
			bad += (a[i][j] != j+1);
		}
		if (bad > 2) {
			goto undo;
		}
	}
	return true;
	undo:
	for (int i=0; i<n; i++) {
		swap(a[i][x], a[i][y]);
	}
	return false;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			if (solve(n,m,i,j)) {
				cout << "YES" << nl;
				return 0;
			}
		}
	}
	cout << "NO" << nl;

	return 0;
}