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
 
const ll mod = 1000000007;

template <typename num_t>
struct hld {
  int vert, all, cnt = 1;
  vector<int> heavy, size, p, chain, num, csz, top, depth;
  vector<vector<int>> edges;
  vector<num_t> tree, comp;

  /* change this problem by problem */

  const num_t SENTINEL = 0;

  inline num_t OP(num_t x, num_t y) {
    return x + y;
  }

  /* end changeable section */

  void init_graph(int nodes) {
    vert = nodes;
    edges = vector<vector<int>>(vert);
    heavy = vector<int>(vert, -1);
    size = vector<int>(vert);
    p = vector<int>(vert);
    chain = vector<int>(vert);
    num = vector<int>(vert);
    csz = vector<int>(vert);
    top = vector<int>(vert);
    depth = vector<int>(vert);
    tree = vector<num_t>(4 * vert);
    comp = vector<num_t>(4 * vert);
  }

  /* edges are 0-indexed */
  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void init_hld() {
    dfs(0);
    decomp(0);
  }

  void init_values(const vector<num_t>& vals) {
    /* assume vals.size() = vert */
    for (int i = 0; i < vert; i++) {
      modify(i, vals[i]);
    }
  }  
  /* basic segment tree stuff */
  void upd(int v, int tl, int tr, int pos, int d){
    if(tl == tr){
      tree[v] = d;
      return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v + v, tl, tm, pos, d); else
      upd(v + v + 1, tm + 1, tr, pos, d);
    tree[v] = OP(tree[v + v], tree[v + v + 1]);
  }
  
  num_t query(int v, int tl, int tr, int l, int r){
    if(l > tr || r < tl){
      return SENTINEL;
    }
    if(l <= tl && r >= tr){
      return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return OP(query(v + v, tl, tm, l, r), query(v + v + 1, tm + 1, tr, l, r));
  }
  /* end segtree part */
  
  void dfs(int v, int parent = 0){
    p[v] = parent;
    size[v] = 1;
    for (int i = 0; i < edges[v].size(); i++) {
      int to = edges[v][i];
      if (to == parent){
        continue;
      }
      depth[to] = depth[v] + 1;
      dfs(to, v);
      size[v] += size[to];
      if (heavy[v] == -1 || size[to] > size[heavy[v]]){
        heavy[v] = to;
      }
    }
  }
  
  void decomp(int v, int parent = -1){
    chain[v] = cnt - 1;
    num[v] = all++;
    if(!csz[cnt - 1]){
      top[cnt - 1] = v;
    }
    ++csz[cnt - 1];
    if(heavy[v] != -1){
      decomp(heavy[v], v);
    }
    for (int i = 0; i < edges[v].size(); i++) {
      int to = edges[v][i];
      if(to == parent || to == heavy[v]){
        continue;
      }
      ++cnt;
      decomp(to, v);
    }
  }
  
  num_t path(int a, int b){
    num_t res = SENTINEL;
    while(chain[a] != chain[b]){
      if(depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
      int start = top[chain[a]];
      if(num[a] == num[start] + csz[chain[a]] - 1)
        res = OP(res, comp[chain[a]]);
      else
        res = OP(res, query(1, 0, vert - 1, num[start], num[a]));
      a = p[start];
    }
    if(depth[a] > depth[b]) swap(a, b);
    res = OP(res, query(1, 0, vert - 1, num[a], num[b]));
    return res;
  }
  
  void modify(int edge, int v){
    upd(1, 0, vert - 1, num[edge], v);
    int start = num[top[chain[edge]]];
    int end = start + csz[chain[edge]] - 1;
    comp[chain[edge]] = query(1, 0, vert - 1, start, end);
  }
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

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> k;
  ai(a, n);
  ms(b, 0);

  f0r(i, n) {
    ans += b[a[i] ^ k];
    ++b[a[i]];
  }

  cout << ans << endl;
}