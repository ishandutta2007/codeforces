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
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;



ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

ll dp[205][205][205]; //len, cur, have
int lps[205][2];
int st[205];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> s;
  n *= 2;
  k = s.length();

  f0r(i, k) {
    if (s[i] == '(') st[i] = 1;
    else st[i] = -1;
  }

  // lps
  f0r(i, k) { // start
    f0r(ad, 2) { // char
      int nc = (ad ? -1 : 1);
      lps[i][ad] = 0;
      f0r(j, i + 1) { // len
        if (j > i) break;
        if (st[j] != nc) continue;
        bool f = 1;
        f0r(k, j) if (st[k] != st[(i - j + 1) + k]) {
          f = 0;
          break;
        }
        if (!f) continue;
        lps[i][ad] = j + 1;
      }
    }
  }

  // f0r(i, k) {
  //   f0r(ad, 2) {
  //     cout << i << " " << s.substr(0, i + 1) << " " << (ad ? ')' : '(') << " " << lps[i][ad] << endl;
  //   }
  // }

  // dp - len, cur, have
  ms(dp, 0);
  dp[0][0][0] = 1;
  f0r(i, n) {
    f0r(j, n) {
      f0r(l, k + 1) {
        f0r(ad, 2) {
          int v = (ad ? -1 : 1);
          int nbal = j + v;
          if (nbal < 0) continue;
          int nlen = 0;
          if (l == k) nlen = k;
          else if (st[l] == v) nlen = l + 1;
          else if (l > 0) nlen = lps[l - 1][ad];
          else if (st[0] == v) nlen = 1;

          // if (dp[i][j][l] + dp[i + 1][nbal][nlen]) {
          //   cout << "from " << i << " " << j << " " << l << " " << v << " (dp: " << dp[i][j][l] << endl;
          //   cout << "to " << i + 1 << " " << nbal << " " << nlen << " (dp: " << dp[i + 1][nbal][nlen] << endl;
          // }

          dp[i + 1][nbal][nlen] = (dp[i + 1][nbal][nlen] + dp[i][j][l]) % mod;
        }
      }
    }
  }

  cout << dp[n][0][k] << endl;
}