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
#define ai(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define ain(a, lb, rb) for (int i = lb; i <= rb; i++) cin >> a[i];
#define ao(a, n) for (int i = 0; i < n; i++) { if (i) cout << " "; cout << a[i]; } cout << endl;
#define aout(a, lb, rb) for (int i = lb; i <= rb; i++) { if (i > lb) cout << " "; cout << a[i]; } cout << endl;
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
 
const ll mod = 998244353;
 
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
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
// bool prime[10000006]; 
// void sieve(int n) { 
//   f0r(i, n + 1) prime[i] = 1;
//   for (int p = 2; p * p <= n; p++) { 
//     if (prime[p] == true) { 
//       for (int i = p * p; i <= n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
//   prime[1] = prime[0] = 0;
// } 

ll n, m, q, Q, T, k, l, r, x, y, z, g;
ll a[200005];
ll sz[30];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  // ao(sz, 25);
  // f0r(i, 25) cout << sz[i] / 1e15 << " " << (sz[i + 1] / sz[i]) << endl;

  cin >> Q;
  f0r(q, Q) {
    cin >> k;

    ll pt = 0;
    ll base = 0, range = 9;
    f0r(i, 10) {
      sz[i] = base * range + (i + 1) * range * (range + 1) / 2;
      if (i) sz[i] += sz[i - 1];

      if (sz[i] > k) {
        pt = i;
        break;
      }

      base = base + (i + 1) * range;
      range *= 10;
    }

    // cout << "SZ " << (pt ? sz[pt - 1] : 0) << endl;

    k -= (pt ? sz[pt - 1] : 0);

    ll l = 1, r = range;
    ll best = 0;
    while (l <= r) {
      ll m = (l + r) / 2;

      ll num = base * m + (pt + 1) * m * (m + 1) / 2;
      if (num >= k) {
        r = m - 1;     
      } else {
        l = m + 1;
        best = max(best, m);
      }
    }

    ll bnum = base * best + (pt + 1) * best * (best + 1) / 2;

    // cout << "BNUM " << bnum << endl;

    k -= bnum;

    ll opt = 0;
    ll last = 0, cur = 0, orange = 9, sum = 0;
    f0r(i, 20) {
      cur = orange * (i + 1) + last;

      if (cur >= k) {
        opt = i;
        break;
      }

      last = cur;
      sum += orange;
      orange *= 10;
    }

    // cout << "LAST " << last << endl;

    k -= last;

    // cout << "K " << k << endl;

    ll behind = sum + ((k + opt) / (opt + 1)); //this line was the root of all my problems for two hours - orange is not the same as sum
    int rn = (opt + 1) - ((k - 1) % (opt + 1)) - 1;

    // cout << "RN " << rn << endl;
    // cout << "BEHIND " << behind << endl;

    while (rn--) behind /= 10;

    // cout << "BEHIND " << behind << endl;
    
    cout << behind % 10 << endl;
  }
}