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

struct string_hash {
  int len;
  ll mod, poly, inv;
  vector<ll> prefix;
  vector<ll> invs;
  
  #pragma message("vector sizes in init need to be huge")
  void init(int n, string s, ll k, ll m, int maxn) {
    mod = m;
    poly = k;
    prefix = vector<ll>(maxn);
    invs = vector<ll>(maxn);

    invs[0] = 1;
    inv = minv(k);
    for (int i = 1; i < n; i++) {
      invs[i] = (invs[i - 1] * inv) % mod;
    }

    ll x = 1;
    prefix[0] = (s[0] - '0' + 1);
    for (int i = 1; i < n; i++) {
      x = (x * k) % mod;
      prefix[i] = (prefix[i - 1] + (x * (s[i] - '0' + 1)) % mod) % mod;
    }

    len = n;
  }

  void extend(string next) {
    int x = next.length();
    for (int i = len; i < len + x; i++) {
      invs[i] = (invs[i - 1] * inv) % mod;
    }

    ll p = mpow(poly, len - 1) % mod;
    for (int i = len; i < len + x; i++) {
      p = (p * poly) % mod;
      prefix[i] = (prefix[i - 1] + (p * (next[i - len] - '0' + 1)) % mod) % mod;
    }

    len += x;
  }

  ll get_hash(int left, int right) {
    if (left < 0 || right >= len) {
      cout << "error: invalid get_hash bounds " << left << " " << right << " (len = " << len << ")" << endl;
      exit(1);
    }
    if (left == 0) return prefix[right];
    return (((prefix[right] - prefix[left - 1] + mod) % mod) * invs[left]) % mod;
  }

  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
      if (exp % 2 == 1) {
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
};

ll n, m, q, Q, T, l, r, y, z, g;
ll a[500005];
ll b[500005];
string s, t;
string x[100005];
string ans = "";
string_hash sh[10], temp[10];

ll k[3] = {
  89, 
  101, 
  (ll)rng() % 16000 + 183
};
ll primes[3] = {
  776531419,
  1000000007,
  1000000009
};

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);

  cin >> n;
  ai(x, n);
  ans = x[0];
  f0r(i, 3) 
    sh[i].init(ans.length(), ans, k[i], primes[i], 1000006);

  f1r(i, 1, n) {
    f0r(j, 3) 
      temp[j].init(x[i].length(), x[i], k[j], primes[j], x[i].length());
    ll mx = 0;
    f0r(j, min(ans.length(), x[i].length())) {
      bool f = 1;
      // cout << ans.length() - j - 1 << " " << ans.length() - 1 << endl;
      f0r(k, 3) {
        // cout << "HASH " << sh[k].get_hash(ans.length() - j - 1, ans.length() - 1) << " " << temp[k].get_hash(0, j) << endl;
        if (sh[k].get_hash(ans.length() - j - 1, ans.length() - 1) != temp[k].get_hash(0, j)) f = 0;
      }
      if (f) mx = max(mx, j + 1);
    }
    string cut = x[i].substr(mx, x[i].length() - mx);
    ans += cut;
    f0r(j, 3) sh[j].extend(cut);
    // cout << ans << endl;
  }
  cout << ans << endl;
}