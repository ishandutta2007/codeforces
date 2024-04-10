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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
ll nxt[100005], prv[100005], on[100005], iv[100005];
set<pair<pair<ll, ll>, pair<ll, ll>>> pq;
pair<ll, ll> at[100005];

ll sent = 1e18;

ll isect(ll i, ll j, bool f = 1) {
	ll ii = at[i].s, jj = at[j].s;
	if (i == j) return sent;
	__int128 pi = a[ii], pj = a[jj], ti = c[ii], tj = c[jj];
	
	if (iv[ii] > iv[jj]) pj += m;
	
	__int128 ans = sent;
	
	if (ii < jj) {
		if (ti < tj + 1) {
			pi += (tj + 1 - ti) * b[ii];
			ti = tj + 1;
		}
		
		if (ti == tj + 1) {
			if (pi >= pj) ans = min(ans, ti);
			
			++ti;
			pi += b[ii];
		}
		
		if (ti > tj + 1) {
			pj += ((ti - 1) - tj) * b[jj];
			tj = ti - 1;
		}
		
		// cout << i << " " << j << " " << (ll)ti << " " << (ll)tj << " " << (ll)pi << " " << (ll)pj << endl;
		
		if (pi >= pj) ans = min(ans, ti);
	} else {
		if (ti < tj) {
			pi += (tj - ti) * b[ii];
			ti = tj;
		}
		
		if (ti == tj) {
			if (pi >= pj) ans = min(ans, ti);
			
			++ti;
			pi += b[ii];
		}
		
		if (ti > tj) {
			pj += (ti - tj) * b[jj];
			tj = ti;
		}
		
		if (pi >= pj) ans = min(ans, ti);
	}
	
	if (b[ii] > b[jj]) {
		__int128 sp = b[ii] - b[jj];
		__int128 tv = ti + max(__int128(0), (pj - pi + sp - 1) / sp);
		ans = min(ans, tv);
	}
	
	ll ov = sent;
	if (f) ov = isect(j, i, 0);
	
	// cout << i << " " << j << " " << pair{pair{a[at[i].s], b[at[i].s]}, c[at[i].s]} << " " << 
	// pair{pair{a[at[j].s], b[at[j].s]}, c[at[j].s]} << " " << (ll)ti << " " << 
	// (ll)tj << " " << (ll)pi << " " << (ll)pj << " " << (ll)ans << endl;
	// cout << "ov " << i << " " << j << " " << (ll)ans << " " << ov << endl;
		
	if ((ii < jj && ans <= ov) || (ii > jj && ans < ov)) return ans;
	return sent;
}

void add(ll i) {
	ll val = isect(i, nxt[i]);
	// cout << "add " << i << " " << nxt[i] << " " << pair{pair{a[at[i].s], b[at[i].s]}, c[at[i].s]} << " " << pair{pair{a[at[nxt[i]].s], b[at[nxt[i]].s]}, c[at[nxt[i]].s]} << " " << val << endl;
	if (val != sent) { 
		pq.insert({pair{val, at[i].s}, pair{i, nxt[i]}});
		// cout << "in " << pair{pair{val, at[i].s}, pair{i, nxt[i]}} << endl;
	}
}

void del(ll i, ll t, ll ct) {
	// cout << "del " << i << " " << at[i].s << endl;
	ll lv = prv[i], rv = nxt[i];
	nxt[lv] = rv;
	prv[rv] = lv;
	// cout << at[lv].s << " " << t << endl;
	
	on[i] = 0;
		
	ll ot = isect(lv, rv);
	if (ot == t) {
		del(rv, t, ct + 1);
		return;
	}
	
	a[at[lv].s] += b[at[lv].s] * (t - c[at[lv].s]);
	c[at[lv].s] = t;
	b[at[lv].s] = max(0LL, b[at[lv].s] - ct);
	
	if (lv != rv) {
		add(lv);
		add(prv[lv]);
	}
	// cout << lv << " " << a[lv] << " " << b[lv] << " " << c[lv] << endl;
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	if (n == 1) {
		cout << "1\n1\n";
		return;
	}
		
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		iv[i] = a[i];
		on[i] = 1;
		c[i] = 0;
		
		at[i] = {a[i], i};
	}
	
	sort(at, at + n);
	
	for (ll i = 0; i < n; i++) {
		prv[i] = (i - 1 + n) % n;
		nxt[i] = (i + 1) % n;
		add(i);
		
		// cout << at[i] << endl;
	}
	
	while (!pq.empty()) {
		pair<pair<ll, ll>, pair<ll, ll>> x = *pq.begin();
		pq.erase(pq.begin());
		
		// cout << "x " << x << endl;
		
		if (on[x.s.f] && on[x.s.s] && x.f.f != sent) {
			ll val = isect(x.s.f, x.s.s);
			if (val != x.f.f) {
				if (val != sent) pq.insert({pair{val, at[x.s.f].s}, x.s});
			} else del(x.s.s, val, 1);
		}
	}
	
	vector<ll> ans;
	for (ll i = 0; i < n; i++) if (on[i]) ans.push_back(i);
	
	cout << ans.size() << '\n';
	for (ll x: ans) cout << at[x].s + 1 << " ";
	cout << '\n';
	
	// for (ll i = 0; i < n; i++) cout << on[i] << " ";
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