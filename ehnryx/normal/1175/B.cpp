#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll cap = 1LL<<32;

ll solve() {
	ll res = 0;
	string s;
	while (cin >> s) {
		if (s == "for") {
			ll a;
			cin >> a;
			ll b = solve();
			if (b >= cap) return b;
			if (a*b >= cap) return a*b;
			if (res + a*b >= cap) return res+a*b;
			res += a*b;
		} else if (s == "end") {
			return res;
		} else {
			res++;
			if (res >= cap) return res;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	ll ans = solve();
	if (ans >= cap) {
		cout << "OVERFLOW!!!" << nl;
	} else {
		cout << ans << nl;
	}

	return 0;
}