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
  #pragma message("be careful, freopen may be wrong")
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
ll ans = 0;

bool d[301][301][301];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);

  // usaco("file");

  cin >> n;
  ai(a, n);
  if (n == 1) {
    if (a[0] == 0) cout << "BitAryo" << endl;
    else cout << "BitLGM" << endl;
  } else if (n == 2) {
    bool dp[301][301];
    int mn = min(a[0], a[1]);
    // if (mn > 61) {
    //   int fac = (mn - 61) / 2;
    //   a[0] -= 2 * fac;
    //   a[1] -= 2 * fac;
    // }
    ms(dp, 0);
    f0r(i, a[0] + 1) {
      f0r(j, a[1] + 1) {
        if (!i && !j) {
          dp[i][j] = 0;
          continue;
        }
        bool f = 1;
        int mn = min(i, j);
        f1r(fac, 1, mn + 1) {
          f &= dp[i - fac][j - fac];
        }
        f0r(fac, i) f &= dp[fac][j];
        f0r(fac, j) f &= dp[i][fac];
        dp[i][j] = !f;
      }
    }
    cout << (dp[a[0]][a[1]] ? "BitLGM" : "BitAryo") << endl;
  } else if (n == 3) {
    int mn = min(a[0], min(a[1], a[2]));
    if (mn > 103) {
      int fac = (mn - 103) / 2;
      a[0] -= 2 * fac;
      a[1] -= 2 * fac;
      a[2] -= 2 * fac;
    }
    ms(d, 0);
    f0r(i, a[0] + 1) {
      f0r(j, a[1] + 1) {
        f0r(k, a[2] + 1) {
          if (!i && !j && !k) {
            d[i][j][k] = 0;
            continue;
          }
          bool f = 1;
          int mn = min(i, min(j, k));
          f1r(fac, 1, mn + 1) {
            f &= d[i - fac][j - fac][k - fac];
          }
          f0r(fac, i) f &= d[fac][j][k];
          f0r(fac, j) f &= d[i][fac][k];
          f0r(fac, k) f &= d[i][j][fac];
          d[i][j][k] = !f;
        }
      }
    }
    cout << (d[a[0]][a[1]][a[2]] ? "BitLGM" : "BitAryo") << endl;
  }
}