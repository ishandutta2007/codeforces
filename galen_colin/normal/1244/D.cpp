#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
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
ll ans = 1;
ll cost[3][100005];
vi edges[100005];
ll dp[100005][3][3];
ll rev[100005][3];
int mark[100005];

void dfs(int v, int par) {
  if (par == -1) {
    f0r(i, 3) {
      f0r(j, 3) {
        if (i == j) continue;
        dp[v][i][j] = cost[j][v];
      }
    }
  } else {
    f0r(i, 3) {
      f0r(j, 3) {
        if (i == j) continue;
        int l = 0;
        f0r(k, 3) if (i != k && j != k) l = k;
        if (dp[par][i][j] + cost[l][v] < dp[v][j][l]) {
          dp[v][j][l] = dp[par][i][j] + cost[l][v];
          rev[v][l] = j;
        }
      }
    }
  }

  for (int x: edges[v]) if (x != par) dfs(x, v);
}

void odfs(int v, int par, int col1 = 0, int col2 = 0) {
  if (par == -1) {
    int c = 0, oc = 0;
    ll x = mod * mod;
    f0r(i, 3) {
      ll y = mod * mod;
      int ocx = 0;
      f0r(j, 3) {
        if (i == j) continue;
        if (dp[v][i][j] < y) {
          ocx = j;
          y = dp[v][i][j];
        }
      }
      if (y < x) {
        x = y;
        c = i;
        oc = ocx;
      }
    }
    mark[v] = oc + 1;
    int l = 0;
    f0r(i, 3) {
      if (c != i && oc != i) l = i;
    }
    for (int x: edges[v]) if (x != par) odfs(x, v, oc, l);
  } else {
    int l = 0;
    f0r(i, 3) {
      if (col1 != i && col2 != i) l = i;
    }
    mark[v] = l + 1;
    for (int x: edges[v]) if (x != par) odfs(x, v, l, col1);
  }
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
 
  cin >> n;
  f0r(_, 3) ai(cost[_], n);
  readgraph(edges, n - 1);
  f0r(i, n) f0r(j, 3) f0r(k, 3) dp[i][j][k] = mod * mod;
  f0r(i, n) if (edges[i].size() > 2) {
    cout << -1 << endl;
    exit(0);
  }
  int node = -1;
  f0r(i, n) if (edges[i].size() == 1) {
    if (node == -1) dfs(i, -1);
    node = i;
  }

  odfs(node, -1);

  ll x = mod * mod;
  f0r(i, 3) f0r(j, 3) x = min(dp[node][i][j], x);
  cout << x << endl;

  f0r(i, n) cout << mark[i] << " ";
}