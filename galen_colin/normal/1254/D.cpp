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
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
 
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

  void radd(int l, int r, ll x) {
    add(l + 1, x);
    add(r + 2, -x);
  }
 
  ll query(int loc) {
    ++loc;
    ll sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
  
  #pragma message("BITs are 1-indexed, be careful")
};

struct lca_lift {
  const int lg = 18;
  int n;
  vector<int> depth;
  vector<vector<int> > edges;
  vector<vector<int> > lift;
  
  void init(int sz) {
    n = sz;
    depth = vector<int>(n);
    edges = vector<vector<int> >(n, vector<int>());
    lift = vector<vector<int> >(n, vector<int>(lg, -1));
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for (int i = 1; i < lg; i++) {
      if (lift[a][i - 1] == -1) break;
      lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift() {
    depth[0] = 0;
    dfs(0, -1);
  }

  void dfs(int v, int par) {
    lift[v][0] = par;

    for (int i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) break;
      lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }

    for (int x: edges[v]) {
      if (x != par) {
        depth[x] = depth[v] + 1;
        dfs(x, v);
      }
    }
  }

  int get(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
      if ((1 << i) <= k) {
        v = lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lift[v][i] != lift[b][i]) {
          v = lift[v][i];
          b = lift[b][i];
        }
      }
      return lift[b][0];
    }
  }
};

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

vi edges[150005], child[150005];
ll val[150005], sz[150005];
int st[150005], en[150005];
ll tot = 0;
int TIME = -1;
const ll C = 400;
vi spec;
bit sumt;
lca_lift lca;

void findc(int v, int p = -1) {
  sz[v] = 1;
  st[v] = ++TIME;

  for (int x: edges[v]) {
    if (x != p) {
      child[v].pb(x);
      findc(x, v);
      sz[v] += sz[x];
    }
  }

  en[v] = TIME;
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> n >> Q;
  ms(val, 0);
  ll MN = minv(n);
  readgraph(edges, n - 1);
  lca.init(n);
  f0r(i, n) for (int x: edges[i]) if (i > x) lca.edge(i, x);
  findc(0);
  ms(a, 0);
  sumt.init(n);
  lca.init_lift();
  f0r(i, n) if (edges[i].size() >= C) spec.pb(i);

  f0r(q, Q) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      --x;

      if (edges[x].size() < C) {
        tot = (tot + sz[x] * y) % mod;
        for (int z: child[x]) {
          sumt.radd(st[z], en[z], (y * (n - sz[z])) % mod);
        }

        sumt.radd(st[x], en[x], msub(0, (y * sz[x]) % mod));
      }
      val[x] = (val[x] + y) % mod;
    } else {
      cin >> x;
      --x;

      ll res = sumt.query(st[x]) % mod;
      res = (res + val[x] * n) % mod;
      res = (res + tot) % mod;

      for (int y: spec) {
        if (y == x) continue;
        int v = lca.get_lca(x, y);
        if (v != y) {
          res = (res + val[y] * sz[y]) % mod;
        } else {
          int dist = lca.depth[x] - lca.depth[y];
          v = lca.get(x, dist - 1);
          res = (res + val[y] * (n - sz[v])) % mod;
        }
      }

      cout << (res * MN) % mod << '\n';
    }
  }
}