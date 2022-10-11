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

ll dp[2005][2005][2];
ll dp2[2005][2005][2];
ll cnt[2005][2];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n;
  ai(a, n);
  f0r(i, n) --a[i];
  int cc[2] = {0};
  f0r(i, n) {
    ++cc[a[i]];
    cnt[i][0] = cc[0];
    cnt[i][1] = cc[1];
  }

  ms(dp, 0);
  f0r(start, n) {
    f1r(i, start, n) {
      if (i != start) {
        dp[start][i][0] = dp[start][i - 1][0];
        if (a[i] == 0) ++dp[start][i][0];
        if (a[i] == 1) dp[start][i][1] = max(dp[start][i - 1][0], dp[start][i - 1][1]) + 1;
        else dp[start][i][1] = max(dp[start][i - 1][0] + 1, dp[start][i - 1][1]);
      } else {
        if (a[i] == 0) ++dp[start][i][0];
        ++dp[start][i][1];
      }
    }
  }
  
  ms(dp2, 0);
  f0r(start, n) {
    f0rd(i, start) {
      if (i != start) {
        dp2[start][i][0] = dp2[start][i + 1][0];
        if (a[i] == 0) ++dp2[start][i][0];
        if (a[i] == 1) dp2[start][i][1] = max(dp2[start][i + 1][0], dp2[start][i + 1][1]) + 1;
        else dp2[start][i][1] = max(dp2[start][i + 1][0] + 1, dp2[start][i + 1][1]);
      } else {
        if (a[i] == 0) ++dp2[start][i][0];
        ++dp2[start][i][1];
      }
    }
  }

  // f0r(i, n) f0r(j, n) cout << i << " " << j << " " << dp[i][j][1] << " " << dp2[i][j][1] << endl;
  
  f0r(i, n) {
    f1r(j, i, n) {
      ll a1 = cnt[j][0];
      ans = max(ans, a1 + dp[j + 1][n - 1][1]);
      ll a2 = cnt[n - 1][0];
      if (i) a2 -= cnt[i - 1][0];
      if (i) a2 += dp[0][i - 1][1];
      ans = max(ans, a2);

      ll a3 = dp2[j][i][1];
      if (i) a3 += cnt[i - 1][0];
      a3 += cnt[n - 1][1] - cnt[j][1];
      ans = max(ans, a3);
      // cout << i << " " << j << " " << a1 << " " << a2 << " " << a3 << endl;
    }
  }

  cout << ans << endl;
}