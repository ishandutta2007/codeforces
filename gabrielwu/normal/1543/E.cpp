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
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		int N = 1 << n;
		vector<vector<int>> adj(N);
		forn(i, n*N/2){
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		vector<bool> vis(N, false);
		vector<int> val(N, 0);
		queue<int> q;
		vis[0] = true;
		forn(i, n){
			val[adj[0][i]] = (1<<i);
			q.push(adj[0][i]);
		}
		while(!q.empty()){
			int x = q.front(); q.pop();
			if(vis[x]) continue;
			vis[x] = true;
			for(int y: adj[x]){
				if(!vis[y]){
					val[y] |= val[x];
					q.push(y);
				}
			}
		}

		// cout << val << "\n";

		vector<int> p(N);
		forn(i, N){
			p[val[i]] = i;
		}

		forn(i, N){
			cout << p[i] << " ";
		}cout << "\n";

		if(__builtin_popcount(n) != 1){
			cout << -1 << "\n";
			continue;
		}

		vector<int> ans(N);
		for(int i=0; i<N; i++){
			int c = 0;
			forn(j, n){
				if(i & (1 << j)){
					c ^= j;
				}
			}
			ans[p[i]] = c;
		}

		forn(i, N){
			cout << ans[i] << " ";
		}cout << "\n";
	}
}