/* good lesson to take away: be very careful with maps */
/* of course, they create an entry that doesn't exist, but then you have to make sure to remove it if you don't want it */

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
// const ll mod = 998244353;
 


ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

map<int, int> vals[200005];
int mk[200005], sz[200005];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n;
  f0r(i, n) {
    cin >> a[i];
  }
  f0r(i, n) b[a[i]] = i;

  f0r(i, n) {
    mk[i] = i;
    sz[i] = 0;
  }
  
  f0r(j, n) {
    int i = b[j + 1];
    if (i == 0) {
      if (a[i] > a[i + 1]) {
        mk[i] = mk[i + 1];
      }
    } else if (i == n - 1) {
      if (a[i] > a[i - 1]) {
        mk[i] = mk[i - 1];
      }
    } else {
      if (a[i] < a[i - 1]) {
        if (a[i] > a[i + 1]) {
          mk[i] = mk[i + 1];
        }
      } else {
        if (a[i] < a[i + 1]) {
          mk[i] = mk[i - 1];
        } else {
          int small = i - 1, large = i + 1;
          if (sz[mk[small]] > sz[mk[large]]) swap(small, large);
          for (const pii& x: vals[mk[small]]) {
            if (vals[mk[large]][a[i] - x.f]) ++ans;
            else vals[mk[large]].erase(a[i] - x.f);
          }
          mk[i] = mk[large];
          int stor = mk[small];
          if (large == i - 1) f1r(k, i + 1, i + sz[stor] + 1) {
            mk[k] = mk[large];
            ++vals[mk[large]][a[k]];
          }
          else f1r(k, i - sz[stor], i) {
            mk[k] = mk[large];
            ++vals[mk[large]][a[k]];
          }
          sz[mk[large]] += sz[stor];
        }
      }
    }
    ++vals[mk[i]][a[i]];
    ++sz[mk[i]];
  }

  cout << ans << endl;
  // }
}