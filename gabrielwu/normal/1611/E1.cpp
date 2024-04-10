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
		int n, k;
		cin >> n >> k;

		vector<bool> v(n), b(n);
		forn(i, k){
			int x;
			cin >> x;
			v[x-1] = true;
		}

		vector<vector<int>> adj(n);
		forn(i, n-1){
			int x, y;
			cin >> x >> y;
			x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		vector<int> s;
		function<void(int, int)> dfs1 = [&](int u, int par){
			s.pb(u);
			if(v[u]){
				int h = s[s.size()/2];
				b[h] = true;
			}
			for(int oth: adj[u]){
				if(oth != par){
					dfs1(oth, u);
				}
			}
			s.pop_back();
		};

		bool works = false;
		function<void(int, int)> dfs2 = [&](int u, int par){
			if(b[u]){
				return;
			}
			if(adj[u].size() == 1 && par != u){
				works = true;
			}
			for(int oth: adj[u]){
				if(oth != par){
					dfs2(oth, u);
				}
			}
		};

		dfs1(0,0);
		dfs2(0,0);

		cout << (works ? "YES\n" : "NO\n");
	}
}