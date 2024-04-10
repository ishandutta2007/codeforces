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

	map<int,int> cnt;
	for (int i=0; i<n*n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	int ans[n][n];
	memset(ans, 0, sizeof ans);

	if (n%2 == 0) {
		for (const pii& it : cnt) {
			if (it.second%4 != 0) {
				cout << "NO" << nl;
				return 0;
			}
		}
		for (int i=0; i<n/2; i++) {
			for (int j=0; j<n/2; j++) {
				auto it = cnt.begin();
				it->second -= 4;
				ans[i][j] = it->first;
				if (it->second == 0) cnt.erase(it);
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!ans[i][j]) {
					if (i>=n/2) {
						ans[i][j] = ans[n-i-1][j];
					} else {
						ans[i][j] = ans[i][n-j-1];
					}
				}
			}
		}
	}

	else {
		for (auto& it : cnt) {
			if (it.second%2 == 1) {
				if (ans[n/2][n/2]) {
					cout << "NO" << nl;
					return 0;
				}
				ans[n/2][n/2] = it.first;
				it.second--;
			}
		}

		vector<int> twos;
		for (auto& it : cnt) {
			if (it.second%4 == 2) {
				it.second -= 2;
				twos.push_back(it.first);
			}
		}
		if (twos.size() > n-1) {
			cout << "NO" << nl;
			return 0;
		}

		for (auto it = cnt.begin(); it != cnt.end(); ) {
			if (it->second == 0) it = cnt.erase(it);
			else ++it;
		}

		for (int i=0; i<=n/2; i++) {
			for (int j=0; j<=n/2; j++) {
				if (!ans[i][j]) {
					if (i==n/2 || j==n/2) {
						if (twos.empty()) {
							auto it = cnt.begin();
							ans[i][j] = it->first;
							twos.push_back(it->first);
							it->second -= 4;
							if (it->second == 0) cnt.erase(it);
						} else {
							ans[i][j] = twos.back();
							twos.pop_back();
						}
					} else {
						auto it = cnt.begin();
						ans[i][j] = it->first;
						it->second -= 4;
						if (it->second == 0) cnt.erase(it);
					}
				}
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!ans[i][j]) {
					if (i>n/2) {
						ans[i][j] = ans[n-i-1][j];
					} else {
						ans[i][j] = ans[i][n-j-1];
					}
				}
			}
		}
	}

	cout << "YES" << nl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << nl;
	}

	return 0;
}