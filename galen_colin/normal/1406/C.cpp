#include <bits/stdc++.h>
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<ll> centroids;
vector<ll> edges[100005];
vector<ll> child[100005];

ll smallest_size;

ll dfs(ll v, ll p) {
	ll sz = 1;
	
	ll worst = 0;
	
	for (ll x: edges[v]) {
		if (x != p) {
			ll rem = dfs(x, v);
			worst = max(worst, rem);
			sz += rem;
			child[v].push_back(x);
		}
	}
	
	ll rem_sz = n - sz;
		
	ll big = max(worst, rem_sz);
	if (big < smallest_size) {
		smallest_size = big;
		centroids.clear();
		centroids.push_back(v);
	} else if (big == smallest_size) {
		centroids.push_back(v);
	}
	
	// cout << "V " << v << " " << sz << " " << worst << " " << big << " " << '\n';
	
	return sz;
}

void solve(int tc = 0) {
	centroids.clear();	
	
	cin >> n;
	
	smallest_size = n;
	
	for (ll i = 0; i < n; i++) {
		edges[i].clear();
		child[i].clear();
	}
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	dfs(0, -1);
			
	if (centroids.size() == 1) {
		cout << edges[0][0] + 1 << " " << 1 << '\n';
		cout << edges[0][0] + 1 << " " << 1 << '\n';
	} else {				
		cout << child[centroids[0]][0] + 1 << " " << centroids[0] + 1 << '\n';
		cout << child[centroids[0]][0] + 1 << " " << centroids[1] + 1 << '\n';
	}
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}