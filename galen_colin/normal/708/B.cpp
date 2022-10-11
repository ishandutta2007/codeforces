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
const ll template_array_size = 1e6 + 1160;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;



void solve(int tc = 0) {	
	for (ll i = 0; i < 4; i++) cin >> a[i];
	
	// if (a[1] == 0 && a[2] == 0) {
	
	ll nz = -1, no = -1;
	for (ll it = 0; it < 1e6; it++) {
		if (it * (it - 1) / 2 == a[0]) {
			nz = it;
		}
		if (it * (it - 1) / 2 == a[3]) {
			no = it;
		}
	}
	
	if (nz == -1 || no == -1) {
		cout << "Impossible\n";
		return;
	}
	
	// case - empty string
	ll su = 0;
	for (ll i = 0; i < 4; i++) su += a[i];
	
	if (su == 0) {
		cout << "0\n";
		return;
	}
	
	ll tot = a[1] + a[2];
	
	if (tot == 0) {
		if (a[0] > 0 && a[3] > 0) {
			cout << "Impossible\n";
			return;
		}
		
		if (a[0] == 0) {
			for (ll i = 0; i < no; i++) cout << 1;
			return;
		} else {
			for (ll i = 0; i < nz; i++) cout << 0;
			return;
		}
	}
	
	string s = string(nz, '0') + string(no, '1');
	
	ll inv = nz * no;
	if (a[1] + a[2] != inv) {
		cout << "Impossible\n";
		return;
	}
	
	inv -= a[1];
	
	ll lpt = 0;
	for (ll rpt = nz; rpt < nz + no; rpt++) {
		ll req = min(rpt - lpt, inv);
		if (req > 0) {
			swap(s[rpt], s[rpt - req]);
			inv -= req;
			++lpt;
		}
	}
	
	cout << s << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowland");
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