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

	int a[m], b[m];
	vector<int> memo[n+1];
	for (int i=0; i<m; i++) {
		cin >> a[i] >> b[i];
		memo[a[i]].push_back((b[i]-a[i]+n)%n);
	}
	for (auto& it : memo) {
		sort(it.begin(), it.end());
	}

	for (int s=1; s<=n; s++) {
		int ans = 0;
		for (int i=0; i<n; i++) {
			int pos = 1+(s-1+i)%n;
			if (memo[pos].empty()) continue;
			ans = max(ans, (int)(i + n*(memo[pos].size()-1) + memo[pos].front()));
		}
		cout << ans << " ";
	}
	cout << nl;

	return 0;
}