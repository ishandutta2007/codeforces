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

typedef vector<vector<ll>> Matrix;
Matrix multiply(const Matrix& a, const Matrix& b) {
	int m = a.size();
	Matrix c(m, vector<ll>(m,0));
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<m; k++) {
				c[i][j] += a[i][k]*b[k][j] % MOD;
			}
			c[i][j] %= MOD;
		}
	}
	return c;
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

	ll n; int m;
	cin >> n >> m;

	if (n<m) {
		cout << 1 << nl;
		return 0;
	}

	Matrix mat(m, vector<ll>(m,0));
	Matrix mlt(m, vector<ll>(m,0));
	for (int i=0; i<m; i++) {
		mlt[i][i] = 1;
	}
	mat[0][0] = mat[0][m-1] = 1;
	for (int i=1; i<m; i++) {
		mat[i][i-1] = 1;
	}

	for (n = n-m+1; n>0; n/=2) {
		if (n&1) mlt = multiply(mlt, mat);
		mat = multiply(mat, mat);
	}

	ll ans = 0;
	for (int j=0; j<m; j++) {
		ans += mlt[0][j];
	}
	cout << ans % MOD << nl;

	return 0;
}