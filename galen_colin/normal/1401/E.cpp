#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
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
 
struct bit {
  int n;
  vector<ll> a;
 
  void init(int s) {
    a = vector<ll>(s + 1, 0);
    n = s;
  }
 
  void add(int loc, ll x) {
    if (loc <= 0) return;
    while (loc <= n) {
      a[loc] += x;
      loc += loc & (-loc);
    }
  }
 
  ll query(int loc) {
    ll sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
  
  #pragma message("BITs are 1-indexed, be careful")
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1000575;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

bit bi;

void add(ll x) {
	++x;
	bi.add(x, 1);
}

void del(ll x) {
	++x;
	bi.add(x, -1);
}

ll getrange(ll l, ll r) {
	++l; ++r;
	return bi.query(r) - bi.query(l - 1);
}

pair<ll, pair<ll, ll>> hor[100005];
pair<pair<ll, ll>, ll> ver[100005];

vector<pair<ll, ll>> event[1000005]; // (x, +z)

void solve(int tc = 0) {
	bi.init(1e6 + 9);
	
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		cin >> hor[i];
	}
	
	const ll mx = 1000000;
	
	ll ans = 1;
	
	for (ll i = 0; i < m; i++) {
		cin >> ver[i].s >> ver[i].f;
		event[ver[i].f.f].push_back(make_pair(ver[i].s, 1));
		event[ver[i].f.s + 1].push_back(make_pair(ver[i].s, -1));
		if (ver[i].f.f == 0 && ver[i].f.s == mx) ++ans;
	}
	
	add(0);
	add(mx);
	
	sort(hor, hor + n);
	
	ll pt = 0;
	
	for (ll i = 0; i < n; i++) {
		while (pt <= hor[i].f) {
			for (pair<ll, ll> x: event[pt]) {
				if (x.s == 1) add(x.f);
				else del(x.f);
			}
			
			++pt;
		}
		
		ans += getrange(hor[i].s.f, hor[i].s.s) - 1;
	}
	
	cout << ans << '\n';
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
 
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}