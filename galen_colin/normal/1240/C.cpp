#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
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
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const ll mod = 1000000007;
 
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
ll gcd(ll x, ll y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[1000006]; 
void sieve(int n) { 
  f0r(i, n + 1) prime[i] = 1;
  for (int p = 2; p * p <= n; p++) { 
    if (prime[p] == true) { 
      for (int i = p * p; i <= n; i += p) 
        prime[i] = false; 
    } 
  } 
  prime[1] = prime[0] = 0;
} 
 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[500005];
ll b[500005];
string s, t;
ll ans = 0;
vector<pair<ll, ll> > edges[500025];
ll dp[500005][2];
 
void dfs(int v, int par) {
  // cout << "V    " << v << " " << par << endl;
  if (par != -1 && edges[v].size() == 1) {
    dp[v][0] = 0;
    dp[v][1] = 0;
    return;
  }
 
  vector<pair<ll, ll> > o;
  for (auto x: edges[v]) {
    if (x.s != par) o.pb(x);
  }
  for (auto x: o) dfs(x.s, v);
  sort(all(o), [](pair<ll, ll> v1, pair<ll, ll> v2) {
    if (dp[v1.s][0] - dp[v1.s][1] - v1.f == dp[v2.s][0] - dp[v2.s][1] - v2.f) return v1.f > v2.f;
    return (
      dp[v1.s][0] - dp[v1.s][1] - v1.f < 
      dp[v2.s][0] - dp[v2.s][1] - v2.f
    );
  });
  // reverse(all(o));
  
 
  ll stop = min(k, (ll)o.size());
  ll ans = 0;
  
  f0r(i, stop) {
    ans += o[i].f + dp[o[i].s][1];
  }
  // cout << v << " " << ans << endl;
  f1r(i, stop, o.size()) {
    ans += dp[o[i].s][0];
  }
  // cout << v << " " << ans << endl;
  dp[v][0] = ans;
  if (stop != k) dp[v][1] = ans;
  f0rd(i, stop - 1) {
    ans += dp[o[i].s][0] - dp[o[i].s][1] - o[i].f;
    dp[v][0] = max(dp[v][0], ans);
    dp[v][1] = max(dp[v][1], ans);
  }
  // cout << v << " " << dp[v][0] << " " << dp[v][1] << endl;
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
 
  cin >> Q;
  f0r(q, Q) {
    cin >> n >> k;
    f0r(i, n) edges[i].clear();
    f0r(i, n - 1) {
      cin >> x >> y >> z;
      --x; --y;
      edges[x].pb(mp(z, y));
      edges[y].pb(mp(z, x));
    }
    // f0r(i, n) {sort(all(edges[i])); reverse(all(edges[i]));}
    f0r(i, n) f0r(j, 2) dp[i][j] = 0;
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
  }
}