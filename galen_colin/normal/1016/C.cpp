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

ll tpre[300005], tspre[300005], tssuf[300005];
ll bpre[300005], bspre[300005], bssuf[300005];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> n;
  ai(a, n);
  ai(b, n);

  ll run = 0;
  f0r(i, n) {
    run += a[i];
    tpre[i] = run;
  }

  run = 0;
  f0r(i, n) {
    run += b[i];
    bpre[i] = run;
  }

  run = 0;
  f0r(i, n) {
    run += i * a[i];
    tspre[i] = run;
  }

  run = 0;
  f0r(i, n) {
    run += i * b[i];
    bspre[i] = run;
  }

  run = 0;
  f0rd(i, n - 1) {
    run += (n - i - 1) * a[i];
    tssuf[i] = run;
  }

  run = 0;
  f0rd(i, n - 1) {
    run += (n - i - 1) * b[i];
    bssuf[i] = run;
  }

  run = 0;
  f0r(i, n) {
    if (i % 2 == 0) {
      ll tv = tspre[n - 1];
      if (i) tv -= tspre[i - 1];
      tv += i * (tpre[n - 1] - tpre[i - 1]);

      ll bv = bssuf[i];
      ll bb = bpre[n - 1];
      if (i) bb -= bpre[i - 1];
      bv += (n + i) * bb;

      ans = max(ans, run + tv + bv);

      run += (2 * i) * a[i];
      run += (2 * i + 1) * b[i];
    } else {
      ll bv = bspre[n - 1];
      if (i) bv -= bspre[i - 1];
      bv += i * (bpre[n - 1] - bpre[i - 1]);

      ll tv = tssuf[i];
      ll t = tpre[n - 1];
      if (i) t -= tpre[i - 1];
      tv += (n + i) * t;

      ans = max(ans, run + tv + bv);

      run += (2 * i) * b[i];
      run += (2 * i + 1) * a[i];
    }
  }

  cout << ans << endl;
}