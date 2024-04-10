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

const int N = 2e5+1;
int a[N];

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

	vector<int> order;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		order.push_back(a[i]);
	}
	sort(order.begin(), order.end(), greater<int>());

	int minv = INF;
	ll sum = 0;
	for (int i=0; i<m*k; i++) {
		minv = min(minv, order[i]);
		sum += order[i];
	}
	int allowed = 0;
	for (int i=0; i<m*k; i++) {
		allowed += (order[i] == minv);
	}

	cout << sum << nl;
	int cnt = 0;
	int tot = 1;
	for (int i=0; i<n; i++) {
		if (a[i] > minv) cnt++;
		else if (a[i] == minv && --allowed >= 0) cnt++;
		if (cnt == m && tot < k) {
			tot++;
			cnt = 0;
			cout << i+1 << " ";
		}
	}
	cout << nl;

	return 0;
}