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

bool ispalindrome(const string& s, int i, int j) {
	for (int k=0; k<j-i+1; k++) {
		if (s[i+k] != s[j-k]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;

	int ans = 0;

	int n = s.size();
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (!ispalindrome(s, i, j)) {
				ans = max(ans, j-i+1);
			}
		}
	}

	cout << ans << nl;

	return 0;
}