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
 
#define f0r(a, b) for (long long a = 0; a < (b); a++)
#define f1r(a, b, c) for (long long a = (b); a < (c); a++)
#define f0rd(a, b) for (long long a = (b); a >= 0; a--)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
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
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
 

 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = -mod * mod;
 
vpl edges[300005];
ll dis[300005];
ll bfirst[300005];
ll blast[300005];
bool has[300005];
vl res;

void dfs1(int v, int p, ll d) {
  dis[v] = d;
  for (pll x: edges[v]) if (x.f != p) dfs1(x.f, v, d + x.s);
}

ll why, why2;
ll why3 = -mod * mod;
bool dfs2(int v, int p, ll d, ll d2) {
  if (v == n - 1) {
    why = d2;
    why2 = p;
    return has[v] = 1;
  }
  bfirst[v] = d;
  blast[v] = dis[v];
  int targ = -1;
  ans = max(ans, d + why3);
  
  for (pll x: edges[v]) if (x.f != p) {
    has[v] |= dfs2(x.f, v, d + x.s, d);
    bfirst[v] = max(bfirst[v], bfirst[x.f]);
    blast[v] = max(blast[v], blast[x.f]);
    if (has[x.f]) {
      targ = x.f;
      res.pb(x.s);
    }
  }

  if (has[v]) {
    for (pll x: edges[v]) if (x.f != p && x.f != targ) {
      ll va = bfirst[x.f] + blast[targ];
      ans = max(ans, va);
      ans = max(ans, blast[x.f] + d2);
    }
  }

  return has[v];
}

int cc = 0;
void dfs3(int v, int p, ll d) {
  if (v != n - 1) ans = max(ans, why + d);
  ++cc;
  if (v != n - 1) why3 = max(why3, d);
  for (pll x: edges[v]) if (x.f != p) dfs3(x.f, v, d + x.s);
}

bool f = 0;
void dfs4(int v, int p) {
  for (pll x: edges[v]) if (x.f != p) {
    if (p != -1 && !has[v]) f = 1;
    dfs4(x.f, v);
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
  f0r(i, n - 1) {
    cin >> x >> y >> z;
    --x; --y;
    edges[x].pb(mp(y, z));
    edges[y].pb(mp(x, z));
  }

  dfs1(n - 1, -1, 0);
  ms(bfirst, 0);
  ms(blast, 0);
  dfs2(0, -1, 0, -mod * mod);
  f0r(i, res.size() - 1) ans = max(ans, dis[0] - res[i] - res[i + 1]);
  dfs3(n - 1, why2, 0);
  dfs2(0, -1, 0, -mod * mod);
  if (cc > 2) f = 1;
  dfs4(0, -1);

  f0r(i, m) {
    cin >> x;
    cout << (f ? dis[0] : min(ans + x, dis[0])) << '\n';
  }
}