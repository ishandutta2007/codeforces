#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
const ll template_array_size = 1e6 + 19180;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;



void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (n % 2 == 0) {
		ll pt = 0;
		for (;pt < n; pt += 2) {
			ll g = gcd(abs(a[pt]), abs(a[pt + 1]));
			cout << a[pt + 1] << " " << -a[pt] << " ";
		}
		cout << '\n';
		return;
	}
	
	if (n > 40050) {
		vector<ll> fine[20001];
		vector<ll> sure;
		
		vector<ll> ans(n);
		
		for (ll i = 0; i < n; i++) fine[a[i] + 10000].push_back(i);
		
		for (ll i = 0; i <= 20000; i++) {
			if (fine[i].size() > 2) {
				ll b = fine[i][0], c = fine[i][1], d = fine[i][2];
				
				ans[b] = 1;
				ans[c] = 1;
				ans[d] = -2;
				
				for (ll j = 0; j < n; j++) {
					if (j != b && j != c && j != d) {
						sure.push_back(j);
					}
				}
				
				break;
			}
		}
		assert(sure.size() == n - 3);
		
		for (ll pt = 0; pt < sure.size(); pt += 2) {
			ans[sure[pt]] = a[sure[pt + 1]];
			ans[sure[pt + 1]] = -a[sure[pt]];
		}
		for (ll x: ans) cout << x << " ";
	} else {
		ll pt = 3;
		cout << a[1] * a[2] << " " << a[0] * a[2] << " " << -a[0] * a[1] * 2 << " ";
		for (;pt < n; pt += 2) {
			cout << a[pt + 1] << " " << -a[pt] << " ";
		}
	}
	
	cout << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 

		
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}