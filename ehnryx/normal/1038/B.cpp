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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	if (n <= 2) {
		cout << "No" << nl;
	}
	else if (n == 4) {
		cout << "Yes" << nl;
		cout << 2 << " " << 1 << " " << 4 << nl;
		cout << 2 << " " << 2 << " " << 3 << nl;
	}
	else {
		cout << "Yes" << nl;
		if (n%2 == 0) {
			cout << n/2;
			for (int i=1; i<=n/2; i++) {
				cout << " " << i;
			}
			cout << nl;
			cout << n/2;
			for (int i=1; i<=n/2; i++) {
				cout << " " << i+n/2;
			}
			cout << nl;
		}
		else {
			cout << 1 << " " << n/2+1 << nl;
			cout << n-1;
			for (int i=1; i<=n/2; i++) {
				cout << " " << i << " " << i+1+n/2;
			}
			cout << nl;
		}
	}

	return 0;
}