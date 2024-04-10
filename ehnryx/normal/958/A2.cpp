#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
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

	string real[n+1];
	string grid[m+1];
	for (int i = 1; i <= n; i++) {
		cin >> real[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> grid[i];
	}

	size_t hash_real[n+1];
	size_t hash_grid[n+1];
	for (int i = 1; i <= n-m+1; i++) {
		string cur;
		for (int j = 0; j < m; j++) {
			cur += real[i+j];
		}
		hash_real[i] = hash<string>()(cur);
	}
	for (int i = 1; i <= n-m+1; i++) {
		string cur;
		for (int j = 1; j <= m; j++) {
			cur += grid[j].substr(i-1, m);
		}
		hash_grid[i] = hash<string>()(cur);
	}

	for (int i = 1; i <= n-m+1; i++) {
		for (int j = 1; j <= n-m+1; j++) {
			if (hash_real[i] == hash_grid[j]) {
				cout << i << " " << j << nl;
				return 0;
			}
		}
	}

	return 0;
}