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
const ll template_array_size = 1e6 + 1160;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll dist[100005];
bool vis[100005];
vector<ll> edges[100005];

void bfs(ll v) {
	queue<pair<ll, ll>> q;
	
	for (ll i = 0; i < n; i++) {
		vis[i] = 0;
	}
	
	q.push(make_pair(v, 0)); // (v, dist)
	
	while (!q.empty()) {
		pair<ll, ll> x = q.front();
		q.pop();
		
		dist[x.f] = x.s;
		vis[x.f] = 1;
		
		for (ll y: edges[x.f]) {
			if (!vis[y]) {
				q.push(make_pair(y, x.s + 1));
			}
		}
	}
}

void solve(int tc = 0) {	
	ll a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	--a; --b;
	
	for (ll i = 0; i < n; i++) edges[i].clear();
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	int mv = 0;
	
	bfs(0);
	
	for (ll i = 1; i < n; i++) {
		if (dist[i] > dist[mv]) mv = i;
	}
	
	bfs(mv);
	
	ll mx = 0;
	for (ll i = 0; i < n; i++) {
		mx = max(mx, dist[i]);
	}
	
	bool pos = 1;
	if (db <= 2 * da) pos = 0;
	
	bfs(a);
	if (dist[b] <= da) pos = 0;
	
	if (mx <= 2 * da) pos = 0;
	
	// cout << mx << " " << dist[b] << " " << dist[a] << '\n';
	
	cout << (pos ? "Bob" : "Alice") << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowland");
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