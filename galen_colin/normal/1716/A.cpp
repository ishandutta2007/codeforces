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
const ll template_array_size = 1e6 + 53197;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll check(ll v) {
	ll d = abs(n - v);
	if (d % 3) return 1e9;
	else return d / 3;
}

void solve(int tc = 0) {
	cin >> n;

	ll ans = 1e9;
	for (ll i = 0; i < 5; i++) ans = min({ans, i + check(-2 * i), i + check(2 * i)});
	cout << ans << '\n';
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


/*


aaaabbbbccccddddee

ae ad bd bc cc

1,2  2,3  3,4  4,5

+-000  0+-00  00+-0  000+-

1,0,0,0,1  1,0,0,1,0  0,1,0,1,0  0,1,1,0,0  0,0,2,0,0 - 1

5,4  1,2  4,3  2,3

000-+  +-000  00-+0  0+-00

1,0,2,0,1  1,1,1,0,1  1,1,1,1,0  1,1,0,2,0  0,2,0,2,0 - 2

3,2  5,4  3,4  1,2

0-+00  000-+  00+-0  +-000

1,2,2,2,1  2,1,2,2,1  2,2,1,2,1  2,2,2,1,1  2,2,2,2,0 - 3 (3 + 0 = 2,2,2,2,1)

2,1  3,2  4,3  5,4

3,4,4,4,1  3,4,4,3,2  4,3,4,3,2  4,3,3,4,2  4,4,2,4,2 - 4

4,5  2,1  3,4  3,2

7,8,6,8,3  7,7,7,8,3  7,7,7,7,4  7,7,8,6,4  8,6,8,6,4 - 5

2,3  4,5  4,3  2,1

15,14,14,14,7  14,15,14,14,7  14,14,15,14,7  14,14,14,15,7  14,14,14,14,8 - 6

1,2  2,3  3,4  4,5

aaaabbbbccccdd

1,0,0,0  0,1,0,0  0,0,1,0  0,0,0,1 - 0

ad ac bc bb

1,0,0,1  1,0,1,0  0,1,1,0  0,2,0,0 - 1

1,2,0,1  1,1,1,1  1,1,2,0  2,0,2,0 - 2

3,2,2,1  2,3,2,1  2,2,3,1  2,2,2,2 - 3 (3 - 0 = 2,2,2,1)

5,4,4,3  5,4,5,2  4,5,5,2  4,6,4,2 - 4

9,10,8,5  9,9,9,5  9,9,10,4  10,8,10,4 - 5

aaaabbbbccccddddeeeeff

1,0,0,0,0,0  0,1,0,0,0,0  0,0,1,0,0,0  0,0,0,1,0,0  0,0,0,0,1,0  0,0,0,0,0,1

af ae be bd cd cc

1,0,0,0,0,1  1,0,0,0,1,0  0,1,0,0,1,0  0,1,0,1,0,0  0,0,1,1,0,0  0,0,2,0,0,0

1,0,2,0,0,1  1,0,1,1,0,1  1,0,1,1,1,0  1,1,0,1,1,0  0,2,0,1,1,0  0,2,0,0,2,0

1,2,2,0,2,1  1,2,2,1,1,1  1,2,1,2,1,1  2,1,1,2,1,1  2,1,1,2,2,0  2,0,2,2,2,0

3,2,4,2,4,1  3,3,3,2,4,1  3,3,3,3,3,1  3,3,3,3,2,2  3,3,2,4,2,2  2,4,2,4,2,2

5,6,6,6,6,3  6,5,6,6,6,3  6,6,5,6,6,3  6,6,6,5,6,3  6,6,6,6,5,3  6,6,6,6,6,2 (5 + 0 = 6,6,6,6,6,3)

aaaabbbbccccddddeeeeffffgg

ag af bf be ce cd dd

1,2  2,3  3,4  4,5  5,6  6,7

7,6  1,2  6,5  2,3  5,4  3,4

ai ah bh bg cg cf df de ee

1,2  2,3  3,4  4,5  5,6  6,7  7,8  8,9

9,8  1,2  8,7  2,3  7,6  3,4  6,5  4,5

*/