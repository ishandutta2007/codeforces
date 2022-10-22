#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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

struct Point {
	int i, x, t;
	bool operator < (const Point& o) const {
		if (x != o.x) return x < o.x;
		else return t < o.t;
	}
};

const int N = 2e5+1;
int dp[N], cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<Point> p;
	For(i,n) {
		int a, b;
		cin >> a >> b;
		p.push_back({i,a,-1});
		p.push_back({i,b,1});
	}
	sort(p.begin(), p.end());

	map<int,ll> cur;
	cur[0] = 1;
	for (const Point& it : p) {
		//cerr << "@ " << it.x << " : " << it.i << ',' << it.t << nl;
		if (it.t == -1) {
			int v = dp[it.i] - it.x;
			cur[v] = (cur[v] + cnt[it.i]) % MOD;
			//cerr << " set " << v << " -> " << cur[v] << nl;
		} else {
			auto jt = cur.begin();
			dp[it.i] = jt->first + it.x;
			cnt[it.i] = jt->second;
			//cerr << " update w/ " << jt->first << ',' << jt->second << nl;
			//cerr << "  -> dp " << dp[it.i] << "  cnt " << cnt[it.i] << nl;
		}
	}

	map<int,ll> minv;
	Down(i,2*n) {
		if (p[i].t == 1) break;
		minv[dp[p[i].i]] += cnt[p[i].i];
	}
	cout << minv.begin()->second % MOD << nl;

	return 0;
}