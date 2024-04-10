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

	ll n, k, s;
	cin >> n >> k >> s;

	if (k*(n-1) < s || k > s) {
		cout << "NO" << nl;
	}
	else {
		cout << "YES" << nl;
		ll v = s/k;
		ll o = s - k*v;
		ll cur = 1;
		ll dir = 1;
		for (int i = 0; i < k; i++) {
			cur += dir*v;
			if (o) {
				cur += dir;
				o--;
			}
			dir = -dir;
			cout << cur << " ";
		}
		cout << nl;
	}

	return 0;
}