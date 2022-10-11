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
// const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

const ll magic = 10004205361450474LL;
const ll X = 8591058195128LL;

ll process(vector<ll> v) {
	vector<ll> q;
	q.push_back(0);
	for (ll x: v) q.push_back(x);
	q.push_back(magic + 1);
	
	for (ll i = 0; i < v.size(); i++) {
		if (v[i] == X) {
			cout << "success\n";
			return -1;
		}
	}
	
	for (ll i = 0; i < q.size() - 1; i++) {
		if (q[i] < X && X < q[i + 1]) return i;
	}
}
			
ll ask(vector<ll> v) {
	ll r;
	#ifdef galen_colin_local
		r = process(v);
	#else
		cout << v.size();
		for (ll x: v) cout << " " << x;
		cout << endl;
		cin >> r;
	#endif
	if (r < 0) exit(0);
	return r;	
}

ll dp[10005][7];

ll g(ll l, ll q) {
	l = min(l, 10000LL);
	if (dp[l][q] != -1) return dp[l][q];
	if (q == 0) {
		return 0;
	}
	
	ll p = l;
	for (ll i = 0; i <= l; i++) {
		p += g(p, q - 1) + 1;
	}
	return dp[l][q] = p - l - 1;
}

void solve(int tc = 0) {
	memset(dp, -1, sizeof(dp));
	
	ll l = 1, r = magic;
		
	for (ll q = 5; q > 0; q--) {
		vector<ll> v, askv;
		v.push_back(l - 1);
		
		// cout << q << " " << l << " " << r << endl;
				
		ll p = l;
		
		ll sz = min(l, 10000LL);
		for (ll i = 0; i < sz; i++) {
			p += g(p, q - 1) + 1;
			if (p - 1 <= r) {
				v.push_back(p - 1);
				askv.push_back(p - 1);
			}
		}
		v.push_back(r + 1);
		
		ll ret = ask(askv);
		
		// cout << askv << endl;
				
		l = v[ret] + 1, r = v[ret + 1] - 1;
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
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}