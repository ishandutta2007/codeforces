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

	int n, m, k;
	cin >> n >> m >> k;

	int minv = INF, maxv = -INF;
	int a = INF, b;
	vector<int> diff;
	for (int i=0; i<n; i++) {
		cin >> b;
		minv = min(minv, b);
		maxv = max(maxv, b);
		diff.push_back(b-a-1);
		a = b;
	}
	sort(diff.begin(), diff.end(), greater<int>());

	int sum = 0;
	for (int i=0; i<k-1; i++) {
		sum += diff[i];
	}
	cout << maxv-minv+1 - sum << nl;

	return 0;
}