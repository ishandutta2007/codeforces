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

// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1600;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll cnt[55][2];

void rec(vector<ll>& a, ll b) {
	if (a.size() == 0 || b < 0) return;
	ll c[2] = {0};
	vector<ll> v[2];
		
	for (ll x: a) {
		ll bv = !!(x & (1LL << b));
		
		if (bv == 0) cnt[b][0] += c[1];
		else cnt[b][1] += c[0];
		
		++c[bv];
		
		v[bv].push_back(x);
	}
	
	rec(v[0], b - 1);
	rec(v[1], b - 1);
}

void solve(int tc = 0) {
	cin >> n;
	
	vector<ll> a(n);
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	memset(cnt, 0, sizeof(cnt));
	
	rec(a, 30);
	
	ll x = 0, inv = 0;
	for (ll i = 30; i >= 0; i--) {
		// cout << cnt[i][0] << " " << cnt[i][1] << '\n';
		inv += min(cnt[i][0], cnt[i][1]);
		if (cnt[i][0] > cnt[i][1]) {
			x += (1LL << i);
		}
	}
	
	cout << inv << " " << x << '\n';
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