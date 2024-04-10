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

const int N = 700+1;
int a[N];
int dpl[N][N], dpr[N][N];
int pgcd[N][N];

bool lvalid(int, int);
bool rvalid(int, int);

bool lvalid(int l, int r) {
	if (l > r) return true;
	if (dpl[l][r] != -1) return dpl[l][r];

	for (int i = l; i <= r; i++) {
		if (pgcd[l-1][i] > 1) {
			if (rvalid(l, i-1) && lvalid(i+1, r)) {
				return dpl[l][r] = true;
			}
		}
	}
	return dpl[l][r] = false;
}

bool rvalid(int l, int r) {
	if (l > r) return true;
	if (dpr[l][r] != -1) return dpr[l][r];

	for (int i = l; i <= r; i++) {
		if (pgcd[i][r+1] > 1) {
			if (rvalid(l, i-1) && lvalid(i+1, r)) {
				return dpr[l][r] = true;
			}
		}
	}
	return dpr[l][r] = false;
}

void init() {
	memset(dpl, -1, sizeof dpl);
	memset(dpr, -1, sizeof dpr);
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
	init();

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			pgcd[i][j] = pgcd[j][i] = __gcd(a[i], a[j]);
		}
	}

	if (lvalid(1,n)) {
		cout << "Yes" << nl;
	} else {
		cout << "No" << nl;
	}

	return 0;
}