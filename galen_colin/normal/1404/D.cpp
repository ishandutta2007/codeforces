#include "bits/stdc++.h"
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
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> at[500005];
vector<ll> loc[500005];
bool vis[500005];
ll rev[1000005];
vector<ll> ans;

void solve(int tc = 0) {
	cin >> n;
	
	if (n % 2 == 0) {
		cout << "First" << endl;
		for (ll i = 0; i < 2 * n; i++) cout << (i % n) + 1 << " ";
		cout << endl;
		
		cin >> x;
		assert(x == 0);
		return;
	} else {
		cout << "Second" << endl;
		
		for (ll i = 0; i < 2 * n; i++) {
			cin >> a[i];
			--a[i];
			at[a[i]].push_back(i + 1);
			loc[(i + 1) % n].push_back(a[i]);
		}
		
		for (ll i = 0; i < n; i++) {
			rev[at[i][0]] = at[i][1];
			rev[at[i][1]] = at[i][0];
		}
		
		for (ll i = 0; i < n; i++) {
			ll j = i, v = -1;
			if (!vis[at[i][0] % n]) v = at[i][0] % n;
			else if (!vis[at[i][1] % n]) v = at[i][1] % n;
			else continue;
			while (1) {
				ll t = 0;
				if (vis[at[j][0] % n] && vis[at[j][1] % n]) break;
				if (vis[v]) break;
				if (at[j][0] % n == v) t = 0;
				else if (at[j][1] % n == v) t = 1;
				else break;
				
				vis[v] = 1;
				ans.push_back(at[j][t]);
				
				if (!vis[at[j][!t] % n]) {
					v = at[j][!t] % n;
					j = (loc[at[j][!t] % n][0] == j ? loc[at[j][!t] % n][1] : loc[at[j][!t] % n][0]);
				} else break;
			}
		}
		
		ll r = 0;
		for (ll x: ans) r = (r + x) % (2 * n);
		
		if (r != 0) {
			for (ll i = 0; i < ans.size(); i++) {
				ans[i] = rev[ans[i]];
			}
		}
		
		for (ll x: ans) cout << x << " ";
		cout << endl;
		
		cin >> x;
		assert(x == 0);
	}
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
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}