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

	int n, m;
	cin >> n >> m;

	if (m < n-1) {
		cout << "Impossible" << nl;
		return 0;
	}

	int cnt = 0;
	vector<pii> edges;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (__gcd(i,j) == 1) {
				edges.push_back(pii(i,j));
				if (++cnt == m) {
					cout << "Possible" << nl;
					for (const pii& it : edges) {
						cout << it.first << " " << it.second << nl;
					}
					return 0;
				}
			}
		}
	}

	cout << "Impossible" << nl;

	return 0;
}