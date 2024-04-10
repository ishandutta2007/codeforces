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
#define ain(a, lb, rb) for (int i = lb; i <= rb; i++) cin >> a[i];
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
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[10000006]; 
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
 
ll n, m, q, Q, T, k, l, r, x, y, z, g;
string s;
int a[1000005], b[1000005];
pii ob[1000005];
vi locs;

bool vfy() {
  int pt = 0;
  f0r(i, 2000000) {
    pt += k;
    if (pt >= locs.size()) return true;
    if (locs[pt] <= i) return false;
  }
  return true;
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> m >> k;
  ain(a, 0, n-1);
  ain(b, 0, m-1);
  f0r(i, m) {ob[i].f = b[i]; ob[i].s = i + 1;}
  sort(a, a+n);
  sort(ob, ob+m);
  f0r(i, m) b[i] = ob[i].f;
  int l = 0, r = m - 1;
  while (l <= r) {
    int mi = (l + r) / 2;

    locs.clear();
    int npt = 0, mpt = mi;
    while (npt < n && mpt < m) {
      if (a[npt] <= b[mpt]) {
        locs.pb(a[npt++]);
      } else {
        locs.pb(b[mpt++]);
      }
    }
    while (npt < n) locs.pb(a[npt++]);
    while (mpt < m) locs.pb(b[mpt++]);

    if (vfy()) r = mi - 1;
    else l = mi + 1;
  }
  if (m - l == 0) {
    locs.clear();
    f0r(i, n) locs.pb(a[i]);
    cout << vfy() - 1 << endl;
    exit(0);
  }
  cout << m - l << endl;
  f1r(i, l, m) {
    if (i - (l)) cout << " ";
    cout << ob[i].s;
  }
  cout << endl;
}

/* sort m array use binary search use mergesort things */