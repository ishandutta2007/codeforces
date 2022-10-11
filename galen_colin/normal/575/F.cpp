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
#define bl __int128
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

ll dp[2][10005];
ll iv[5005][2];
set<ll> pts;
ll pt[10005];

void solve(int tc) {
  cin >> n;
  ++n;
  cin >> x;
  iv[0][0] = iv[0][1] = x;
  pts.insert(x);
  f1r(i, 1, n) {
    cin >> iv[i][0] >> iv[i][1];
    pts.insert(iv[i][0]);
    pts.insert(iv[i][1]);
  }

  int sz = 0;
  for (ll x: pts) pt[sz++] = x;

  f0r(i, sz) dp[0][i] = abs(x - pt[i]);
  
  f1r(i, 1, n) {
    int last = (i - 1) % 2, cur = i % 2;
    ll rmn = mod * mod, off = 0;
    f0r(j, sz) dp[cur][j] = mod * mod;
    f0r(j, sz) {
      if (j) off += pt[j] - pt[j - 1];
      rmn = min(rmn, dp[last][j] - off);
      dp[cur][j] = min(dp[cur][j], rmn + off);
    }
    rmn = mod * mod, off = 0;
    f0rd(j, sz - 1) {
      if (j != sz - 1) off += pt[j + 1] - pt[j];
      rmn = min(rmn, dp[last][j] - off);
      dp[cur][j] = min(dp[cur][j], rmn + off);
    }
    f0r(j, sz) {
      ll p = pt[j];
      if (p > iv[i][1] || p < iv[i][0]) {
        dp[cur][j] += min(abs(p - iv[i][1]), abs(p - iv[i][0]));
      }
    }
  }

  ans = mod * mod;
  f0r(i, sz) ans = min(ans, dp[(n - 1) % 2][i]);
  cout << ans << '\n';
}

int main() {
  send help

  // usaco("file");

  int tc;
  tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}