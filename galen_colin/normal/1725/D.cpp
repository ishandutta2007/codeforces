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
const ll mod = 998244353;
// ll mod;
 
struct bit {
  int n;
  vector<long long> a;
 
  void init(int s) {
    a = vector<long long>(s + 1, 0);
    n = s;
  }
 
  void add(int loc, long long x) {
    if (loc <= 0) return;
    while (loc <= n) {
      a[loc] += x;
      loc += loc & (-loc);
    }
  }
 
  long long query(int loc) {
    long long sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
};

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> st[1000005], en[1000005];

ll ord[1000005];
ll d[1000005];
ll rord[1000005];
bit ft;
ll gp = 0;

const ll SZ = 18;

void sord(ll st, ll i, ll sz, ll dv = 0) {
  if (sz == 0) return;

  ord[i] = st + sz;
  rord[st + sz] = i;
  d[st + sz] = dv + 1;

  sord(st, 2 * i, sz / 2, dv + 1);
  sord(st + sz, 2 * i + 1, sz / 2, dv + 1);
}

ll gs(ll x) {
  return x * x;
}

void push(ll p) {
  for (ll x: st[p]) {
    ft.add(x + 1, 1);
  }
  for (ll x: en[p]) {
    ft.add(x + 1, -1);
  }
}

ll get(ll p) {
  while (c[gp] < p) {
    ++gp;
    push(gp);
  }
  
  if (gp > 0) p -= c[gp - 1];

  l = 0, r = 1e6;
  while (l < r) {
    ll m = (l + r) / 2;
    ll v = ft.query(m + 1);
    // cout << l << " " << r << " " << m << " " << v << " " << p << endl;
    if (v < p) l = m + 1;
    else r = m;
  }

  // cout << ((rord[l] * 2 + 1) << (gp - d[l])) << " ";
  
  return rord[l] * 2 + 1 + gp - d[l];
}

void solve(int tc = 0) {
	cin >> n >> q;
  ll s = 0, r = n;

  // ord[0] = 0;
  sord(0, 1, (1 << SZ));

  ft.init(1e6 + 7);

  for (ll i = 1; i <= 1e6; i++) {
    ll v = i - !(i & 1);
    ++a[v];

    ll cnt = (i + 1) / 2;
    s += cnt * i;

    if (r < cnt) {
      --a[v];
      ll sub = r * 2 - 1;
      if (sub > 0) ++a[sub];

      cnt -= r;
      s -= cnt * i;

      break;
    }
    r -= cnt;
  }

  cout << s << '\n';

  ll ps = 0;
  for (ll i = 1e6 + 1; i >= 0; i -= 2) {
    ps += a[i];
    a[i] = ps;

    ll p2 = 63 - __builtin_clzll(i);

    ++b[p2];
    st[p2].push_back(ord[i / 2]);
    --b[p2 + a[i]];
    en[p2 + a[i]].push_back(ord[i / 2]);
  }

  ps = 0;
  ll bps = 0;
  for (ll i = 0; i < 1e6; i++) {
    ps += b[i];
    b[i] = ps;
    bps += b[i];
    c[i] = bps;
  }

  // for (ll i = 0; i < 5; i++) cout << i << " " << st[i] << " " << en[i] << endl;

  push(0);

  // for (ll i = 1; i <= n; i++) cout << "get " << i << " " << get(i) << '\n';

  for (ll i = 0; i < q; i++) { cin >> x; cout << get(x) << '\n'; }
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