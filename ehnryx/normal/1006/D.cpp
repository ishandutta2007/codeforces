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

	string s, t;
	cin >> s;
	cin >> t;

	int ans = 0;
	if (n % 2 == 1) {
		if (s[n/2] != t[n/2]) ans++;
	}

	for (int i=0; i<n/2; i++) {
		if (t[i] == t[n-1-i]) {
			ans += (s[i] != s[n-1-i]);
		}
		else if (t[i] == s[i]) {
			ans += (s[n-1-i] != t[n-1-i]);
		}
		else if (t[i] == s[n-1-i]) {
			ans += (s[i] != t[n-1-i]);
		}
		else if (t[n-1-i] == s[i]) {
			ans += (s[n-1-i] != t[i]);
		}
		else if (t[n-1-i] == s[n-1-i]) {
			ans += (s[i] != t[i]);
		}
		else {
			ans += 2;
		}
	}

	cout << ans << nl;

	return 0;
}