#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

int solve(ll ub) {
	ll b2, b3;
	for (b2 = 1; b2 <= ub; b2 *= 2) ;
	for (b3 = 1; b3 <= ub; b3 *= 3) ;

	int res = 0;
	for (ll i = 1; i <= b2; i *= 2) {
		for (ll j = 1; j <= b3 && i*j <= ub; j *= 3) {
			res++;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int left, right;
	cin >> left >> right;
	cout << solve(right) - solve(left-1) << nl;

	return 0;
}