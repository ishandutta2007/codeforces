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

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s;
	cin >> t;

	int i = s.find('*');
	if (i == -1) {
		cout << (s == t ? "YES" : "NO") << nl;
	}
	else {
		if (n-1 > m) {
			cout << "NO" << nl;
		} else {
			int right = n-(i+1);
			cout << (s.substr(0,i) == t.substr(0,i) && s.substr(i+1,right) == t.substr(m-right, right) ? "YES" : "NO") << nl;
		}
	}

	return 0;
}