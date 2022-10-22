#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	map<int,vector<int>> p;
	For(i,n) {
		int x, y;
		cin >> x >> y;
		p[y].push_back(x);
	}

	ll ans = 0;
	ordered_set cur;
	for (auto it = p.rbegin(); it != p.rend(); it++) {
		auto& line = it->second;
		line.push_back(-1);
		line.push_back(INF);
		sort(line.begin(), line.end());
		int m = line.size();

		//cerr << "do line at " << it->first << nl;
		ll sqr = 0;
		ll sum = 0;
		For(i,m-1) {
			ll val = cur.order_of_key(line[i+1]) - cur.order_of_key(line[i]+1) + 1;
			sum += val;
			sqr += val*val;
		}
		FOR(i,1,m-2) {
			cur.insert(line[i]);
		}

		//cerr << "sum: " << sum << nl;
		//cerr << "sqr: " << sqr << nl;
		ans += (sum*sum - sqr)/2;
	}

	cout << ans << nl;

	return 0;
}