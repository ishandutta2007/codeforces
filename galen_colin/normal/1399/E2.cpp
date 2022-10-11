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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;

namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
}

using namespace modop;

ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

vector<pair<ll, pll>> edges[100005];
ll nleaf[100005]; // number of leaves below edge i
ll wt[100005];
// ll c[100005];

void dfs(int v, int p) {
	if (edges[v].size() == 1 && p != -1) { //leaf, not root
		nleaf[v] = 1;
	} else {
		nleaf[v] = 0;
	}
	
	for (pair<ll, pll> x: edges[v]) {
		if (x.f != p) {
			dfs(x.f, v);
			nleaf[v] += nleaf[x.f];
		}
	}
	
	for (pair<ll, pll> x: edges[v]) {
		if (x.f == p) {
			wt[v] = x.s.f;
			c[v] = x.s.s;
		}
	}
}

// costs in {1, 2}
// so fix number of 1-edge uses?

vl seq;

ll findv(ll req) {
	ll l = 0, r = seq.size();
	while (l < r) {
		ll m = (l + r) / 2;
		
		if (seq[m] >= req) r = m;
		else l = m + 1;
	}
	
	if (r == seq.size()) r = 1e12;
	return r;
}

void solve(int tc) {
	cin >> n >> k;
	
	f0r(i, n) edges[i].clear();
	
	f0r(i, n - 1) {
		cin >> x >> y >> z >> m;
		--x; --y;
		edges[x].pb(mp(y, mp(z, m)));
		edges[y].pb(mp(x, mp(z, m)));
	}
		
	dfs(0, -1);
	
	ll tot = 0;
	priority_queue<pll> pq, pq2;
		
	seq.clear();
	ll tot2 = 0, cleared = 0;
	ll tot1 = 0;
	f1r(i, 1, n) {
		ll val = wt[i] * nleaf[i];
		ll next = (wt[i] / 2) * nleaf[i];
		tot += val;
		if (c[i] == 1) {
			pq.push(mp(val - next, i));
			tot1 += val;
		}
	}
	f1r(i, 1, n) {
		if (c[i] == 2) {
			tot2 += wt[i] * nleaf[i];
			ll val = wt[i] * nleaf[i];
			ll next = (wt[i] / 2) * nleaf[i];
			pq2.push(mp(val - next, i));
		}
	}
	seq.pb(0);
	
	
	while (tot2 > 0) {
		pll x = pq2.top();
		pq2.pop();
		
		ll i = x.s;
		ll val = wt[i] * nleaf[i];
		ll next = (wt[i] / 2) * nleaf[i];
		cleared += val - next;
		tot2 += next - val; // this is negative right
		wt[i] /= 2;
		
		val = wt[i] * nleaf[i];
		next = (wt[i] / 2) * nleaf[i];
		pq2.push(mp(val - next, i));
		
		seq.pb(cleared);
	}
	// cout << seq << endl;
		
	ans = 2 * findv(tot - k);
	ll cur = 0;
	while (tot1 > 0) {
		pll x = pq.top();
		pq.pop();
		
		ll i = x.s;
		ll val = wt[i] * nleaf[i];
		ll next = (wt[i] / 2) * nleaf[i];
		tot += next - val; // this is negative right
		tot1 += next - val; // this is negative right hopefully
		wt[i] /= 2;
		
		val = wt[i] * nleaf[i];
		next = (wt[i] / 2) * nleaf[i];
		pq.push(mp(val - next, i));
		
		++cur;
		ans = min(ans, cur + 2 * findv(tot - k));
	}
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help

	// usaco("cowland");

	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}