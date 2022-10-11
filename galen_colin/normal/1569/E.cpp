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

map<ll, vector<ll>> pos[2][2]; // (side, whether this guy wins finals)
ll pows[105];

void gen(ll p) {
	ll m = n / 2;
	
	ll st = p * m + 1;
	
	for (ll mask = 0; mask < (1 << (m - 1)); mask++) {
		vector<ll> place(m);
		
		vector<ll> spot(m);
		iota(spot.begin(), spot.end(), st);
		
		ll pt = 0;
		ll h = 0;
		
		for (ll sz = m; sz > 1; sz /= 2) {
			for (ll i = 0; i < sz; i += 2) {
				ll res = (mask >> pt) & 1;
				++pt;
				
				if (res) { // first wins
					place[spot[i + 1] - st] = sz + 1;
					h = (h + spot[i + 1] * pows[sz + 1]) % mod;
					spot[i / 2] = spot[i];
				} else {
					place[spot[i] - st] = sz + 1;
					h = (h + spot[i] * pows[sz + 1]) % mod;
					spot[i / 2] = spot[i + 1];
				}
			}
		}
		
		// winner at spot[0]
		
		{ // wins finals
			vector<ll> nplace = place;
			ll nh = h;
			
			nplace[spot[0] - st] = 1;
			nh = (nh + spot[0] * pows[1]) % mod;
			
			pos[p][1][nh] = nplace;
		}
		
		{ // doesn't win finals
			vector<ll> nplace = place;
			ll nh = h;
			
			nplace[spot[0] - st] = 2;
			nh = (nh + spot[0] * pows[2]) % mod;
			
			pos[p][0][nh] = nplace;
		}
	}
}

void solve(int tc = 0) {
	cin >> k >> x >> y;
	
	ll r = 1;
	pows[0] = 1;
	
	for (ll i = 1; i <= 100; i++) {
		r = (r * x) % mod;
		pows[i] = r;
	}
	
	n = (1 << k);
	
	gen(0);
	gen(1);
	
	for (ll w = 0; w < 2; w++) { // does first guy win finals
		for (pair<ll, vector<ll>> x: pos[0][w]) {
			ll targ = (y - x.f + mod) % mod;
			
			if (pos[1][!w].find(targ) != pos[1][!w].end()) {
				for (ll z: x.s) cout << z << " ";
				for (ll z: pos[1][!w][targ]) cout << z << " ";
				cout << '\n';
				return;
			}
		}
	}
	
	cout << -1 << '\n';
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
 
	
	
	// handling mod in general, variable names
		
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