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



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

pair<ll, ll> p[200005];
vector<pair<ll, ll>> cv;
map<ll, ll> cnt;
ll tot[5000005];

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = {a[i], i};
		++cnt[a[i]];
	}
	
	sort(p, p + n);
	
	ll targ = -1;
	for (pair<ll, ll> x: cnt) cv.push_back(x);
	for (ll i = 0; i < cv.size(); i++) {
		tot[2 * cv[i].f] += cv[i].s / 2;
		if (tot[2 * cv[i].f] > 1) {
			targ = 2 * cv[i].f;
			break;
		}
		for (ll j = i + 1; j < cv.size(); j++) {
			tot[cv[i].f + cv[j].f] += min(cv[i].s, cv[j].s);
			if (tot[cv[i].f + cv[j].f] > 1) {
				targ = cv[i].f + cv[j].f;
				break;
			}
		}
		if (targ != -1) break;
	}
	
	if (targ == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		ll pt = n - 1;
		ll t = 0;
		for (ll i = 0; i < n; i++) {
			while (pt > i && p[i].f + p[pt].f > targ) --pt;
			if (pt > i && p[i].f + p[pt].f == targ) {
				cout << p[i].s + 1 << " " << p[pt].s + 1 << " ";
				--pt;
				++t;
				if (t == 2) exit(0);
			}
		}
	}
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