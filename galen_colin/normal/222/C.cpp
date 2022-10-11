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
// const ll mod = 1e9 + 7;
ll mod;
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
 
ll n, q, Q, T, m, k, r, x, y, z, g;
int a[100001], b[100001];
int mk[10000006];
vi primes;
vi locs[670000];
vi olocs[670000];
int cnt[670000];
int ocnt[670000];
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  sieve(1e7);
  ms(cnt, 0);
  ms(ocnt, 0);
  ms(mk, 0);
  cin >> n >> m;
  f0r(i, n) cin >> a[i];
  f0r(i, m) cin >> b[i];
  int x = 0;
  f0r(i, 1e7) {
    if (prime[i]) {
      mk[i] = x++;
      primes.pb(i);
    }
  }
  f0r(i, 670000) locs[i].pb(-1);
  f0r(i, 670000) olocs[i].pb(-1);
  f0r(i, n) {
    int x = a[i];
    for (int j = 0; primes[j] <= x; j++) {
      while (x % primes[j] == 0) {
        x /= primes[j];
        cnt[j]++;
        locs[j].pb(i);
      }
      if (prime[x]) {
        cnt[mk[x]]++;
        locs[mk[x]].pb(i);
        break;
      }
    }
  }
  f0r(i, m) {
    int x = b[i];
    for (int j = 0; primes[j] <= x; j++) {
      while (x % primes[j] == 0) {
        x /= primes[j];
        ocnt[j]++;
        olocs[j].pb(i);
      }
      if (prime[x]) {
        ocnt[mk[x]]++;
        olocs[mk[x]].pb(i);
        break;
      }
    }
  }
  f0r(i, 670000) {
    int pt = 1;
    while (pt - 1 < cnt[i] && pt - 1 < ocnt[i]) {
      a[locs[i][pt]] /= primes[i];
      b[olocs[i][pt]] /= primes[i];
      pt++;
    }
  }
  cout << n << " " << m << endl;
  f0r(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  f0r(i, m) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
}