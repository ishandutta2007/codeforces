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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<vector<int>> at[105];
pair<int, int> val[105];
ll tot[105];
multiset<string> big[105];

string asdf = "abcdefghgfedcba";

vector<string> query(ll l, ll r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	// #ifdef galen_colin_local
		// vector<string> vs;
		
		// for (ll i = l; i <= r; i++) {
			// for (ll j = i; j <= r; j++) {
				// vs.push_back(asdf.substr(i, j - i + 1));
			// }
		// }
		
		// return vs;
	// #else
		vector<string> vs;
		
		for (ll i = l; i <= r; i++) {
			for (ll j = i; j <= r; j++) {
				string a;
				cin >> a;
				sort(a.begin(), a.end());
				vs.push_back(a);
			}
		}
		return vs;
	// #endif
}

string get(ll n) {
	for (ll i = 1; i <= n; i++) big[i].clear();
	
	vector<string> a = query(0, n - 1);
	
	for (string s: a) {
		big[s.length()].insert(s);
	}
	
	if (n == 1) {
		return *big[1].begin();
	}
	
	a = query(1, n - 1);
	
	for (string s: a) {
		big[s.length()].erase(big[s.length()].find(s));
	}
	
	s = string(n, '?');
	s[0] = (*big[1].begin())[0];
	
	for (ll i = 1; i < n; i++) {
		vector<int> cnt(26, 0);
		for (char c: *big[i].begin()) --cnt[c - 'a'];
		for (char c: *big[i + 1].begin()) ++cnt[c - 'a'];
		
		for (ll j = 0; j < 26; j++) {
			if (cnt[j] == 1) {
				s[i] = 'a' + j;
			}
		}
	}
	
	return s;
}

void solve(int tc = 0) {
	// #ifdef galen_colin_local
		// n = asdf.length();
		// n = 20;
		// asdf = string(n, '?');
		// for (ll i = 0; i < 20; i++) asdf[i] = 'a' + (rng() % 26);
	// #else
		cin >> n;
	// #endif
	
	for (ll i = 1; i <= n; i++) at[i].clear();
	
	vector<string> a = query(0, n - 1);
	
	for (string s: a) {
		vector<int> cnt(26, 0);
		for (char c: s) ++cnt[c - 'a'];
		at[s.length()].push_back(cnt);
	}
	
	ll m = n / 2;
	
	for (ll i = 0; i < m; i++) {
		vector<int> cnt(26, 0);
		memset(tot, 0, sizeof(tot));
		
		ll p = n - i - 1;
		for (ll j = 0; j < at[p].size(); j++) {
			for (ll k = 0; k < 26; k++) cnt[k] -= at[p][j][k];
			
			for (ll k = j; k < j + p; k++) ++tot[k];
		}
				
		ll cur = tot[i];
		for (ll j = 0; j < i; j++) {
			cnt[val[j].f] -= (cur + 1) - tot[j];
			cnt[val[j].s] -= (cur + 1) - tot[j];
		}
				
		for (ll j = 0; j < 26; j++) cnt[j] += (cur + 1) * at[n][0][j];
				
		bool f = 1;
		for (ll j = 0; j < 26; j++) {
			while (cnt[j] > 0) {
				if (f) val[i].f = j;
				else val[i].s = j;
				
				f = 0;
				--cnt[j];
			}
		}
	}
	
	t = string(n, '?');
	
	if (n % 2 == 1) {
		vector<int> cnt = at[n][0];
		for (ll i = 0; i < m; i++) --cnt[val[i].f], --cnt[val[i].s];
		for (ll i = 0; i < 26; i++) {
			if (cnt[i] == 1) {
				t[m] = 'a' + i;
			}
		}
	}
	
	if (n == 1) {
		cout << "! " << t << endl;
		return;
	}
	
	s = get(m);
	
	for (ll i = 0; i < m; i++) {
		if (val[i].f != s[i] - 'a') swap(val[i].f, val[i].s);
		t[i] = val[i].f + 'a';
		t[n - i - 1] = val[i].s + 'a';
	}
	
	cout << "! " << t << endl;
	
	// #ifdef galen_colin_local
		// assert(t == asdf);
	// #endif
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