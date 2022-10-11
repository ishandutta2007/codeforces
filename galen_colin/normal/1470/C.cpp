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
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll v[100005][2];
map<ll, ll> maxd;
ll turns = 0;

void upd(bool comp) {
	ll lv = min(n - 1, turns + 2);
	ll rv = max(lv + 1, (n - 1) - (turns + 2));
	
	ll p = turns & 1;
	
	for (ll i = 0; i <= lv; i++) {
		ll lp = (i == 0 ? n - 1 : i - 1);
		ll rp = (i == n - 1 ? 0 : i + 1);
		
		v[i][p] = (v[rp][!p] >> 1) + ((v[lp][!p] + 1) >> 1);
	}
	for (ll i = rv; i < n; i++) {
		ll lp = (i == 0 ? n - 1 : i - 1);
		ll rp = (i == n - 1 ? 0 : i + 1);
		
		v[i][p] = (v[rp][!p] >> 1) + ((v[lp][!p] + 1) >> 1);
	}
	
	v[n - 1][p] -= v[0][!p] >> 1;
	v[1][p] += v[0][!p] >> 1;
	
	if (comp) {
		maxd.clear();
		for (ll i = 0; i <= lv; i++) {
			maxd[v[i][p]] = max(maxd[v[i][p]], i);
		}
		for (ll i = rv; i < n; i++) {
			maxd[v[i][p]] = max(maxd[v[i][p]], i);
		}
	}
	
	++turns;
}

ll qq = 0;

ll query(ll x) {
	assert(qq <= 1000);
	++qq;
	cout << "? " << x + 1 << endl;
	ll y; cin >> y;
	return y;
}

void solve(int tc = 0) {
	cin >> n >> k;
	
	ll b = sqrtl(n);
	
	for (ll i = 0; i < 2; i++) {
		for (ll j = 0; j < n; j++) {
			v[j][i] = k;
		}
	}
	
	for (ll i = 0; i <= b + 5; i++) {
		query(0);
		upd(1);
	}
	
	ll p = 0;
	ll bestp = -1, bestv = n;
	for (ll i = 0; i <= b + 5; i++) {
		ll v = query(p);
		ll x = maxd[v];
		
		if (x < bestv) {
			bestv = x;
			bestp = p;
		}
		
		p = (p + b) % n;
		upd(1);
	}
	
	for (ll i = 0; i < n; i++) {
		ll x = query(bestp);
		
		if (x == v[0][!(turns & 1)]) break;
		
		--bestp;
		if (bestp < 0) bestp += n;
		
		upd(0);
	}
	
	cout << "! " << bestp + 1 << endl;
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
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