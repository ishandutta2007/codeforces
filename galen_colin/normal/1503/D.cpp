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
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll loc[400005];
pair<ll, ll> p[200005];
bool used[400005];

void solve(int tc = 0) {	
	cin >> n;
	
	memset(used, 0, sizeof(used));
	
	bool pos = 1;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
		--p[i].f;
		--p[i].s;
		loc[p[i].f] = i;
		loc[p[i].s] = i;
	}
	
	ll cnt = 0, cur = 0, run = 0;
	ll lp = 0, rp = 2 * n - 1;
	vector<pair<ll, ll>> a, b;
	while (lp <= rp) {
		if (lp < cnt) {
			ll v = loc[lp];
			
			// beginning
			if (p[v].f > p[v].s) {
				++cur;
				swap(p[v].f, p[v].s);
			}
			used[p[v].f] = used[p[v].s] = 1;
			a.push_back(p[v]);
		} else if ((2 * n - 1 - rp) < cnt) {
			ll v = loc[rp];
			
			// end
			if (p[v].f < p[v].s) {
				++cur;
				swap(p[v].f, p[v].s);
			}
			used[p[v].f] = used[p[v].s] = 1;
			b.push_back(p[v]);
		} else {
			ans += min(cur, run - cur);
			cur = run = 0;
			ll v = loc[lp];
			
			// beginning
			if (p[v].f > p[v].s) {
				++cur;
				swap(p[v].f, p[v].s);
			}
			used[p[v].f] = used[p[v].s] = 1;
			a.push_back(p[v]);
		}
		
		++cnt;
		++run;
		while (used[lp]) ++lp;
		while (used[rp]) --rp;
	}
	
	ans += min(cur, run - cur);
	
	reverse(b.begin(), b.end());
	for (pair<ll, ll> x: b) a.push_back(x);
		
	for (ll i = 1; i < n; i++) {
		pos &= (a[i - 1].f < a[i].f);
		pos &= (a[i - 1].s > a[i].s);
	}
	
	if (!pos) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}