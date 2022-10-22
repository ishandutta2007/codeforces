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

const int N = 2e5+1;
int b[N];
ll a[N];

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

	int minv = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] < b[minv]) minv = i;
	}

	int maxv = minv;
	for (int i = 0; i < n; i++) {
		if (b[(i+minv)%n] > b[maxv]) maxv = (i+minv)%n;
	}

	if (maxv == minv) {
		if (b[0] == 0) {
			cout << "YES" << nl;
			for (int i = 0; i < n; i++) {
				cout << 1 << " ";
			}
			cout << nl;
		}
		else {
			cout << "NO" << nl;
		}
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int j = (maxv+n-i) % n;
		int pre = (j+1) % n;
		int nxt = (j+n-1) % n;

		if (b[j] > b[nxt]) {
			a[j] = b[j];
		}
		else {
			ll k = (b[nxt] - b[j] + a[pre]) / a[pre];
			a[j] = k*a[pre] + b[j];
		}
	}

	cout << "YES" << nl;
	for (int i = 0; i < n; i++) {
		assert(a[i] % a[(i+1)%n] == b[i]);
		cout << a[i] << " ";
	}
	cout << nl;

	return 0;
}