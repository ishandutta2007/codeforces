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

const int N = 2e5+1;
int a[N];
unordered_map<ll,int> pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	ll sum = 0;
	pref[sum] = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
		pref[sum] = i;
	}

	ll suf = 0;
	ll ans = 0;
	for (int i=n; i>0; i--) {
		suf += a[i];
		if (pref.count(suf) && pref[suf] < i) {
			ans = suf;
		}
	}

	cout << ans << nl;

	return 0;
}