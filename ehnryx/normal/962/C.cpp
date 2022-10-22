#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;

	int ans = INF;
	int len = s.size();
	for (int bm = 1; bm < 1<<len; bm++) {
		int n = 0;
		for (int i = 0; i < len; i++) {
			if (bm & 1<<i) {
				n = n*10 + (s[i]-'0');
				if (n == 0) {
					n = 2;
					break;
				}
			}
		}
		int rt = llround(sqrt(n));
		if (rt*rt == n) {
			ans = min(ans, len - __builtin_popcount(bm));
		}
	}
	cout << (ans == INF ? -1 : ans) << nl;

	return 0;
}