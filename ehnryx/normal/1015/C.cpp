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
int a[N], b[N];

bool cmp(int i, int j) {
	return a[i]-b[i] > a[j]-b[j];
}

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

	vector<int> id;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
		id.push_back(i);
	}
	sort(id.begin(), id.end(), cmp);

	int ans = 0;
	for (int i : id) {
		if (sum <= m) break;
		sum += b[i]-a[i];
		ans++;
	}

	if (sum <= m) cout << ans << nl;
	else cout << -1 << nl;

	return 0;
}