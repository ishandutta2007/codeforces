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
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> ops;

void kill_eleft(ll l, ll r) {
	for (ll j = l; j <= r; j += 2) {
		ops.push_back(j);
	}
}

void kill_eright(ll l, ll r) {
	for (ll j = r; j >= l; j -= 2) {
		ops.push_back(j);
	}
}

void drag(ll s, ll t) {
	for (ll j = s; j < t; j += 2) {
		ops.push_back(j + 1);
	}
}
 
void solve(int tc = 0) {
	ops.clear();
	
	cin >> n;
	
	ll ct = 0;
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		ct += a[i];
	}
	
	if (ct % 2 == 1) {
		cout << "NO\n";
		return;
	}
	
	ll last = a[0], cnt = 1;
	vector<ll> g;
	vector<pair<ll, ll>> r;
	
	for (ll i = 1; i < n; i++) {
		if (a[i] == last) ++cnt;
		else {
			g.push_back(cnt);
			r.push_back({i - cnt, i - 1});
			cnt = 1;
			last = a[i];
		}
	}
	g.push_back(cnt);
	r.push_back({n - cnt, n - 1});
		
	ll v = a[0];
	for (ll i = !v; i < g.size(); i += 2) {
		if (g[i] % 2 == 0) {
			if (i > 0) {
				kill_eleft(r[i].f, r[i].s);
			} else if (i + 1 < g.size()) {
				kill_eright(r[i].f, r[i].s);
			} else {
				cout << "NO\n";
				return;
			}
		} else {
			ll nxt = i + 2;
			while (nxt < g.size() && g[nxt] % 2 == 0) nxt += 2;
						
			assert(nxt < g.size());
			
			ll st = r[i].f;
			
			for (ll j = i; j < nxt; j += 2) {
				if (g[j + 1] % 2 == 0) {
					drag(r[j].s, r[j + 1].s);
				} else {
					drag(r[j].s, r[j + 1].s - 1);
					ops.push_back(r[j + 1].s);
					
					ll en = r[j + 1].s - 2;
					
					if (st <= en) {
						kill_eright(st, en);
					}
					
					st = r[j + 1].s + 2;
				}
			}
			
			if (st <= r[nxt].s) {
				if (st > 0) kill_eleft(st, r[nxt].s);
				else if (r[nxt].s + 1 < n) kill_eright(st, r[nxt].s);
				else {
					cout << "NO\n";
					return;
				}
			}
			
			i = nxt;
		}
	}
	
	cout << "YES\n" << ops.size() << '\n';
	for (ll x: ops) cout << x << " ";
	cout << '\n';
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