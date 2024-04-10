#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v = { a, b, c };
	sort(v.begin(), v.end());
	if (v[0] == 1) {
		cout << "YES" << nl;
	}
	else if (v[0] == 2 && v[1] == 2) {
		cout << "YES" << nl;
	}
	else if (v[0] == 3 && v[1] == 3 && v[2] == 3) {
		cout << "YES" << nl;
	}
	else if (v[0] == 2 && v[1] == 4 && v[2] == 4) {
		cout << "YES" << nl;
	}
	else {
		cout << "NO" << nl;
	}

	return 0;
}