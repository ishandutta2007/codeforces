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
// const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14342;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll dist[605][605];
ll conn[605][605];
ll req[605][605];
ll pos[605][605];
bool vis[605];

void solve(int tc = 0) {	
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			dist[i][j] = 1e15;
			conn[i][j] = -1;
			req[i][j] = -1;
			pos[i][j] = 0;
		}
		dist[i][i] = 0;
	}
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y >> z;
		--x; --y;
		dist[x][y] = dist[y][x] = z;
		conn[x][y] = conn[y][x] = z;
	}
	
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	cin >> q;
	
	for (ll i = 0; i < q; i++) {
		cin >> x >> y >> z;
		--x; --y;
		
		req[x][y] = req[y][x] = z;
	}
	
	for (ll i = 0; i < n; i++) {
		memset(vis, 0, sizeof(vis));
		for (ll j = 0; j < n; j++) {
			if (req[i][j] == -1) a[j] = -1e15;
			else {
				a[j] = req[i][j];
			}
		}
		
		for (ll it = 0; it < n; it++) {
			ll mv = -1;
			for (ll j = 0; j < n; j++) {
				if (!vis[j]) {
					if (mv == -1 || a[j] > a[mv]) {
						mv = j;
					}
				}
			}
			
			if (mv == -1) break;
			
			vis[mv] = 1;
			
			for (ll j = 0; j < n; j++) {
				if (conn[mv][j] != -1) {
					a[j] = max(a[j], a[mv] - conn[mv][j]);
				}
			}
		}
		
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				if (conn[j][k] != -1) {
					ll d = a[k] - dist[i][j] - conn[j][k];
					if (d >= 0) pos[j][k] = 1;
				}
			}
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (pos[i][j]) ++ans;
		}
	}
	
	cout << ans / 2 << '\n';
}

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