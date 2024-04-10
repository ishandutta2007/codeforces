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
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
std::vector<int> topo_sort(std::vector<std::vector<int>> adj) {
	int n = (int)adj.size();
	std::vector<int> in(n);
	std::vector<int> res;
	std::list<int> todo;
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			++in[j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			todo.push_back(i);
		}
	}
	while (!todo.empty()) {
		int x = todo.front();
		todo.pop_front();
		res.push_back(x);
		for (int nxt : adj[x]) {
			if (!(--in[nxt])) {
				todo.push_back(nxt);
			}
		}
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<vector<int>> adj(n), dep(n);
		forn(i, n){
			int k;
			cin >> k;
			forn(j, k){
				int x;
				cin >> x;
				x--;
				adj[x].pb(i);
				dep[i].pb(x);
			}
		}

		vector<int> topo = topo_sort(adj);
		if(topo.size() != n){
			cout<< -1 << "\n";
			continue;
		}
		vector<int> dp(n, 1);
		for(int u: topo){
			bool p = false;
			for(int c: dep[u]){
				if(dp[c] > dp[u]){
					dp[u] = dp[c];
					p = c > u;
				} else if(dp[c] == dp[u]){
					p |= c > u;
				}
			}
			dp[u] += p;
		}

		int ans = 0;
		forn(i, n){
			ckmax(ans, dp[i]);
		}
		cout << ans << "\n";
	}
}