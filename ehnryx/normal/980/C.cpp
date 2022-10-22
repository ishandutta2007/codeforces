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

	int n, k;
	cin >> n >> k;

	int ans[n];
	int key[256];
	memset(key, INF, sizeof key);

	int a;
	for (int i=0; i<n; i++) {
		cin >> a;
		if (key[a] == INF) {
			int start = max(0, a-k+1);
			while (key[start] < start) {
				start++;
			}
			for (int j=start; j<=a; j++) {
				key[j] = start;
			}
		}
		ans[i] = key[a];
	}

	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}