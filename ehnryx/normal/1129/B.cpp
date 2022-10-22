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

const int N = 2e3;
const int M = 1e6;

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int k;
	cin >> k;

	for (int len=1; len<=N; len++) {
		for (int m=1; m<len; m++) {
			if ((k+len) % (len-m) == 0 && (k+len)/(len-m) <= m*M) {
				cout << len << nl;
				for (int i=0; i<len-m-1; i++) {
					cout << 0 << " ";
				}
				cout << -1 << " ";
				int cur = (k+len)/(len-m);
				for (int i=0; i<m; i++) {
					cout << min(cur,M) << " ";
					cur -= min(cur,M);
				}
				cout << nl;
				return 0;
			}
		}
	}

	cout << -1 << nl;

	return 0;
}