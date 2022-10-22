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

struct Node {
	ll id, dist;
	bool operator < (const Node& o) const {
		return dist > o.dist;
	}
};

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;

	unordered_map<ll,ll> res;
	priority_queue<Node> dijk;
	dijk.push({0,0});
	res[0] = 0;
	while (!dijk.empty() && res.size()<2e6 && clock()<1.789*CLOCKS_PER_SEC) {
		Node cur = dijk.top();
		dijk.pop();
		ll u = cur.id;
		ll v = cur.dist;
		if (u-b >= 0 && !res.count(u-b)) {
			res[u-b] = max(u-b, v);
			dijk.push({u-b, max(u-b,v)});
		}
		if (!res.count(u+a)) {
			res[u+a] = max(u+a, v);
			dijk.push({u+a, max(u+a,v)});
		}
	}

	ll g = __gcd(a,b);
	ll k = (n+1)/g;
	ll ans = (ll)(k+1)*(n+1) - (ll)g*((ll)k*(k+1)/2);
	for (const auto& it : res) {
		if (it.first <= n) {
			ans += max((ll)0, n-it.second+1) - (n-it.first+1);
		}
	}
	cout << ans << nl;

	return 0;
}