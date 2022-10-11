#include <bits/stdc++.h>
using namespace std;
 
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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
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
const ll template_array_size = 1e6 + 8061;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll hc(char c) { // _ -> 0, [a-z] -> [1-26]
	if (c == '_') return 0;
	return c - 'a' + 1;
}

ll ghash(string s) {
	ll tot = 0, cur = 1;
	for (ll i = 0; i < s.length(); i++) {
		tot += cur * hc(s[i]);
		cur *= 27;
	}
	return tot;
}

vector<ll> edges[1000005];
vector<ll> at[1000005];
ll id[1000005];
bool vis[1000005];
string st[100005];

void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	ll pk = (1 << k);
	memset(id, 0, sizeof(id));
	memset(vis, 0, sizeof(vis));
	
	for (ll i = 0; i < n; i++) {
		cin >> st[i];
		at[ghash(st[i])].push_back(i + 1);
	}
	
	for (ll i = 0; i < m; i++) {
		cin >> s >> x;
		
		ll cand[pk];
		for (ll j = 0; j < pk; j++) {
			string t = s;
			for (ll p = 0; p < k; p++) {
				if (j & (1 << p)) t[p] = '_';
			}
			cand[j] = ghash(t);
		}
		
		ll sh = ghash(st[x - 1]);
		
		ll match = -1;
		for (ll i = 0; i < pk; i++) {
			if (cand[i] == sh) match = cand[i];
		}
		if (match == -1) {
			cout << "NO\n";
			return;
		}
		for (ll i = 0; i < pk; i++) {
			if (cand[i] != sh) {
				edges[sh].push_back(cand[i]);
				++id[cand[i]];
			}
		}
	}
	
	vector<ll> ans;
	queue<ll> q;
	
	ll mx = 1;
	for (ll i = 0; i < k; i++) mx *= 27;
	
	for (ll i = 0; i < mx; i++) {
		if (id[i] == 0) {
			q.push(i);
		}
	}
	
	ll tp = 0;
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		
		if (vis[x]) continue;
		vis[x] = 1;
		
		++tp;
		for (ll y: at[x]) {
			ans.push_back(y);
		}
		
		for (ll y: edges[x]) {
			if (--id[y] == 0) {
				q.push(y);
			}
		}
	}
	
	if (tp != mx) {
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	for (ll x: ans) cout << x << " ";
	cout << '\n';
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
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}