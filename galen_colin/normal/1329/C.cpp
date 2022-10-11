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
// const ll mod = 998244353;
ll mod;



ll n, m, k, q, l, r, x, y, z;
ll a[3000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

ll lb, ub;
ll dp[(1 << 21) + 50];
ll found;
ll seq[(1 << 20) + 50];
bool pos[(1 << 21) + 50];

void upd(int v) {
  --dp[v];
  if (dp[v] == 0) pos[v] = 0;
  while (v != 0) {
    v = (v - 1) / 2;
    --dp[v];
    if (dp[v] == 0) pos[v] = 0;
    else {
      int x = 2 * v + 1, y = 2 * v + 2;
      if (a[x] < a[y]) swap(x, y);
      pos[v] = pos[x];

      if (lb <= v + 1 && v + 1 <= ub) pos[v] = 1;
    }
  }
}

void rm(int v) {
  int x = 2 * v + 1, y = 2 * v + 2;
  if (a[x] < a[y]) swap(x, y);
  if (a[x] == a[y] && a[x] == 0) {
    a[v] = 0;
    upd(v);
  } else {
    a[v] = a[x];
    rm(x);
  }
}

void find(int v) {
  if (pos[v]) {
    ans -= a[v];
    rm(v);
    found = v + 1;
  } else {
    int x = 2 * v + 1, y = 2 * v + 2;
    if (a[x] < a[y]) swap(x, y);
    
    if (dp[x] > 0) {
      find(x);
    }

    if (found != -1) return;

    find(y);
  }
}

void solve(int tc) {
  cin >> n >> m;
  
  ll v1 = (1 << n) - 1;
  ll v2 = (1 << m) - 1;
  ll ops = v1 - v2;
  
  lb = v2 + 1;
  ub = v1;

  ll xx = 1;
  ll stop = (1 << (n + 1));
  f0r(i, stop) {
    dp[i] = 0;
    pos[i] = 0;
    a[i] = 0;
  }
  ai(a, v1);
  f0r(i, v1) {
    if ((1 << xx) - 1 < i + 1) ++xx;
    if ((1 << xx) - 1 > v2) dp[i] = 1;
    pos[i] = 1;
  }
  f0rd(i, v1 - 1) {
    dp[i] += dp[2 * i + 1] + dp[2 * i + 2];
  }

  ans = 0;
  f0r(i, v1) ans += a[i];

  f0r(i, ops) {
    found = -1;
    find(0);

    seq[i] = found;
  }

  cout << ans << '\n';
  ao(seq, ops);
}

int main() {
  send help

  // usaco("file");
  
  int tc;
  // tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}