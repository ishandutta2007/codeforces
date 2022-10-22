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

	unordered_set<int> vals;
	for (int i = 1; i <= m; i++) {
		vals.insert(i);
	}

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			vals.erase(j);
		}
	}

	cout << vals.size() << nl;
	for (int it : vals) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}