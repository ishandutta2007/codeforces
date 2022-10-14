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
		forn(i, n-1) {
			int x, y; cin >> x >> y;
			x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		if(n == 1) {
			cout << 0 << "\n";
			continue;
		}
		if(n == 2) {
			cout << 1 << "\n";
			continue;
		}

		int start = -1;

		function<int(int, int)> dfs1 = [&](int u, int par) {
			vector<int> c;
			for(int oth: adj[u]) {
				if(oth != par) {
					int x = dfs1(oth, u);
					if(x != -1) {
						c.pb(x);
					}
				}
			}

			if(c.size() > 1) {
				if(start == -1) start = c[0];
			}

			if(par == -1) return 0;

			if(adj[u].size() == 1) {	//leaf
				return u;
			} else if(adj[u].size() == 2) {	//joint
				if(c.size() == 1) return c[0];
			}
			return -1;
		};

		forn(i, n) {
			if(adj[i].size() > 1) {
				dfs1(i, -1);
				break;
			}
		}
		assert(start != -1);

		// cout << start << "\n";
		function<int(int, int)> dfs2 = [&](int u, int par) {
			if(par != -1 && adj[u].size() == 1) {
				// leaf
				return 0;
			}

			vector<int> c;
			int oc = 0;
			for(int oth: adj[u]) {
				if(oth != par) {
					c.pb(dfs2(oth, u));
					if(c.back() == 0) oc++;
				}
			}

			int ans = 0;
			for(int x: c) ans += x;
			if(oc > 0) ans += oc-1;

			return ans;
		};

		cout << dfs2(start, -1) + 1 << "\n";

	}
}