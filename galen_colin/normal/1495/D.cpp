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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> edges[405];
bool vis[405];
ll dist[405][405];
ll cnt[405][405];
ll pos[405];
bool lev[405];

void bfs(ll v) {
	memset(vis, 0, sizeof(vis));
	
	queue<pair<ll, ll>> q;
	q.push({v, 0});
	
	while (!q.empty()) {
		pair<ll, ll> x = q.front();
		q.pop();
		
		if (vis[x.f]) continue;
		vis[x.f] = 1;
		
		dist[v][x.f] = x.s;
		
		for (ll y: edges[x.f]) {
			if (!vis[y]) q.push({y, x.s + 1});
		}
	}
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	for (ll i = 0; i < n; i++) {
		bfs(i);
	}
	
	memset(cnt, 0, sizeof(cnt));
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll ans = 1;
			
			memset(pos, 0, sizeof(pos));
			memset(lev, 0, sizeof(lev));
			ll lv = dist[i][j];
			
			for (ll k = 0; k < n; k++) {
				for (ll y: edges[k]) {
					if (dist[i][k] == dist[i][y] - 1) {
						if (dist[j][y] - dist[j][k] == 1) ++pos[y];
						else if (dist[j][k] - dist[j][y] == 1 && !lev[dist[i][k]] && dist[j][k] == lv - dist[i][k]) {
							lev[dist[i][k]] = 1;
							pos[k] = -1e9;
						}
					}
				}
			}
			
			for (ll k = 0; k < n; k++) {
				if (pos[k] < 0) pos[k] = 1;
				if (k != j) {
					ans = (ans * pos[k]) % mod;
				}
			}
			
			for (ll k = 0; k < lv; k++) ans *= lev[k];
			
			// cout << "           A " << ans << endl;
			cout << ans << " ";
		}
		cout << '\n';
	}
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
	// freopen("tc2.cpp", "w", stdout);
 		
	cout << setprecision(15) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}