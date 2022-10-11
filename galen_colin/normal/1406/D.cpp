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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll diff[100005];

ll d;

void answer() {
	ll val = (a[0] + d) / 2;
	
	if ((a[0] + d) % 2 != 0) {
		if ((a[0] + d) > 0) ++val;
	}
	
	cout << val << '\n';
}

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	d = 0;
	
	for (ll i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
		if (diff[i] > 0) d += diff[i];
	}
	
	cin >> q;
	
	answer();
	
	for (ll i = 0; i < q; i++) {
		cin >> l >> r >> x;
		--l; --r;
		
		if (l > 0) {
			if (diff[l - 1] > 0) d -= diff[l - 1];
			diff[l - 1] += x;
			if (diff[l - 1] > 0) d += diff[l - 1];
		}
		
		if (r < n - 1) {
			if (diff[r] > 0) d -= diff[r];
			diff[r] -= x;
			if (diff[r] > 0) d += diff[r];
		}
		
		if (l == 0) a[0] += x;
		
		answer();
	}
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}