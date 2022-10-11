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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 

 
void solve(int tc) {
  cin >> n >> m;

  vi edges[n];
  ll id[n];
  ll real_id[n];
  ll stid[n];
  ms(stid, 0);
  ms(real_id, 0);
  ms(id, 0);
  f0r(i, m) {
    cin >> x >> y; --x; --y;
    edges[x].pb(y);
    ++id[y];
    ++real_id[y];
    ++stid[y];
  }

  bool on[n];
  ms(on, 0);
  bool vis[n];
  ms(vis, 0);

  queue<int> q;
  f0r(i, n) if (id[i] == 0) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (vis[x]) continue;
    vis[x] = 1;

    if (vsz(edges[x]) == 0 || id[x] == 0) on[x] = 1;

    for (int y: edges[x]) {
      if (!on[x]) --id[y];
      --real_id[y];
      if (real_id[y] == 0) q.push(y);
    }
  }

  ll c = 0;
  f0r(i, n) if (!on[i]) ++c;
  if (c <= 4 * n / 7) {
    cout << c << '\n';
    f0r(i, n) if (!on[i]) cout << i + 1 << " ";
    cout << '\n';
    return;
  }

  f0r(i, n) real_id[i] = stid[i];

  ms(on, 0);
  ms(vis, 0);

  ll dep[n];
  ms(dep, 0);
  q = queue<int>();
  f0r(i, n) if (real_id[i] == 0) {
    q.push(i);
    dep[i] = 0;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (vis[x]) continue;
    vis[x] = 1;

    if (dep[x] > 1) {
      on[x] = 1;
      dep[x] = -1;
    }

    for (int y: edges[x]) {
      --real_id[y];
      dep[y] = max(dep[y], dep[x] + 1);
      if (real_id[y] == 0) q.push(y);
    }
  }

  c = 0;
  f0r(i, n) if (on[i]) ++c;
  if (c <= 4 * n / 7) {
    cout << c << '\n';
    f0r(i, n) if (on[i]) cout << i + 1 << " ";
    cout << '\n';
  } else {
    cout << n - c << '\n';
    f0r(i, n) if (!on[i]) cout << i + 1 << " ";
    cout << '\n';
  }
}
 
int main() {
  send help
 
  // usaco("file");
 
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}