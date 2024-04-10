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

const ll mod = 1e9 + 7;

ll madd(ll a, ll b) {
  return (a + b) % mod;
}

ll msub(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}

ll mmul(ll a, ll b) {
  return (a % mod * b % mod) % mod;
}
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[10000006]; 
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

struct matrix {
  using TYPE = long long;
  int n;
  vector<vector<TYPE>> v;

  void init(int s) {
    n = s;
    v = vector<vector<TYPE> >(n, vector<TYPE>(n, 0));
  }

  matrix mul(matrix &b) {
    matrix res;
    res.init(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          res.v[i][j] = madd(res.v[i][j], mmul(v[i][k], b.v[k][j]));
        }
      }
    }
    return res;
  }

  matrix pow(matrix &a, ll x) {
    matrix res;
    res.init(n);
    for (int i = 0; i < n; i++) res.v[i][i] = 1;

    while (x) {
      if (x & 1) {
        res = res.mul(a);
      }
      x /= 2;
      a = a.mul(a);
    }
    return res;
  }  
  #pragma message("be careful with mod in matrix")
} base;

ll n, q, Q, T, m, k, r, x, y, z, g;
int get(char c) {
  if (c - 'a' >= 0) return c - 'a';
  else return 26 + c - 'A';
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> m >> k;
  base.init(m);
  f0r(i, m) f0r(j, m) base.v[i][j] = 1;
  f0r(i, k) {
    string s; cin >> s;
    base.v[get(s[0])][get(s[1])] = 0;
  }
  base = base.pow(base, n - 1);
  ll ans = 0;
  f0r(i, m) f0r(j, m) ans = madd(ans, base.v[i][j]);
  cout << ans << endl;
}