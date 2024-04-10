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
	int n = s.size();
	string t;

	int na = 0;
	for (char c : s) {
		if (c != 'a') {
			na++;
			t.push_back(c);
		}
	}

	if (na%2 != 0) {
		cout << ":(" << nl;
		return 0;
	}

	for (int i=0; i<na/2; i++) {
		if (t[i] != t[i+na/2]) {
			cout << ":(" << nl;
			return 0;
		}
	}

	for (int i=1; i<=na/2; i++) {
		if (s[n-i] == 'a') {
			cout << ":(" << nl;
			return 0;
		}
	}

	for (int i=0; i<n-na/2; i++) {
		cout << s[i];
	}
	cout << nl;

	return 0;
}