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

	string a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<char> p = {'A','C','G','T'};
	sort(p.begin(), p.end());

	int best = INF;
	char ans[n][m];
	char cur[n][m];

	do {
		int sum = 0;
		int cnt1, cnt2;
		for (int i=0; i<n; i++) {
			cnt1 = cnt2 = m;
			if (i%2 == 0) {
				for (int j=0; j<m; j++) {
					cnt1 -= (p[j%2] == a[i][j]);
					cnt2 -= (p[(j%2)^1] == a[i][j]);
				}
				if (cnt1 < cnt2) {
					for (int j=0; j<m; j++) {
						cur[i][j] = p[j%2];
					}
				} else {
					for (int j=0; j<m; j++) {
						cur[i][j] = p[(j%2)^1];
					}
				}
			} else {
				for (int j=0; j<m; j++) {
					cnt1 -= (p[2+j%2] == a[i][j]);
					cnt2 -= (p[2+((j%2)^1)] == a[i][j]);
				}
				if (cnt1 < cnt2) {
					for (int j=0; j<m; j++) {
						cur[i][j] = p[2+j%2];
					}
				} else {
					for (int j=0; j<m; j++) {
						cur[i][j] = p[2+((j%2)^1)];
					}
				}
			}
			sum += min(cnt1, cnt2);
		}
		if (sum < best) {
			best = sum;
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					ans[i][j] = cur[i][j];
				}
			}
		}

		sum = 0;
		for (int j=0; j<m; j++) {
			cnt1 = cnt2 = n;
			if (j%2 == 0) {
				for (int i=0; i<n; i++) {
					cnt1 -= (p[i%2] == a[i][j]);
					cnt2 -= (p[(i%2)^1] == a[i][j]);
				}
				if (cnt1 < cnt2) {
					for (int i=0; i<n; i++) {
						cur[i][j] = p[i%2];
					}
				} else {
					for (int i=0; i<n; i++) {
						cur[i][j] = p[(i%2)^1];
					}
				}
			} else {
				for (int i=0; i<n; i++) {
					cnt1 -= (p[2+i%2] == a[i][j]);
					cnt2 -= (p[2+((i%2)^1)] == a[i][j]);
				}
				if (cnt1 < cnt2) {
					for (int i=0; i<n; i++) {
						cur[i][j] = p[2+i%2];
					}
				} else {
					for (int i=0; i<n; i++) {
						cur[i][j] = p[2+((i%2)^1)];
					}
				}
			}
			sum += min(cnt1, cnt2);
		}
		if (sum < best) {
			best = sum;
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					ans[i][j] = cur[i][j];
				}
			}
		}
	} while (next_permutation(p.begin(), p.end()));

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << ans[i][j];
		}
		cout << nl;
	}

	return 0;
}