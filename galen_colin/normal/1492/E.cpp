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

ll seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
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



void solve(int tc = 0) {
	cin >> n >> m;
	
	ll a[n][m];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	vector<ll> v;
	bool s[m];
	for (ll i = 0; i < m; i++) {
		s[i] = 1;
		for (ll j = 1; j < n; j++) {
			if (a[j][i] != a[0][i]) s[i] = 0;
		}
		if (!s[i]) {
			v.push_back(i);
		}
	}
	
	ll diff[n];
	ll mx = 0;
	for (ll i = 1; i < n; i++) {
		diff[i] = 0;
		for (ll x: v) {
			if (a[0][x] != a[i][x]) ++diff[i];
		}
		if (diff[i] > 4) {
			cout << "No\n";
			return;
		}
		mx = max(mx, diff[i]);
	}
	
	if (mx <= 2) {
		cout << "Yes\n";
		for (ll i = 0; i < m; i++) cout << a[0][i] << " ";
		return;
	}
	
	for (ll i = 0; i < v.size(); i++) {
		for (ll j = 0; j < v.size(); j++) {
			if (i != j) {
				ll d[n];
				for (ll k = 1; k < n; k++) d[k] = diff[k];
				
				ll ti = a[0][v[i]];
				for (ll k = 1; k < n; k++) {
					if (a[k][v[i]] != a[0][v[i]] && d[k] > 2) {
						ti = a[k][v[i]];
						break;
					}
				}
				
				for (ll k = 1; k < n; k++) {
					if (a[k][v[i]] != a[0][v[i]]) --d[k];
					if (a[k][v[i]] != ti) ++d[k];
				}
				
				ll tj = a[0][v[j]];
				for (ll k = 1; k < n; k++) {
					if (a[k][v[j]] != a[0][v[j]] && d[k] > 2) {
						tj = a[k][v[j]];
						break;
					}
				}
				
				ll mx = 0;
				for (ll k = 1; k < n; k++) {
					if (a[k][v[j]] != a[0][v[j]]) --d[k];
					if (a[k][v[j]] != tj) ++d[k];
					mx = max(mx, d[k]);
					if (mx > 2) break;
				}
				
				if (mx > 2) {
					continue;
				}
				
				cout << "Yes\n";
				a[0][v[i]] = ti;
				a[0][v[j]] = tj;
				for (ll i = 0; i < m; i++) {
					cout << a[0][i] << " ";
				}
				return;
			}
		}
	}
	
	cout << "No\n";
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
		// usaco("dining");
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