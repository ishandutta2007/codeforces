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
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
// mt19937 rng(steady_clock::now().time_since_epoch().count());
mt19937 rng(61378913);
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
 


ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

pll dp[300005];
pll cur[300005];
bool pol[300005];
vi edges[300005];

void dfs_down(int v, int p) {
  dp[v] = mp(mod, -1);
  if (pol[v]) dp[v] = mp(0, v);

  for (int x: edges[v]) if (x != p) {
    dfs_down(x, v);
    dp[v] = min(dp[v], mp(dp[x].f + 1, dp[x].s));
  }
}

void dfs_up(int v, int p, pll run) {
  cur[v] = min(run, dp[v]);
  if (pol[v]) run = mp(0, v);

  pll pmax[edges[v].size()], smax[edges[v].size()];

  pll rn = mp(mod, -1);
  f0r(i, edges[v].size()) {
    if (edges[v][i] != p) rn = min(rn, mp(dp[edges[v][i]].f + 1, dp[edges[v][i]].s));
    pmax[i] = rn;
  }

  rn = mp(mod, -1);
  f0rd(i, edges[v].size() - 1) {
    if (edges[v][i] != p) rn = min(rn, mp(dp[edges[v][i]].f + 1, dp[edges[v][i]].s));
    smax[i] = rn;
  }

  f0r(i, edges[v].size()) if (edges[v][i] != p) {
    pll rn = run;
    if (i) rn = min(rn, pmax[i - 1]);
    if (i != edges[v].size() - 1) rn = min(rn, smax[i + 1]);
    dfs_up(edges[v][i], v, mp(rn.f + 1, rn.s));
  }
}

vpl elist;

void solve(int tc) {
  cin >> n >> m >> k;

  ms(pol, 0);
  f0r(i, m) {
    cin >> x; pol[--x] = 1;
  }

  f0r(i, n - 1) {
    cin >> x >> y; --x; --y;
    edges[x].pb(y);
    edges[y].pb(x);
    elist.pb(mp(x, y));
  }

  dfs_down(0, -1);
  dfs_up(0, -1, mp(mod, -1));

  // ao(cur, n);

  vl pos;
  f0r(i, elist.size()) {
    if (cur[elist[i].f].s != cur[elist[i].s].s) pos.pb(i + 1);
  }
  cout << pos.size() << '\n';
  ao(pos, pos.size());
}
 
int main() {
  send help
 
  // usaco("file");



  int tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}