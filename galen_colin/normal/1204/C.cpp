#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
#define aout(a, lb, rb) for (int i = lb; i <= rb; i++) { if (i > lb) cout << " "; cout << a[lb]; } cout << endl;
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
  return mpow(base, mod - 1);
}

ll mdiv(ll a, ll b) {
  return mmul(a, minv(b));
}
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[100006]; 
void sieve(int n) { 
  ms(prime, 1);
  for (int p = 2; p * p <= n; p++) { 
    if (prime[p] == true) { 
      for (int i = p * p; i <= n; i += p) 
        prime[i] = false; 
    } 
  } 
  prime[1] = prime[0] = 0;
} 

ll n, q, Q, T, m, k, l, r, x, y, z, g;
bool mat[101][101];
vi path[101][101];
int par[101];
bool vis[101];
vi seq;
vi ans;
int dp[1000001];
int p[1000001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  f0r(i, n) {
    string s; cin >> s;
    f0r(j, n) {
      mat[i][j] = s[j] - '0';
    }
  }
  cin >> m;
  f0r(i, m) {
    int x; cin >> x;
    seq.pb(--x);
  }

  f0r(i, n) {
    f0r(j, n) par[j] = -1;
    ms(vis, 0);
    queue<pii> q;
    q.push(mp(i, -1));
    while (!q.empty()) {
      pii x = q.front();
      q.pop();
      if (vis[x.f]) continue;
      // cout << x << endl;
      vis[x.f] = 1;
      par[x.f] = x.s;
      f0r(j, n) {
        if (j != x.f && !vis[j] && mat[x.f][j]) {
          q.push(mp(j, x.f));
        }
      }
    }
    f0r(j, n) {
      int foc = j;
      while (par[foc] != -1) {
        // cout << i << " " << j << " " << foc << endl;
        path[i][j].pb(foc);
        foc = par[foc];
      }
    }
    // f0r(j, n) cout << par[j] << " ";
    // cout << endl;
  }

  // f0r(i, n) {
  //   f0r(j, n) cout << path[i][j] << " ";
  //   cout << endl;
  // }
  f0r(i, m) dp[i] = 1e7;
  f0r(i, m) p[i] = -1;
  dp[0] = 1;
  f1r(i, 1, m) {
    f1rd(j, i - 1, max(0LL, i - n + 1)) {
      if (seq[i] != seq[j] && path[seq[j]][seq[i]].size() == i - j && dp[j] + 1 <= dp[i]) {
        p[i] = j;
        dp[i] = dp[j] + 1;
      }
    }
  }
  // f0r(i, m) cout << dp[i] << " ";

  // cout << endl;
  // f0r(i, m) cout << p[i] << " ";
  // cout << endl;

 
  int foc = m - 1;
  while (foc != -1) {
    // cout << foc << endl;
    ans.pb(seq[foc]);
    foc = p[foc];
  }

  cout << ans.size() << endl;
  reverse(all(ans));
  f0r(i, ans.size()) {
    if (i) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;
}