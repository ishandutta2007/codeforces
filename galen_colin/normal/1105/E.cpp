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
 
#define f0r(a, b) for (int a = 0; a < b; a++)
#define f1r(a, b, c) for (int a = b; a < c; a++)
#define f0rd(a, b) for (int a = b; a >= 0; a--)
#define f1rd(a, b, c) for (int a = b; a >= c; a--)
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

map<string, int> nums;
bitset<40> adj[40];
bool vis[40];
int dp[1 << 20];
vi run;

int rec(int x) {
  if (dp[x] != -1) return dp[x];
  ms(vis, 0);
  bool bad = 0;
  int c = m / 2;
  f1r(i, c, m) {
    if (x & (1 << (i - c))) {
      f1r(j, c, m) {
        if (i == j) continue;
        if (x & (1 << (j - c))) {
          if (adj[i][j]) {
            bad = 1;
            break;
          }
        }
      }
    }
    if (bad) break;
  }

  if (!bad) {
    dp[x] = __builtin_popcount(x);
  } else {
    f0r(i, m - c) {
      if (x & (1 << i)) dp[x] = max(dp[x], rec(x ^ (1 << i)));
    }
  }

  return dp[x];
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> m;
  int c = m / 2;
  f0r(i, (1 << (m - c))) dp[i] = -1;
  if (m == 1) {
    cout << 1 << endl;
    exit(0);
  }

  f0r(i, n) {
    cin >> x;
    if (x == 1) {
      ms(vis, 0);
      for (int x: run) {
        for (int y: run) {
          adj[x][y] = 1;
        }
      }
      run.clear();
    } else {
      cin >> s;
      if (nums.find(s) == nums.end()) {
        int v = nums.size();
        nums[s] = v;
      }
      int v = nums[s];
      if (!vis[v]) {
        run.pb(v);
        vis[v] = 1;
      }
    }
  }

  for (int x: run) {
    for (int y: run) {
      adj[x][y] = 1;
    }
  }

  f0r(i, 1 << c) {
    bool bad = 0;
    f0r(j, c) {
      if (i & (1 << j)) {
        f0r(k, c) {
          if (i & (1 << k)) {
            if (j == k) continue;
            if (adj[j][k]) {
              bad = 1;
              break;
            }
          }
        }
      }
      if (bad) break;
    }

    if (bad) continue;

    ms(vis, 0);
    f0r(j, c) {
      if (i & (1 << j)) {
        f1r(k, c, m) {
          if (adj[j][k]) vis[k] = 1;
        }
      }
    }

    int mask = 0;
    f0r(j, m - c) {
      if (!vis[j + c]) mask += (1 << j);
    }

    int v = rec(mask);
    if (v < 0) v = 0;

    ans = max(ans, (ll)__builtin_popcount(i) + v);
  }

  cout << ans << endl;
}