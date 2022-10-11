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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 9097;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> edges[300005];
ll indegree[300005];
vector<ll> toposort;
ll dp[300005];

void solve(int tc = 0) {
	cin >> n >> m >> s;
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		++indegree[y];
	}
	
	queue<ll> q;
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		++cnt;
		ll x = q.front();
		q.pop();
		toposort.push_back(x);
		
		for (ll y: edges[x]) {
			--indegree[y];
			if (indegree[y] == 0) {
				q.push(y);
			}
		}
	}
	
	if (cnt < n) {
		cout << -1 << '\n';
		return;
	}
	
	ll ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		memset(dp, 0, sizeof(dp));
		
		for (ll x: toposort) {
			if (s[x] == c) ++dp[x];
			for (ll y: edges[x]) {
				dp[y] = max(dp[y], dp[x]);
			}
			ans = max(ans, dp[x]);
		}
	}
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