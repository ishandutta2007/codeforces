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
ll ans = 0;
 
ll jump[100005];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
  
  ll d;
  cin >> n >> d >> k;
  ai(a, n);

  ll lval = (n - 1) / 2, rval = (n - 1) / 2 + 1;

  ll mx = (n + 1) / 2;
  ll l = 0, r = mx + 1;
  while (l < r) {
    ll m = (l + r) / 2;

    ll lpt = lval - m + 1, rpt = rval + m - 1;
    if (n % 2 == 1) --rpt;
    ll ltarg = lpt, rtarg = rpt;
    ms(b, 0);
    f0r(i, n) jump[i] = -1;

    ll lreach = 0, rreach = n - 1;
    ll lfoc = 0, rfoc = n - 1;

    f0r(i, n) {
      if (i % 2 == 0) {
        lreach += d;
        ll v = a[lfoc];

        while (lfoc - d * (lpt + 1) > lpt) ++lpt;

        while (lpt <= lval && v) {
          if (v >= k - b[lpt]) {
            v -= k - b[lpt];
            b[lpt] = k;
            ++lpt;
          } else {
            b[lpt] += v;
            break;
          }
        }

        ll l1 = rval - 1, r1 = n;
        while (l1 < r1) {
          ll m = (l1 + r1) / 2;

          ll t = n - m;
          ll r = lfoc + t * d;
          if (r >= m) l1 = m + 1;
          else r1 = m;
        }

        ll rt = min(rpt, l1 - 1);
        ll ort = rt;
        while (rt >= rval && v) {
          if (jump[rt] != -1) rt = jump[rt];
          if (v >= k - b[rt]) {
            v -= k - b[rt];
            b[rt] = k;
            --rt;
          } else {
            b[rt] += v;
            break;
          }
        }
        jump[ort] = rt;

        ++lreach;
        ++lfoc;
      } else {
        rreach -= d;
        ll v = a[rfoc];

        while (rfoc + d * (n - rpt) < rpt) --rpt;

        while (rpt >= rval && v) {
          if (v >= k - b[rpt]) {
            v -= k - b[rpt];
            b[rpt] = k;
            --rpt;
          } else {
            b[rpt] += v;
            break;
          }
        }

        ll l1 = 0, r1 = lval + 1;
        while (l1 < r1) {
          ll m = (l1 + r1) / 2;

          ll t = m + 1;
          ll r = rfoc - t * d;
          if (r <= m) r1 = m;
          else l1 = m + 1;
        }

        ll lt = max(lpt, r1);
        ll olt = lt;
        while (lt <= lval && v) {
          if (jump[lt] != -1) lt = jump[lt];
          if (v >= k - b[lt]) {
            v -= k - b[lt];
            b[lt] = k;
            ++lt;
          } else {
            b[lt] += v;
            break;
          }
        }
        jump[olt] = lt;

        --rreach;
        --rfoc;
      }
    }

    bool f = 1;
    f0r(i, n) {
      if (ltarg <= i && i <= rtarg && b[i] < k) f = 0;
    }

    // cout << m << endl;
    // ao(b, n);

    if (f) l = m + 1;
    else r = m;
  }

  cout << mx - l + 1 << endl;
}