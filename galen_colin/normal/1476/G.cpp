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

const ll C = 2500;
vector<pair<ll, pair<ll, ll>>> upd;
vector<pair<ll, ll>> rev;
vector<pair<pair<ll, ll>, pair<ll, ll>>> que;

bool comp(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) {
	if (a.s.f / C == b.s.f / C) {
		if (a.s.s / C == b.s.s / C) {
			return a.f.f < b.f.f;
		}
		return a.s.s / C < b.s.s / C;
	}
	return a.s.f / C < b.s.f / C;
}

ll freq[100005];
ll ffreq[100005];
int cand[30000005], cp = 0;
ll vis[100005];
ll res[100005];

void ins(ll i) {
	--ffreq[freq[a[i]]];
	++freq[a[i]];
	++ffreq[freq[a[i]]];
	cand[cp++] = freq[a[i]];
}

void del(ll i) {
	--ffreq[freq[a[i]]];
	--freq[a[i]];
	++ffreq[freq[a[i]]];
	cand[cp++] = freq[a[i]];
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	memset(freq, 0, sizeof(freq));
	memset(ffreq, 0, sizeof(ffreq));
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	for (ll i = 0; i < m; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> k;
			--l; --r;
			que.push_back(make_pair(make_pair(i, k), make_pair(l, r)));
		} else {
			cin >> l >> x;
			--l;
			upd.push_back(make_pair(i, make_pair(l, x)));
			rev.push_back(make_pair(b[l], x));
			b[l] = x;
		}
	}
	
	sort(que.begin(), que.end(), comp);
	memset(vis, 0, sizeof(vis));
	
	ll lv = 0, rv = n - 1, pt = 0, us = upd.size();
	for (ll i = 0; i < n; i++) ins(i);
	for (ll i = 0; i < que.size(); i++) {
		pair<ll, ll> loc = que[i].s;
		while (lv < loc.f) {
			del(lv);
			++lv;
		}
		while (lv > loc.f) {
			--lv;
			ins(lv);
		}
		while (rv > loc.s) {
			del(rv);
			--rv;
		}
		while (rv < loc.s) {
			++rv;
			ins(rv);
		}
		
		ll t = que[i].f.f;
		while (pt < us && t > upd[pt].f) {
			ll loc = upd[pt].s.f;
			if (lv <= loc && loc <= rv) del(loc);
			a[loc] = rev[pt].s;
			if (lv <= loc && loc <= rv) ins(loc);
			++pt;
		}
		while (pt > 0 && t < upd[pt - 1].f) {
			ll loc = upd[pt - 1].s.f;
			if (lv <= loc && loc <= rv) del(loc);
			a[loc] = rev[pt - 1].f;
			if (lv <= loc && loc <= rv) ins(loc);
			--pt;
		}
		
		ll curp = 0;
		for (ll j = 0; j < cp; j++) {
			if (cand[j] > 0 && ffreq[cand[j]] > 0 && vis[cand[j]] != i + 1) {
				cand[curp++] = cand[j];
				vis[cand[j]] = i + 1;
			}
		}
		cp = curp;
		
		sort(cand, cand + cp);
		
		cand[cp] = 100001;
		
		ll pt = 0, tot = 0;
		vector<pair<ll, ll>> fv;
		for (ll i = 0; i <= cp; i++) {
			if (cand[i] != cand[pt]) {
				fv.push_back(make_pair(cand[pt], tot));
				pt = i;
				tot = 0;
			}
			tot += ffreq[cand[i]];
		}
		
		pt = 0;
		ll sent = 1e9, cur = 0;
		ll ans = sent, kv = que[i].f.s;
		for (ll i = 0; i < fv.size(); i++) {
			while (pt < fv.size() && cur < kv) {
				cur += fv[pt].s;
				++pt;
			}
			
			if (cur >= kv) {
				ans = min(ans, fv[pt - 1].f - fv[i].f);
			}
			
			cur -= fv[i].s;
		}
		
		if (ans == sent) ans = -1;
				
		res[t] = ans;
	}
	
	sort(que.begin(), que.end());
	for (pair<pair<ll, ll>, pair<ll, ll>> x: que) cout << res[x.f.f] << '\n';
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