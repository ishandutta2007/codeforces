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
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
ll kk[10] = {
  89, 
  101, 
  189,
  94,
  621,
  (ll)rng() % 1000 + 101,
  (ll)rng() % 2000 + 121,
  (ll)rng() % 4000 + 141,
  (ll)rng() % 8000 + 161,
  (ll)rng() % 16000 + 183
};

ll primes[10] = {
  533000401,
  735632791,
  776531419,
  797003413,
  817504243,
  920419813,
  961748941, 
  982451653,
  1000000007,
  1000000009
};

struct string_hash {
  int len;
  ll mod, poly, inv;
  vector<ll> prefix;
  vector<ll> invs;
  
  #pragma message("vector sizes in init need to be huge")
  void init(int n, string s, ll k = 89, ll m = 1000000007, int maxn = 1000005) {
    mod = m;
    poly = k;
    prefix = vector<ll>(n);
    invs = vector<ll>(n);

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

    ll p = mpow(poly, len - 1);
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

template<int K>
struct multihash {
  string_hash sh[K];

  void init(int n, string s) {
    for (int i = 0; i < K; i++) {
      sh[i].init(n, s, kk[9 - i], primes[9 - i]);
    }
  }

  vector<ll> get_hash(int l, int r) {
    vector<ll> ret(K);
    for (int i = 0; i < K; i++) {
      ret[i] = sh[i].get_hash(l, r);
    }
    return ret;
  }

  bool compare(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < K; i++) {
      if (a[i] != b[i]) return 0;
    }
    return 1;
  }
};
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

multihash<3> mh;

void solve(int tc) {
  cin >> s >> t;

  ll c[2] = {0};
  f0r(i, s.length()) ++c[s[i] - '0'];

  mh.init(t.length(), t);

  int best = 0;
  f0r(i, t.length() - 1) if (mh.compare(mh.get_hash(0, i), mh.get_hash(t.length() - 1 - i, t.length() - 1))) best = i + 1;

  string res;
  int pt = 0;
  f0r(i, s.length()) {
    int x = t[pt] - '0';
    if (!c[x]) x ^= 1;
    res.pb(x + '0');
    --c[x];
    pt++;
    if (pt >= t.length()) pt = best;
  }

  cout << res << '\n';
}
 
int main() {
  send help
 
  // usaco("file");
 
  int tc;
  tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}