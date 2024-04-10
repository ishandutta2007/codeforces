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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll mn[200005][10];
ll mx[200005][10];
ll csz[200005];
ordered_set<pair<ll, ll>> mins[10], maxs[10];

void solve(int tc = 0) {
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) {
		// cout << "-------------------- " << i << endl;
		
		ll minv = 1e9, maxv = -1e9;
		
		for (ll j = 0; j < k; j++) {
			ll v;
			cin >> v;
			
			if (maxs[j].size()) minv = min(minv, (ll)maxs[j].order_of_key(make_pair(v, -1)));
			if (mins[j].size()) maxv = max(maxv, (ll)mins[j].order_of_key(make_pair(v, -1)) - 1);
			
			mn[i][j] = mx[i][j] = v;
		}
		
		// cout << " D " << i << endl;
		// cout << i << " " << minv << " " << maxv << endl;
		
		ll tot = 1;
		if (minv <= maxv) {
			for (ll j = minv; j <= maxv; j++) {
				pair<ll, ll> x = *mins[0].find_by_order(j);
				
				// cout << j << " " << x << endl;
				
				tot += csz[x.s];
				for (ll l = 0; l < k; l++) {
					// cout << j << " " << l << " " << make_pair(mn[x.s][l], mx[x.s][l]) << endl;
					mn[i][l] = min(mn[i][l], mn[x.s][l]);
					mx[i][l] = max(mx[i][l], mx[x.s][l]);
				}
			}
			
			// cout << " I " << i << endl;
			
			for (ll i = minv; i <= maxv; i++) {
				for (ll j = 0; j < k; j++) {
					pair<ll, ll> x = *mins[j].find_by_order(minv);
					mins[j].erase(x);
					x = *maxs[j].find_by_order(minv);
					maxs[j].erase(x);
				}
			}
		}
		
		// cout << " E " << i << endl;
		
		csz[i] = tot;
		for (ll j = 0; j < k; j++) {
			mins[j].insert(make_pair(mn[i][j], i));
			maxs[j].insert(make_pair(mx[i][j], i));
		}
		
		// for (pair<ll, ll> x: mins[0]) {
			// cout << x << " " << csz[x.s] << endl;
			// for (ll j = 0; j < k; j++) {
				// cout << make_pair(mn[x.s][j], mx[x.s][j]) << " ";
			// }
			// cout << endl;
		// }
		// for (ll j = 0; j < k; j++) {
			// cout << make_pair(mn[i][j], mx[i][j]) << " ";
		// }
		// cout << endl;
		
		// cout << " F " << i << endl;
		
		ll id = (--maxs[0].end())->s;
		cout << csz[id] << '\n';
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