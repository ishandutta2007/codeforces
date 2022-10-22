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

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n <= 2) {
		cout << 0 << nl;
		return 0;
	}

	unordered_set<int> diff;
	for (int d = -2; d <= 2; d++) {
		diff.insert(a[1]-a[0]+d);
	}

	for (int i = 2; i < n; i++) {
		unordered_set<int> nxt;
		for (int it : diff) {
			if (it >= a[i]-a[i-1]-2 || it <= a[i]-a[i-1]+2) {
				nxt.insert(it);
			}
		}
		diff = nxt;
	}

	int ans = INF;
	for (int d : diff) {
		for (int s = -1; s <= 1; s++) {
			int cur = a[0]+s;
			int cnt = (cur != a[0]);
			bool bad = false;
			for (int i = 1; i < n; i++) {
				if (abs(cur+d-a[i]) == 1) {
					cnt += 1;
				} else if (cur+d == a[i]) {
					cnt += 0;
				} else {
					bad = true;
				}
				cur += d;
			}
			if (!bad) ans = min(ans, cnt);
		}
	}

	if (ans < INF) cout << ans << nl;
	else cout << -1 << nl;

	return 0;
}