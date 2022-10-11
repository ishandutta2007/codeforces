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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<pair<ll, ll>, pair<ll, ll>>> ops;
ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {1, -1, 0, 0};

pair<ll, ll> loc[55], dest[55];
pair<pair<ll, ll>, ll> dup[55];

bool valid(ll r, ll c) {
	return r >= 1 && r <= n && c >= 1 && c <= n;
}

void op(ll ax, ll ay, ll bx, ll by) {
	pair<ll, ll> c = {ax, ay}, d = {bx, by};
	ops.push_back({c, d});
}

void move(pair<ll, ll> a, pair<ll, ll> b) {
	op(a.f, a.s, b.f, b.s);
}

void shift(ll ind, ll dr, ll dc) {
	pair<ll, ll> x = {loc[ind].f + dr, loc[ind].s + dc};
	move(loc[ind], x);
	loc[ind] = x;
}

void bump(ll ind, ll dr, ll dc) {
	vector<ll> vals(1, ind);
	
	while (1) {
		bool touch = 0;
		pair<ll, ll> x = {loc[ind].f + dr, loc[ind].s + dc};
		for (ll j = 0; j < m; j++) {
			if (loc[j] == x) {
				touch = 1;
				vals.push_back(j);
				ind = j;
				break;
			}
		}
		if (!touch) break;
	}
	
	while (vals.size()) {
		ind = vals.back();
		pair<ll, ll> x = {loc[ind].f + dr, loc[ind].s + dc};
		move(loc[ind], x);
		loc[ind] = x;
		vals.pop_back();
	}
}

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.f - b.f) + abs(a.s - b.s);
}

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
	if (a.f.s == b.f.s) return a.f.f > b.f.f;
	return a.f.s < b.f.s;
}

void solve(int tc = 0) {
	cin >> n >> m;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	
	for (ll i = 0; i < m; i++) cin >> loc[i];
	for (ll i = 0; i < m; i++) cin >> dest[i];
	
	for (ll i = 1; i <= m; i++) {
		pair<ll, ll> targ = {1e9, 1e9};
		ll ind = -1;
		pair<ll, ll> req = {1, i};
		
		for (ll j = 0; j < m; j++) {
			if (loc[j].f != 1 || loc[j].s >= i) {
				if (dist(loc[j], req) < dist(targ, req)) {
					targ = loc[j];
					ind = j;
				}
			}
		}
		
		while (dist(targ, req) > 0) {
			ll d = dist(targ, req);
			
			for (ll dv = 0; dv < 4; dv++) {
				ll nr = targ.f + dr[dv], nc = targ.s + dc[dv];
				if (!valid(nr, nc)) continue;
				pair<ll, ll> nloc = {nr, nc};
				
				bool collide = 0;
				for (ll j = 0; j < m; j++) {
					if (loc[j] == nloc) collide = 1;
				}
				if (collide) continue;
				
				if (dist(nloc, req) >= d) continue;
				
				move(loc[ind], nloc);
				targ = loc[ind] = nloc;
				break;
			}
		}
	}
	
	for (ll i = 0; i < m; i++) dup[i] = {dest[i], i};
	sort(dup, dup + m, cmp);
	
	for (ll i = 0; i < m; i++) {
		ll pos = loc[dup[i].s].s;
		ll iv = dup[i].s;
		for (ll j = pos; j > i + 1; j--) {
			ll ind = -1;
			for (ll k = 0; k < m; k++) {
				if (loc[k].s == j - 1) ind = k;
			}
			
			shift(ind, 1, 0);
			shift(iv, 0, -1);
			shift(ind, 0, 1);
			shift(ind, -1, 0);
		}
	}
	
	for (ll i = 0; i < m; i++) {
		ll iv = dup[i].s;
		
		while (loc[iv].f < dest[iv].f) shift(iv, 1, 0);
	}
	
	for (ll i = 0; i < m; i++) {
		ll iv = dup[i].s;
		
		while (loc[iv].s < dest[iv].s) bump(iv, 0, 1);
		while (loc[iv].s > dest[iv].s) bump(iv, 0, -1);
	}
	
	// for (ll i = 0; i < m; i++) cout << loc[i] << " " << dest[i] << endl;
	
	cout << ops.size() << '\n';
	for (pair<pair<ll, ll>, pair<ll, ll>> x: ops) cout << x.f.f << " " << x.f.s << " " << x.s.f << " " << x.s.s << '\n';
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
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}