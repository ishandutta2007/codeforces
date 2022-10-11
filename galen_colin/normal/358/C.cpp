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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

pair<ll, ll> p[100005];

void solve(int tc = 0) {
	cin >> n;
	set<ll> s;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = {a[i], i};
		if (a[i] == 0) s.insert(i);
	}
	
	sort(p, p + n);
	reverse(p, p + n);
	
	for (ll i = 0; i < n; i++) {
		if (p[i].f == 0) break;
		auto x = s.lower_bound(p[i].s);
		if (x == s.end() || b[*x] == 3) b[p[i].s] = -1;
		else {
			ll y = *x;
			b[p[i].s] = 7;
			++b[y];
		}
	}
	
	for (ll i = 0; i < n; i++) if (a[i] == 0) s.insert(i);
	
	for (ll i = 0; i < n; i++) {
		if (b[i] == 7) {
			ll y = *s.lower_bound(i);
			b[i] = c[y];
			if (++c[y] == 3) s.erase(y);
		}
	}
	
	
	// for (ll i = 0; i < n; i++) cout << b[i] << '\n';
	
	ll cs = 0, cq = 0, cd = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (b[i] == -1) cout << "pushBack\n";
			else if (b[i] == 0) {
				cout << "pushStack\n";
				++cs;
			} else if (b[i] == 1) {
				cout << "pushQueue\n";
				++cq;
			} else {
				cout << "pushFront\n";
				++cd;
			}
		} else {
			cout << c[i];
			if (c[i] > 0) {
				cout << " popStack";
				assert(--cs >= 0);
			} if (c[i] > 1) {
				cout << " popQueue";
				assert(--cq >= 0);
			} if (c[i] > 2) {
				cout << " popFront";
				assert(--cd >= 0);
			}
			cout << '\n';
		}
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