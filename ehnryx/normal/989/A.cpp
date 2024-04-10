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

	string s;
	cin >> s;
	int n = s.size();

	for (int i=1; i+1<n; i++) {
		set<char> m;
		m.insert(s[i-1]);
		m.insert(s[i]);
		m.insert(s[i+1]);
		if (m.size() == 3 && !m.count('.')) {
			cout << "Yes" << nl;
			return 0;
		}
	}
	cout << "No" << nl;

	return 0;
}