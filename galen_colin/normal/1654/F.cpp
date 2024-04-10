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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
 
// benq - print any container + pair
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
	cout << "["; 
	for (auto it = v.begin(); it != v.end();) {
		cout << *it;
		if (++it != v.end()) cout << ", ";
	}
	return cout << "]";
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
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

const ll m1 = 1455910909;
const ll m2 = 1455952999;
ll b1 = 1500 + rng() % 1000000000;
ll b2 = 7500 + rng() % 400000000;

vector<vector<pair<ll, ll>>> h[20];
ll pow1[1 << 20];
ll pow2[1 << 20];

string xorate(int x) {
	string t = "";
	for (ll i = 0; i < m; i++) t.push_back(s[i ^ x]);
	return t;
}

ll compare(ll a, ll b) {
	ll sz = 0;
	ll ra = a, rb = b;
	for (ll i = n - 1; i >= 0; i--) {
		ra &= ~(1 << i);
		rb &= ~(1 << i);

		ll nha1 = h[i][(sz ^ a) >> i][ra].f;
		ll nha2 = h[i][(sz ^ a) >> i][ra].s;
		ll nhb1 = h[i][(sz ^ b) >> i][rb].f;
		ll nhb2 = h[i][(sz ^ b) >> i][rb].s;

		if (nha1 == nhb1 && nha2 == nhb2) {
			sz += (1 << i);
		}
	}

	int v = 0;
	if (sz < m) {
		v = s[sz ^ a] - s[sz ^ b];
	}
	if (v <= 0) return a;
	return b;
}

void solve(int tc = 0) {
  cin >> n >> s;
  m = 1 << n;

  pow1[0] = pow2[0] = 1;
  for (ll i = 1; i < 1e6 - 5; i++) {
	pow1[i] = (pow1[i - 1] * b1) % m1;
	pow2[i] = (pow2[i - 1] * b2) % m2;
  }

  for (ll i = 0; i < n; i++) {
	for (ll j = 0; (j << i) < m; j++) {
		h[i].push_back(vector<pair<ll, ll>>(1 << i));
		for (ll k = 0; k < (1 << i); k++) {
			ll p = (j << i) + k;
			if (i == 0) {
				h[i][j][k].f = (s[p] - 'a' + 1);
				h[i][j][k].s = (s[p] - 'a' + 1);
			} else {
				if ((k >> (i - 1)) & 1) {
					int nk = k ^ (1 << (i - 1));
					h[i][j][k].f = (h[i - 1][2 * j + 1][nk].f + pow1[(1 << (i - 1))] * h[i - 1][2 * j][nk].f) % m1;
					h[i][j][k].s = (h[i - 1][2 * j + 1][nk].s + pow2[(1 << (i - 1))] * h[i - 1][2 * j][nk].s) % m2;
				} else {
					h[i][j][k].f = (h[i - 1][2 * j][k].f + h[i - 1][2 * j + 1][k].f * pow1[(1 << (i - 1))]) % m1;
					h[i][j][k].s = (h[i - 1][2 * j][k].s + h[i - 1][2 * j + 1][k].s * pow2[(1 << (i - 1))]) % m2;
				}
			}
		}
	}
  }

  ll ans = 0;
  for (int i = 1; i < m; i++) ans = compare(ans, i);
  cout << xorate(ans) << '\n';
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
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}