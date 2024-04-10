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

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

inline ld sqr(ld x) { return x*x; }


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, r;
	cin >> n >> r;

	ld ans[n];
	int x[n];

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		ans[i] = r;
		for (int j = 0; j < i; j++) {
			if (abs(x[i] - x[j]) <= 2*r) {
				ans[i] = max(ans[i], ans[j] + sqrt(sqr(2*r) - sqr(x[i]-x[j])));
			}
		}
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}