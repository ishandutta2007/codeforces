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
typedef double ld;
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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag,tree_order_statistics_node_update>;
 
struct bit {
  ll n;
  ordered_set<ll> os[200005];
 
  void init(ll s) {
    for (ll i = 0; i <= s; i++) os[i] = ordered_set<ll>();
    n = s;
  }
 
  void add(ll t, ll y) {
    ++t;
    if (t <= 0) return;
    while (t <= n) {
      os[t].insert(y);
      t += t & (-t);
    }
  }
 
  void del(ll t, ll y) {
    ++t;
    if (t <= 0) return;
    while (t <= n) {
      os[t].erase(y);
      t += t & (-t);
    }
  }
 
  ll query(ll t, ll y) {
    ++t;
    ll sum = 0;
    while (t > 0) {
      sum += os[t].order_of_key(y + 1);
      t -= t & (-t);
    }
    return sum;
  }
  
  #pragma message("BITs are 1-indexed, be careful")
};
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
pll qu[200005];
bit uv, dv;
map<pll, ll> onv;
 
ll ct = 0;
ll vsz;
ll n2; // bruh (n * 2) / 2 = n
ll fac;
 
void ins(ll r, ll c) {
  ll orv = r / 2, oc = c / 2;
  
  ll id = fac * oc + orv;
 
  if (r % 2 == 0) {
    uv.add(orv, id);
 
    ct += dv.query(n2 - orv - 1, -id);
  } else {
    dv.add(n2 - orv - 1, -id);
 
    ct += uv.query(orv, id);
  }
}

void del(ll r, ll c) {
  ll orv = r / 2, oc = c / 2;
  
  ll id = fac * oc + orv;
 
  if (r % 2 == 0) {
    uv.del(orv, id);
 
    ct -= dv.query(n2 - orv - 1, -id);
  } else {
    dv.del(n2 - orv - 1, -id);
 
    ct -= uv.query(orv, id);
  }
}

void solve(int tc) {
  cin >> n >> m >> q;
  f0r(i, q) {
    cin >> l >> r;
    --l; --r;
    qu[i] = mp(l, r);
  }
  
  n2 = n + 2;
  fac = n + m + 2;

  uv.init(n2);
  dv.init(n2);
 
  ct = 0;
 
  f0r(i, q) {
    if (onv[qu[i]]) {
      onv[qu[i]] = 0;
      del(qu[i].f, qu[i].s);
    } else {
      onv[qu[i]] = 1;
      ins(qu[i].f, qu[i].s);
    }
	
	// cout << ct << endl;
 
    if (ct > 0) cout << "NO\n";
    else cout << "YES\n";
  }
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help

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