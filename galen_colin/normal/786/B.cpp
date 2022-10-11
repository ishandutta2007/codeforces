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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l], l);

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
    /* end special part */

    lazy[i] = num_t();
  }
};

struct max_t {
  long long val;
  int ind;
  static const long long null_v = -9223372036854775807LL;

  max_t(): val(0) {}
  max_t(long long v): val(v) {}
  max_t(long long v, int i): val(v), ind(i) {};

  max_t op(max_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val < other.val) ? other : *this;
  }
  
  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val, ind);
  }
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<ll, ll>> e1[100005];
pair<ll, ll> e2[100005];
vector<pair<ll, ll>> e3[100005];
pair<pair<ll, ll>, pair<ll, ll>> e3v[100005];
ll pt[100005];
set<ll> unvis;
ll dist[200005];
bool vis[200005];
const ll inft = 2e18;
segtree<max_t> st;

ll ep2, ep3;

void ins(ll i) {
	if (pt[i] >= e3[i].size()) return;
	st.update(i, i, e3[i][pt[i]].f + 1);
}

void del(ll i) {
	st.update(i, i, -(e3[i][pt[i]].f + 1));
	++pt[i];
}

void solve(int tc = 0) {
	ll s;
	cin >> n >> m >> s;
	--s;
	
	ep2 = n, ep3 = 0;
	
	for (ll i = 0; i < m; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> z;
			--x; --y;
			e1[x].push_back({y, z});
		} else {
			ll l, r;
			cin >> x >> l >> r >> z;
			--x; --l; --r;
			if (t == 2) {
				e1[x].push_back({ep2, z});
				e2[ep2 - n] = {l, r};
				++ep2;
			} else {
				e3[l].push_back({r, ep3});
				e3v[ep3] = make_pair(make_pair(l, r), make_pair(x, z));
				++ep3;
			}
		}
	}
		
	memset(c, -1, sizeof(c));
	st.init(n, c);
	
	for (ll i = 0; i < 200001; i++) dist[i] = inft;
	
	for (ll i = 0; i < n; i++) {
		unvis.insert(i);
		
		if (e3[i].size()) {
			sort(e3[i].begin(), e3[i].end());
			reverse(e3[i].begin(), e3[i].end());
						
			ins(i);
		}
	}
	
	dist[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	
	pq.push({0, s});
	
	while (!pq.empty()) {
		pair<ll, ll> x = pq.top();
		pq.pop();
				
		if (vis[x.s]) continue;
		unvis.erase(x.s);
		vis[x.s] = 1;
		dist[x.s] = x.f;
		
		if (x.s < n) {
			for (pair<ll, ll> y: e1[x.s]) {
				if (dist[y.f] > dist[x.s] + y.s) {
					dist[y.f] = dist[x.s] + y.s;
					pq.push({dist[y.f], y.f});
				}
			}
			
			while (1) {
				auto res = st.query(0, x.s);
				if (res.val >= x.s) {
					ll pos = res.ind;
					pair<pair<ll, ll>, pair<ll, ll>> y = e3v[e3[pos][pt[pos]].s];
					del(pos);
					ins(pos);
					
					if (dist[y.s.f] > dist[x.s] + y.s.s) {
						dist[y.s.f] = dist[x.s] + y.s.s;
						pq.push({dist[y.s.f], y.s.f});
					}
				} else break;
			}
		} else {
			ll l = e2[x.s - n].f, r = e2[x.s - n].s;
			set<ll>::iterator it;
			while ((it = unvis.lower_bound(l)) != unvis.end()) {
				if (*it > r) break;
				pq.push({dist[x.s], *it});
				unvis.erase(it);
			}
		}
	}
	
	for (ll i = 0; i < n; i++) {
		if (dist[i] == inft) dist[i] = -1;
		cout << dist[i] << " ";
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