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
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
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
const ll mod = 1000000007;
// const ll mod = 998244353;

struct lca_lift {
  const int lg = 20;
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
      if (lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift(int v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }

  void dfs(int v, int par) {
    lift[v][0] = par;

    for (int i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i - 1]][i - 1];
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
	  if (v == -1) return v;
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

vi edges[100005];
map<int, ll> dp[100005];
ll tot[100005];
ll par[100005];
ll sz[100005];
lca_lift lca;

void dfs1(int v, int p = -1) {
  tot[v] = 1;
  sz[v] = 1;

  for (int x: edges[v]) if (x != p) {
    dfs1(x, v);
    dp[v][x] = tot[x] + sz[x];
    tot[v] += tot[x] + sz[x];
    sz[v] += sz[x];
  }
}

void dfs2(int v, int p, ll run) {
  run += tot[v];
  for (int x: edges[v]) if (x != p) {
    ll o = dp[v][x];
    run -= o;
    run += n - sz[x];
    dfs2(x, v, run);
    run -= n - sz[x];
    run += o;
  }
  run -= tot[v];

  par[v] = run;
}

lld solve(int x, int y, int v) {
  if (v != x) {
    return tot[x] - par[x];
  } else {
    int v2 = lca.get(y, lca.depth[y] - lca.depth[x] - 1);
    return tot[x] - dp[x][v2];
  }
}

lld gcnt(int x, int y, int v) {
  if (v != x) {
    return sz[x];
  } else {
    int v2 = lca.get(y, lca.depth[y] - lca.depth[x] - 1);
    return n - sz[v2];
  }
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> m;
  lca.init(n);
  f0r(i, n - 1) {
    cin >> x >> y;
    lca.edge(--x, --y);
    edges[x].pb(y);
    edges[y].pb(x);
  }
  lca.init_lift(0);

  dfs1(0, -1);
  dfs2(0, -1, 0);
  f0r(i, n) tot[i] += par[i];

  cout << setprecision(13) << fixed;
  f0r(i, m) {
    cin >> x >> y;
    --x; --y;

    int v = lca.get_lca(x, y);

    lld xy = gcnt(x, y, v), yx = gcnt(y, x, v);
    lld dist = (lca.depth[x] + lca.depth[y] - 2 * lca.depth[v]);
    lld res = (solve(x, y, v) * yx) + (solve(y, x, v) * xy);
    res /= xy * yx;
    res += dist - 1;

    cout << res << '\n';
  }
}