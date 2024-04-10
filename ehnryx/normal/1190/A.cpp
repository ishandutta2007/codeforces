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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	ll n, m, k;
	cin >> n >> m >> k;

	set<ll> cur;
	For(i,m) {
		ll v;
		cin >> v;
		cur.insert(v-1);
	}
	cur.insert(3*n+1);

	ll ans = 0;
	ll off = 0;
	while (*cur.begin() != 3*n+1) {
		ans++;
		auto s = cur.begin();
		ll page = ((*s)-off)/k;
		ll t = *cur.lower_bound((page+1)*k + off);
		for (auto it = s; *it != t; it = cur.erase(it)) {
			off++;
		}
	}
	assert(off == m);
	cout << ans << nl;

	return 0;
}