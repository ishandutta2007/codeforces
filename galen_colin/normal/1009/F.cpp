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
const ll mod = 1000000007;

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, ll* arr) {
    n = s;
    tree = vector<num_t>(6 * s, 0);
    lazy = vector<num_t>(6 * s, -1);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, ll* arr) {
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
      lazy[i] = v.val;
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

  void eval_lazy(int i, int l, int r) {
    if (lazy[i].val == -1) return;
    tree[i] = tree[i].lazy_op(lazy[i]);
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i];
      lazy[i * 2 + 2] = lazy[i];
    }

    lazy[i] = num_t(-1);
  }

  void clear() {
    update(0, n - 1, 0);
  }
};

struct max_t {
  int val, ind;
  static const int null_v = -10;

  max_t(): val(0) {}
  max_t(int v): val(v) {}
  max_t(int v, int i): val(v), ind(i) {};

  max_t op(max_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val < other.val) ? other : *this;
  }
  
  max_t lazy_op(max_t& v) {
    return max_t(v.val, ind);
  }
};

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

segtree<max_t> st;

int depth[1000005], sz[1000005], par[1000005], res[1000005];
vi child[1000005], edges[1000005];
vi* vals[1000005];

int md = 0;

int dfs_sz(int v, int d = 0, int p = -1) {
  sz[v] = 1;
  par[v] = p;
  depth[v] = d;
  md = max(md, d);

  for (int x: edges[v]) {
    if (x != p) {
      sz[v] += dfs_sz(x, d + 1, v);
      child[v].pb(x);
    }
  }

  return sz[v];
}

void dfs_ans(int v) {
  st.clear();

  if (child[v].size() == 0) {
    res[v] = 0;
    vals[v] = new vi(1, depth[v]);
    st.update(depth[v], depth[v], st.query(depth[v], depth[v]).val + 1);
    return;
  }

  int bigc = child[v][0];
  for (int x: child[v]) {
    if (x != par[v] && sz[x] > sz[bigc]) bigc = x;
  }

  for (int x: child[v]) {
    if (x != par[v] && x != bigc) dfs_ans(x);
  }

  dfs_ans(bigc);
  vals[v] = vals[bigc];

  for (int x: child[v]) {
    if (x != par[v] && x != bigc) {
      for (int y: *vals[x]) {
        vals[v]->pb(y);
        st.update(y, y, st.query(y, y).val + 1);
      }
    }
  }

  // f0r(i, 2*md + 1) cout << v << " " << i << " " << st.query(i, i).val << " " << st.query(i, i).ind << endl;

  // cout << st.query(0, 2 * md).val << " " << st.query(0, 2 * md).ind << endl; 

  st.update(depth[v], depth[v], st.query(depth[v], depth[v]).val + 1);
  res[v] = st.query(0, md - 1).ind - depth[v];
  
  vals[v]->pb(depth[v]);
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n;
  readgraph(edges, n - 1);

  dfs_sz(0);

  md += 2;
  ms(a, 0);
  st.init(md, a);

  dfs_ans(0);

  f0r(i, n) cout << res[i] << '\n';
}