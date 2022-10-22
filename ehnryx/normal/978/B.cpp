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

	string s;
	cin >> s;

	int cnt = 0;
	int ans = 0;
	for (char c : s) {
		if (c == 'x') {
			cnt++;
		} else {
			ans += max(0, cnt-2);
			cnt = 0;
		}
	}
	ans += max(0, cnt-2);
	cout << ans << nl;

	return 0;
}