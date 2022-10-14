#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<ll> l(n), r(n);
		forn(i, n-1) {
			int x; cin >> x;
			adj[x-1].pb(i+1);
		}

		forn(i, n) cin >> l[i] >> r[i];

		int ans = 0;
		function<ll(int)> dfs = [&](int u) {
			if(adj[u].size() == 0) {
				ans++; //leaf
				return r[u];
			}
			vector<ll> c;
			for(int oth: adj[u]) {
				c.pb(dfs(oth));
			}

			ll sm = 0;
			for(ll x: c) sm += x;
			if(r[u] <= sm) {
				return r[u];
			} else if(l[u] <= sm) {
				return sm;
			} else {
				ans++;
				return r[u];
			}
		};

		dfs(0);
		cout << ans << "\n";


	}
}