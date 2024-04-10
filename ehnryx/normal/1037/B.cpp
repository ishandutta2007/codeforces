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

	int n, s;
	cin >> n >> s;

	int mv = n/2;

	int a[n];
	vector<int> small, large;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < s) small.push_back(a[i]);
		if (a[i] > s) large.push_back(a[i]);
	}
	sort(small.begin(), small.end());
	sort(large.begin(), large.end(), greater<int>());

	ll ans = 0;
	while (small.size() > mv) {
		ans += abs(s - small.back());
		small.pop_back();
	}
	while (large.size() > mv) {
		ans += abs(s - large.back());
		large.pop_back();
	}
	cout << ans << nl;

	return 0;
}