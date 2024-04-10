#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
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
// typedef int ll;
// #pragma warning("int")
 
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
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17598;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

string mat[505];
ll dr[4] = {0, 0, 1, -1};
ll dc[4] = {1, -1, 0, 0};
ll ret[505][505];

bool vis[300005];
ll col[300005];

vector<pair<ll, ll>> edges[300005];

ll id(ll r, ll c) {
	return r * m + c;
}

void edge(ll a, ll b, ll c) {
	edges[a].push_back({b, c});
	edges[b].push_back({a, c});
}

bool dfs(ll v, ll c) {
	if (vis[v]) return 1;
	vis[v] = 1;
	col[v] = c;
	
	for (pair<ll, ll> x: edges[v]) {
		if (vis[x.f]) {
			if ((col[v] ^ col[x.f]) != x.s) {
				return 0;
			}
		} else {
			dfs(x.f, col[v] ^ x.s);
		}
	}
	return 1;
}
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) cin >> mat[i];
	
	bool pos = 1;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] == 'X') {
				ll cnt = 0;
				
				vector<ll> p;
				
				for (ll d = 0; d < 4; d++) {
					ll ni = i + dr[d], nj = j + dc[d];
					if (mat[ni][nj] == '.') {
						++cnt;
						p.push_back(d);
					}
				}
				
				if (cnt % 2 == 1) {
					pos = 0;
					break;
				} else if (cnt == 2) {
					ll a = id(i + dr[p[0]], j + dc[p[0]]);
					ll b = id(i + dr[p[1]], j + dc[p[1]]);
					
					edge(a, b, 1);
				} else if (cnt == 4) {
					edge(id(i - 1, j), id(i + 1, j), 0);
					edge(id(i, j - 1), id(i, j + 1), 0);
					
					edge(id(i - 1, j), id(i, j - 1), 1);
				}
				
				ret[i][j] = 5 * (cnt / 2);
			}
		}
	}
	
	if (!pos) {
		cout << "NO\n";
		return;
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] != 'X') {
				ll v = id(i, j);
				if (!vis[v]) {
					if (!dfs(v, 0)) {
						cout << "NO\n";
						return;
					}
				}
			}
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] != 'X') {
				ll v = id(i, j);
				ret[i][j] = 1 + 3 * col[v];
			}
		}
	}
	
	cout << "YES\n";
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cout << ret[i][j] << " ";
		}
		cout << '\n'; 
	}
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}