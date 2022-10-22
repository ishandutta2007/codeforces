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

	int n, m;
	cin >> n >> m;

	vector<int> a, b;
	for (int i = 0; i < n; i+=9) {
		a.push_back(9);
		b.push_back(0);
	}
	b[0] = 1;
	for (int i = 1; i < n; i+=9) {
		b.push_back(9);
	}
	reverse(b.begin(), b.end());

	for (int it : a) cout << it;
	cout << nl;
	for (int it : b) cout << it;
	cout << nl;

	return 0;
}