// i really hate my compiler

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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

string g[1000005];
const ll dr[4] = {0, 0, -1, 1};
const ll dc[4] = {1, -1, 0, 0};
bool valid(ll r, ll c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	pair<ll, ll> L;
	for (ll i = 0; i < n; i++) {
		cin >> g[i];
		for (ll j = 0; j < m; j++) {
			if (g[i][j] == 'L') L = {i, j};
		}
	}
	
	queue<pair<ll, ll>> q;
	q.push(L);
	
	while (!q.empty()) {
		pair<ll, ll> x = q.front();
		q.pop();
		
		if (g[x.f][x.s] == '+') continue;
		
		if (g[x.f][x.s] == '.') {
			ll cnt = 0;
			for (ll d = 0; d < 4; d++) {
				ll nr = dr[d] + x.f, nc = dc[d] + x.s;
				
				if (valid(nr, nc) && g[nr][nc] == '.') ++cnt;
			}
			
			if (cnt <= 1) g[x.f][x.s] = '+';
		}
		
		if (g[x.f][x.s] != '.') {
			for (ll d = 0; d < 4; d++) {
				ll nr = dr[d] + x.f, nc = dc[d] + x.s;
				
				if (valid(nr, nc) && g[nr][nc] == '.') q.push({nr, nc});
			}
		}
	}
	
	for (ll i = 0; i < n; i++) cout << g[i] << '\n';
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
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}