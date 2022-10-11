#include <bits/stdc++.h>
using namespace std;

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<ll, ll>> edges[55];
vector<ll> cur;
ll cnt[55];
ll dp[55][55];
ll cost[55];
ll par[55];
ll at[55];
ll dist[55];

ll count(ll v, ll p) {
	for (pair<ll, ll> x: edges[v]) if (x.f != p) cnt[v] += count(x.f, v);
	return cnt[v];
}

void dfs(ll v, ll p, ll d) {
	dist[v] = d;
	par[v] = p;
	bool leaf = 1;
	for (pair<ll, ll> x: edges[v]) if (x.f != p) {
		dfs(x.f, v, d + x.s);
		leaf = 0;
	}
	if (leaf) cur.push_back(v);
}

ll rec(ll pos, ll cnt);

ll getv(ll v, ll p, ll cnt, ll diff) {
	memset(at, 0, sizeof(at));
	cur.clear();
	dfs(v, p, 0);
	
	ll ans = 1e18;
	for (ll it = 0; it < cnt; it++) {
		ll wpos = -1, wval = -1;
		for (ll x: cur) {
			cost[x] = dist[x] + rec(x, cnt + diff - (at[x] + 1));
			
			if (cost[x] > wval) {
				wval = cost[x];
				wpos = x;
			}
		}
		++at[wpos];
		ans = min(ans, wval);
	}
	return ans;
}

ll rec(ll pos, ll cnt) {
	if (cnt == 0) return 0;
	if (dp[pos][cnt] != -1) return dp[pos][cnt];
	
	assert(edges[pos].size() == 1);
	ll v = edges[pos][0].s + getv(edges[pos][0].f, pos, cnt, 0);
	return dp[pos][cnt] = v;
}

void solve(int tc = 0) {
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		--x; --y;
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}
	
	ll s;
	cin >> s;
	--s;
	
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> x;
		--x;
		++cnt[x];
	}
	
	count(s, -1);
	
	for (ll i = 0; i <= m; i++) {
		for (ll j = 0; j < n; j++) {
			if (edges[j].size() == 1) {
				rec(j, i);
			}
		}
	}
	
	ll ans = 1e18;
	for (pair<ll, ll> x: edges[s]) ans = min(ans, x.s + getv(x.f, s, cnt[x.f], m - cnt[x.f]));
	cout << ans << '\n';
}

// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}