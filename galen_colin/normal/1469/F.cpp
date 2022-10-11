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
 
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll psum[1500005];
 
void solve(int tc = 0) {
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	reverse(a, a + n);
	
	ll lv = 0, rv = 1000000;
	while (lv < rv) {
		ll m = (lv + rv) / 2;
		
		memset(psum, 0, sizeof(psum));
		
		bool pos = 0;
		
		ll curv = 1, r = 0, tot = 0, pt = 0;
		++psum[0];
		--psum[1];
		
		if (curv >= k) pos = 1;
		for (ll i = 0; i <= m; i++) {
			r += psum[i];
			tot = r;
			
			while (tot > 0) {
				if (pt >= n) break;
				
				--curv;
				--tot;
				
				ll lpos = i + 2;
				ll rpos = i + 2 + (a[pt] - 1) / 2 - 1;
				
				if (lpos <= m) {
					curv += (min(rpos, m) - lpos + 1) * 2;
				}
				
				psum[lpos] += 2;
				psum[rpos + 1] -= 2;
				
				if (a[pt] % 2 == 0) {
					ll p = rpos + 1;
					if (p <= m) ++curv;
					++psum[p];
					--psum[p + 1];
				}
				
				++pt;
				
				if (curv >= k) pos = 1;
			}
		}
		
		if (pos) rv = m;
		else lv = m + 1;
	}
	
	if (lv == 1000000) lv = -1;
	cout << lv << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	// cout << setprecision(12) << fixed;
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}