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


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n, m;
		cin >> n >> m;

		vector<vector<pii>> adj(n);
		vector<pii> q;
		vector<pair<pii, int>> fixed;
		forn(i, n-1){
			int x, y, v;
			cin >> x >> y >> v;
			x--; y--;
			if(v == -1){
				q.pb(mp(x, y));
			} else {
				fixed.pb(mp(mp(x, y), v));
				v = __builtin_popcount(v)%2;
				adj[x].pb(mp(y, v));
				adj[y].pb(mp(x, v));
			}
		}
		forn(i, m){
			int x, y, v;
			cin >> x >> y >> v;
			x--; y--;
			adj[x].pb(mp(y, v));
			adj[y].pb(mp(x, v));

		}

		vector<int> val(n, -1);
		bool works = true;
		function<void(int, int)> dfs = [&](int u, int v){
			assert(val[u] == -1);
			val[u] = v;
			for(pii oth: adj[u]){
				if(val[oth.f] == -1){
					dfs(oth.f, oth.s^v);
				} else {
					if(val[oth.f] != (oth.s^v)) works = false;
				}
			}
		};
		forn(i, n){
			if(val[i] == -1){
				dfs(i, 0);
			}
		}

		if(works){
			cout << "YES" << "\n";
			for(pair<pii, int> qu: fixed){
				cout << qu.f.f+1 << " " << qu.f.s+1 << " " << qu.s << "\n";

			}
			for(pii qu: q){
				cout << qu.f+1 << " " << qu.s+1 << " " << (val[qu.f]^val[qu.s]) << "\n";
			}

		} else {
			cout << "NO" << "\n";

		}
	}
}