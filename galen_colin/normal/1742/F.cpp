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



void solve(int tc = 0) {
	cin >> q;

  for (ll i = 0; i < 26; i++) a[i] = b[i] = 0;

  a[0] = b[0] = 1;
  
  for (ll i = 0; i < q; i++) {
    for (ll j = 0; j < 26; j++) c[j] = 0;
    cin >> x >> k;
    cin >> s;
    for (char y: s) ++c[y - 'a'];

    if (x == 1) {
      for (ll j = 0; j < 26; j++) a[j] += k * c[j];
    } else {
      for (ll j = 0; j < 26; j++) b[j] += k * c[j];
    }

    ll sp = -1, ac = 0;
    for (ll j = 0; j < 26; j++) {
      if (a[j]) {
        sp = j;
        break;
      }
    }

    ll lp = -1, bc = 0;
    for (ll j = 25; j >= 0; j--) {
      if (b[j]) {
        lp = j;
        break;
      }
    }

    for (ll j = 0; j < 26; j++) ac += a[j], bc += b[j];

    if (lp == -1) {
      cout << "NO\n";
      continue;
    }

    if (sp == -1) {
      cout << "YES\n";
      continue;
    }

    if (sp > lp) {
      cout << "NO\n";
      continue;
    }

    if (sp < lp) {
      cout << "YES\n";
      continue;
    }

    if (a[sp] < b[lp]) {
      if (a[sp] == ac) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (a[sp] == b[lp]) {
      if (a[sp] == ac && b[sp] != bc) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  }
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