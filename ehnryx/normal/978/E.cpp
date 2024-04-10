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

	int n, w;
	cin >> n >> w;

	int a, maxv, minv, cur;
	cur = maxv = minv = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cur += a;
		maxv = max(maxv, cur);
		minv = min(minv, cur);
	}

	cout << max(0, w+1 - (maxv-minv)) << nl;

	return 0;
}