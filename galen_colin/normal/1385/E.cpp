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

vi digraph[200005];
vpl elist;
bool vis[200005];
bool instack[200005];
bool swp[200005];
ll topo[200005];
ll id[200005];
ll ord[200005];

bool cyclic(ll v) {
  if (!vis[v]) {
    vis[v] = 1;
    instack[v] = 1;

    for (ll x: digraph[v]) {
      if (!vis[x] && cyclic(x)) return 1;
      else if (instack[x]) return 1;
    }
  }
  
  instack[v] = 0;
  return 0;
}
 
void solve(int tc) {
  cin >> n >> m;
  f0r(i, n) {
    digraph[i].clear();
    vis[i] = instack[i] = swp[i] = id[i] = 0;
  }
  elist.clear();

  f0r(i, m) {
    cin >> z >> x >> y;
    --x; --y;
    if (z) {
      digraph[x].pb(y);
      ++id[y];
    }
    elist.pb(mp(x, y));
  }

  f0r(i, n) if (cyclic(i)) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  queue<pii> q;
  f0r(i, n) {
    if (id[i] == 0) q.push(mp(i, 0));
    vis[i] = 0;
  }

  while (!q.empty()) {
    pii x = q.front();
    q.pop();

    vis[x.f] = 1;
    topo[x.f] = x.s;

    for (ll y: digraph[x.f]) {
      --id[y];
      if (!vis[y] && id[y] == 0) {
        vis[y] = 1;
        q.push(mp(y, x.s + 1));
      }
    }
  }

  pll tv[n];
  f0r(i, n) tv[i] = mp(topo[i], i);
  sort(tv, tv + n);
  f0r(i, n) ord[tv[i].s] = i;
  for (pll x: elist) {
    if (ord[x.f] > ord[x.s]) swap(x.f, x.s);
    cout << x.f + 1 << " " << x.s + 1 << '\n';
  }
}
 
int main() {
  send help
 
  // usaco("cowland");
 
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}