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

const int N = 1e5+1;
int deg[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int a, b;
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}

	vector<int> leaves;
	vector<int> center;
	for (int i=1; i<=n; i++) {
		if (deg[i] == 1) leaves.push_back(i);
		if (deg[i] > 2) center.push_back(i);
	}

	if (center.size() > 1) {
		cout << "No" << nl;
	}
	else if (center.size() == 0) {
		cout << "Yes" << nl;
		cout << 1 << nl;
		cout << leaves.front() << " " << leaves.back() << nl;
	}
	else {
		cout << "Yes" << nl;
		cout << leaves.size() << nl;
		for (int it : leaves) {
			cout << center[0] << " " << it << nl;
		}
	}

	return 0;
}