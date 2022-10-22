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

	int ones = 0;
	int twos = 0;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		if (a==1) ones++;
		else twos++;
	}

	if (!ones) {
		for (int i=0; i<twos; i++) {
			cout << 2 << " ";
		}
		cout << nl;
	} else if (!twos) {
		for (int i=0; i<ones; i++) {
			cout << 1 << " ";
		}
		cout << nl;
	} else {
		cout << 2 << " " << 1 << " ";
		--ones; --twos;
		for (int i=0; i<twos; i++) {
			cout << 2 << " ";
		}
		for (int i=0; i<ones; i++) {
			cout << 1 << " ";
		}
		cout << nl;
	}

	return 0;
}