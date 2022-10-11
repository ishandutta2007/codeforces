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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
}
 
using namespace modop;
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 776;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
pair<ll, ll> v[300005];
ll fact[350005], ifact[350005];
bool toggle[300005];
bool spec[300005];
vector<ll> edges[300005];
vector<ll> specv;
vector<ll> events[300005];
 
ll nck(ll n, ll k) {
	ll dem = (ifact[n - k] * ifact[k]) % mod;
	return (dem * fact[n]) % mod;
}
 
ll dp[45];
ll cnt[45];
 
bool vis[300005];
ll id[300005];
vector<ll> comp;
 
void dfs(int v) {
	vis[v] = 1;
	comp.push_back(v);
	
	for (ll x: edges[v]) {
		if (toggle[x] && !vis[x]) {
			dfs(x);
		}
	}
}
 
void solve_iset() {
	for (ll i = 0; i < 24; i++) cnt[i] = 0;
	
	for (ll x: specv) id[x] = -1;
	for (ll i = 0; i < comp.size(); i++) id[comp[i]] = i;
	
	ll sz = (ll)comp.size();
 
	// cout << comp << endl;
	
	if (sz == 1) {
		cnt[0] = cnt[1] = 1;
		return;
	}
	
	ll cut = (sz + 1) / 2;
	
	ll rem = sz - cut;
	
	ll mask1 = (1 << cut), mask2 = (1 << rem);
	
	ll tot[mask2][22];
	memset(tot, 0, sizeof(tot));
	
	for (ll i = 0; i < mask2; i++) {
		bool bad[22];
		memset(bad, 0, sizeof(bad));
		
		bool pos = 1;
		for (ll j = cut; j < sz; j++) {
			if (i & (1 << (j - cut))) {
				if (bad[j]) {
					// cout << j << " " << comp[j] << endl;
					pos = 0;
					break;
				}
				for (ll x: edges[comp[j]]) {
					if (id[x] != -1) {
						bad[id[x]] = 1;
					}
				}
			}
		}
		
		tot[i][__builtin_popcountll(i)] += pos;
		// if (pos) cout << i << endl;
	}
	
	// sos dp: https://codeforces.com/blog/entry/45223
	for (ll i = 0; i < rem; i++) {
		for (ll mask = 0; mask < mask2; mask++) {
			if (mask & (1 << i)) {
				for (ll j = 0; j < 22; j++) {
					tot[mask][j] += tot[mask ^ (1 << i)][j];
					if (tot[mask][j] >= mod) tot[mask][j] -= mod;
				}
			}
		}
	}
	
	for (ll i = 0; i < mask1; i++) {
		bool bad[22];
		memset(bad, 0, sizeof(bad));
		
		bool pos = 1;
		for (ll j = 0; j < cut; j++) {
			if (i & (1 << j)) {
				if (bad[j]) {
					pos = 0;
					break;
				}
				for (ll x: edges[comp[j]]) {
					if (id[x] != -1) {
						bad[id[x]] = 1;
					}
				}
			}
		}
		
		if (pos) {
			ll rem_mask = 0;
			for (ll j = cut; j < sz; j++) {
				rem_mask += (1 << (j - cut)) * !bad[j];
			}
			
			// cout << i << " " << rem_mask << " " << tot[rem_mask][1] << endl;
			
			ll v = __builtin_popcountll(i);
			for (ll j = 20; j >= 0; j--) {
				cnt[v + j] += tot[rem_mask][j];
				if (cnt[v + j] >= mod) cnt[v + j] -= mod;
			}
		}
	}
}
 
void solve_isets() {
	for (ll x: specv) vis[x] = 0;
	
	for (ll i = 0; i < 43; i++) dp[i] = 0;
	dp[0] = 1;
	
	for (ll x: specv) {
		comp.clear();
		if (toggle[x] && !vis[x]) {
			dfs(x);
			solve_iset();
			
			ll ndp[45];
			for (ll i = 0; i < 43; i++) ndp[i] = 0;
			
			for (ll i = 21; i >= 0; i--) {
				for (ll j = 21; j >= 0; j--) {
					if (i + j < 43) {
						ndp[i + j] = (ndp[i + j] + dp[i] * cnt[j]) % mod;
					}
				}
			}
			
			for (ll i = 0; i < 43; i++) dp[i] = ndp[i];
		}
	}
}
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) events[i].reserve(5);
	
	fact[0] = ifact[0] = fact[1] = ifact[1] = 1;
	for (ll i = 2; i < 300003; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	
	ifact[300001] = minv(fact[300001]);
	for (ll i = 300000; i >= 2; i--) {
		ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
	}
	
	for (ll i = 0; i < n; i++) {
		toggle[i] = 0;
		cin >> v[i];
		id[i] = -1;
	}
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y; 
		--x; --y;
		spec[x] = 1;
		spec[y] = 1;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	for (ll i = 0; i < n; i++) {
		if (spec[i]) {
			id[i] = (ll)specv.size();
			specv.push_back(i);
		}
	}
	
	for (ll i = 0; i < n; i++) {
		events[v[i].f].push_back(i + n);
		events[v[i].s + 1].push_back(i);
	}
	
	solve_isets();
 
	ll ntoggled = 0;
	
	ans = 0;
	for (ll i = 1; i <= n; i++) {
		bool change = 0;
		for (ll x: events[i]) {
			if (x >= n) {
				++ntoggled;
				toggle[x -= n] = 1;
			} else {
				--ntoggled;
				toggle[x] = 0;
			}
			if (spec[x]) change = 1;
		}
		
		if (change) {
			solve_isets();
		}
		
		ll ctog = 0;
		for (ll x: specv) {
			if (toggle[x]) {
				++ctog;
			}
		}
		
		for (ll j = 0; j < 42; j++) {
			ll tot = i - j;
			ll rest = ntoggled - ctog;
			
			if (tot >= 0 && rest >= 0 && rest >= tot) {
				ans = (ans + nck(rest, tot) * dp[j]) % mod;
			}
		}
		
		// cout << ans << endl;
	}
	
	cout << ans << '\n';
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
 
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}