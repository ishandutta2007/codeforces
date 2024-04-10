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

	string s;
	cin >> s;

	vector<int> cnt(2,0);
	for (char c : s) {
		if (c == '1') {
			cout << 1 << " " << 1 + cnt[0] << nl;
			cnt[0] = (cnt[0] + 2) % 4;
		} else {
			cout << 3 << " " << 1 + cnt[1] << nl;
			cnt[1] = (cnt[1] + 1) % 4;
		}
	}

	return 0;
}