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

ll seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
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
const ll template_array_size = 1e6 + 9097;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<ll, ll>> edges[1000005];
bool vis[1000005];
ll touched[1000005];
ll best[1000005];
ll dist[1000005];
ll at[10][1000005];
ll sz[10];

ll cur;

void add(ll x, ll y, ll z) {
	ll targ = y;
	while (z >= 10) {
		edges[cur].push_back({targ, z % 10});
		targ = cur++;
		z /= 10;
	}
	edges[x].push_back({targ, z});
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	cur = n;
	
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		--x; --y;
		add(x, y, i + 1);
		add(y, x, i + 1);
	}
	
	queue<pair<vector<ll>, ll>> q;
	q.push(make_pair(vector<ll>(1, 0), 0));
	
	ll cur_time = 0;
	while (!q.empty()) {
		++cur_time;
		
		pair<vector<ll>, ll> x = q.front();
		q.pop();
		
		for (ll y: x.f) {
			if (vis[y]) continue;
			dist[y] = x.s;
			for (pair<ll, ll> z: edges[y]) {
				if (vis[z.f]) continue;
				if (touched[z.f] == cur_time) {
					best[z.f] = min(best[z.f], z.s);
				} else {
					touched[z.f] = cur_time;
					best[z.f] = z.s;
				}
			}
		}
		
		++cur_time;
		
		for (ll y: x.f) {
			if (vis[y]) continue;
			vis[y] = 1;
			for (pair<ll, ll> z: edges[y]) {
				if (touched[z.f] == cur_time - 1) {
					at[best[z.f]][sz[best[z.f]]++] = z.f;
					touched[z.f] = cur_time;
				}
			}
		}
		
		for (ll i = 0; i < 10; i++) {
			if (sz[i]) {
				vector<ll> h(sz[i]);
				for (ll j = 0; j < sz[i]; j++) h[j] = at[i][j];
				q.push(make_pair(h, (x.s * 10 + i) % mod));
			}
			sz[i] = 0;
		}
	}
	
	for (ll i = 1; i < n; i++) cout << dist[i] << '\n';
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
		// usaco("dining");
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