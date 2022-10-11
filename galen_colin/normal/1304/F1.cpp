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
const ll mod = 1000000007;
// const ll mod = 998244353;



ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

ll dp[52][20005];
ll mat[52][20005];
ll pre[52][20005];
ll pmax[52][20005];
ll smax[52][20005]; // dab

pll isect(pll a, pll b) {
  return mp(max(a.f, b.f), min(a.s, b.s));
}

ll gsum(int r, int c1, int c2) {
  ll v = pre[r][c2];
  if (c1 > 0) v -= pre[r][c1 - 1];
  return v;
}

ll rec(int r, int c) {
  if (r >= n || c >= m - k + 1) return 0;
  if (dp[r][c] != -1) return dp[r][c];

  ll s = gsum(r, c, c + k - 1);
  ll s2;
  if (r == n - 1) s2 = 0;
  else s2 = gsum(r + 1, c, c + k - 1);
  // cout << "REC " << r << " " << c << " " << s << " " << s2 << endl;

  if (r == 0) {
    return dp[r][c] = s + s2;
  }
  
  ll lpos = max(c - k + 1, 0LL);
  ll rpos = min(c + k - 1, m - k);

  if (lpos != 0) dp[r][c] = max(dp[r][c], s + s2 + pmax[r - 1][lpos - 1]);

  if (rpos != m - k) dp[r][c] = max(dp[r][c], s + s2 + smax[r - 1][rpos + 1]);

  f1r(i, lpos, rpos + 1) {
    pll iv = isect(mp(i, i + k - 1), mp(c, c + k - 1));
    ll loss = 0;
    if (iv.f <= iv.s) loss = gsum(r, iv.f, iv.s);
    dp[r][c] = max(dp[r][c], s + s2 - loss + dp[r - 1][i]);
  }

  return dp[r][c];
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> m >> k;

  f0r(i, n) ai(mat[i], m);
  f0r(i, n) {
    ll run = 0;
    f0r(j, m) {
      run += mat[i][j];
      pre[i][j] = run;
    }
  }

  f0r(i, n) f0r(j, m) dp[i][j] = -1;
  f0r(i, n) {
    f0r(j, m - k + 1) ans = max(ans, rec(i, j));
    // f0r(j, m - k + 1) cout << dp[i][j] << " ";
    // cout << endl;
    ll run = 0;
    f0r(j, m - k + 1) {
      run = max(run, dp[i][j]);
      pmax[i][j] = run;
    }
    // cout << "PMAX ";
    // f0r(j, m - k + 1) cout << pmax[i][j] << " ";
    // cout << endl;
    run = 0;
    f0rd(j, m - k) {
      run = max(run, dp[i][j]);
      smax[i][j] = run;
    }
    // cout << "SMAX ";
    // f0r(j, m - k + 1) cout << smax[i][j] << " ";
    // cout << endl;
  }

  cout << ans << endl;
}