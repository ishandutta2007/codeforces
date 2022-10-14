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
		int n;
		cin >> n;
		vector<vector<int>> adj1(n), adj2(n);
		forn(i, n-1){
			int x;
			cin >> x;
			adj1[x-1].pb(i+1);
		}
		forn(i, n-1){
			int x;
			cin >> x;
			adj2[x-1].pb(i+1);
		}

		vector<int> l(n), r(n);
		int time = 0;
		function<void(int)> tour = [&](int u){
			l[u] = time++;
			for(int oth: adj2[u]){
				tour(oth);
			}
			r[u] = time++;
		};

		tour(0);
		set<pii> s;
		int ans = 0;
		function<void(int)> dfs = [&](int u){
			auto f = s.upper_bound(mp(l[u], u));
			pii p{-1,-1};
			if(f == s.end() || f->f >= r[u]){
				auto g = s.emplace(l[u], u).f;
				if(g != s.begin() && r[(--g)->s] > r[u]){
					p = *g;
					s.erase(g);
				}
			}

			ckmax(ans, (int) s.size());
			for(int oth: adj1[u]){
				dfs(oth);
			}

			if(p.f >= 0) s.insert(p);
			s.erase(mp(l[u], u));
		};

		dfs(0);
		cout << ans << "\n";
	}
}