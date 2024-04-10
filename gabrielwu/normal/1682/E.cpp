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
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       // http://xorshift.di.unimi.it/splitmix64.c
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(pll _x) const {
       static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
       uint64_t x = _x.f * MOD + _x.s;
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	forn(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<vector<pii>> adj(n);
	vector<pii> swaps(m);
	forn(i, m) {
		int x, y; cin >> x >> y; x--; y--;
		adj[x].pb({y, i}); adj[y].pb({x, i});
		swaps[i] = {x, y};
	}

	vector<int> top(n, -1);
	unordered_map<pii, int, custom_hash> want;	//(a,b) -> c means when p[a] == b, good for c-1
	vector<int> ready;
	vector<int> waiting(n, 2);

	function<pair<int,int>(int, int)> dfs = [&](int u, int par) {

		unordered_map<int,int> need;
		need[u]++;
		need[p[u]]--;
		for(pii oth: adj[u]) {
			if(oth.f == par) continue;
			top[oth.f] = oth.s;
			pii x = dfs(oth.f, u);
			need[x.f]++;
			need[x.s]--;
		}
		if(par != -1) {
			int a, b;
			for(pii x: need) {
				if(x.s == 1) {
					a = x.f;
				} else if(x.s == -1) {
					b = x.f;
				}
			}
			want[mp(par, a)] = top[u]+1;
			want[mp(u, b)] = top[u]+1;
			return mp(a, b);
		}
		return mp(0,0);

	};

	forn(i, n) {
		if(top[i] == -1) dfs(i, -1);
	}

	forn(i, n) {
		int x = want[mp(i, p[i])] - 1;
		if(x >= 0) {
			waiting[x]--;
			if(waiting[x] == 0) {
				ready.pb(x);
			}
		}
	}

	vector<int> ans;
	while(ready.size()) {
		int x = ready.back(); ready.pop_back();
		ans.pb(x);
		swap(p[swaps[x].f], p[swaps[x].s]);

		int y = want[mp(swaps[x].f, p[swaps[x].f])] - 1;
		if(y >= 0) {
			waiting[y]--;
			if(waiting[y] == 0) {
				ready.pb(y);
			}
		}
		y = want[mp(swaps[x].s, p[swaps[x].s])] - 1;
		if(y >= 0) {
			waiting[y]--;
			if(waiting[y] == 0) {
				ready.pb(y);
			}
		}
	}

	assert(ans.size() == m);
	forn(i, m) {
		cout << ans[i]+1 << " ";
	}
	cout << "\n";
}