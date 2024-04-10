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
 
#define f0r(a, b) for (long long a = 0; a < (b); a++)
#define f1r(a, b, c) for (long long a = (b); a < (c); a++)
#define f0rd(a, b) for (long long a = (b); a >= 0; a--)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
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
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
 
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
    maxn = n;
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
 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
const int nh = 4;
string_hash sh[2][nh];
 
int mx[1000005];
int rmx[1000005];
 
bool ipal(int l, int r) {
  if (l == r) return 1;
  int m = (l + r) / 2;
  int lm = m, rm = m;
  if ((r - l + 1) % 2 == 1) {
    --lm;
    ++rm;
  } else {
    ++rm;
  }
  r = n - 1 - r;
  rm = n - 1 - rm;
  // cout << l << " " << r << " " << lm << " " << rm << endl;
 
  bool f = 1;
  f0r(i, nh) {
    f &= (sh[0][i].get_hash(l, lm) == sh[1][i].get_hash(r, rm));
    if (!f) break;
  }
  return f;
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
  
  cin >> Q;
  f0r(q, Q) {
    cin >> s;
    n = s.length();
    sh[0][0].init(n, s, kk[2], primes[9]);
    sh[0][1].init(n, s, kk[6], primes[8]);
    sh[0][2].init(n, s, kk[3], primes[6]);
    sh[0][3].init(n, s, kk[9], primes[3]);
    reverse(all(s));
    sh[1][0].init(n, s, kk[2], primes[9]);
    sh[1][1].init(n, s, kk[6], primes[8]);
    sh[1][2].init(n, s, kk[3], primes[6]);
    sh[1][3].init(n, s, kk[9], primes[3]);
    reverse(all(s));
 
    ll pt = 0;
    f0rd(i, n - 1) {
      while (!ipal(i, i + pt) || (i < n / 2 && i + pt >= n - i - 1)) --pt;
 
      mx[i] = pt + 1;
      // cout << pt << " " << i << " " << mx[i] << endl;
      pt = min(n - i, pt + 2);
    }
    pt = 0;
    f0r(i, n) {
      while (!ipal(pt, i) || (i >= n / 2 && pt < n - i - 1)) ++pt;
 
      rmx[i] = i - pt + 1;
      pt = max(0LL, pt - 2);
    }

    // ao(mx, n);
    // ao(rmx, n);
 
    int mxl = 1;
    pii vals = mp(1, 0);
 
    /* case: all of one side */
    int l = mx[0];
    if (l > mxl) {
      mxl = l;
      vals = mp(mx[0], 0);
    }
    l = rmx[n - 1];
    if (l > mxl) {
      mxl = l;
      vals = mp(0, rmx[n - 1]);
    }
 
    // ao(mx, n);
    // ao(rmx, n);
 
    f0r(i, n / 2) {
      bool f = 1;
      if (s[i] != s[n - i - 1]) break;
 
      if (f) {
        int j = i;
        int v = 0;
        if (i < n - 1) v = mx[i + 1];
        // cout << i << " " << v << " " << i + v << " " << n - j - 1 << endl;
        if (i + v < n - j - 1) {
          int l = i + v + j + 2;
          if (l > mxl) {
            mxl = l;
            vals = mp(i + v + 1, j + 1);
          }
        }
 
        v = 0;
        if (j < n - 1) v = rmx[n - j - 2];
        if (i < n - j - 1 - v) {
          int l = i + j + v + 2;
          if (l > mxl) {
            mxl = l;
            vals = mp(i + 1, j + v + 1);
          }
        }
 
        int l = i + j + 2;
        if (l > mxl) {
          mxl = l;
          vals = mp(i + 1, j + 1);
        }
 
        // cout << i << " " << j << " " << vals << endl;
      }
    }
 
    string t = "";
    if (vals.f) t += s.substr(0, vals.f);
    if (vals.s) t += s.substr(n - vals.s, vals.s);
    cout << t << '\n';
  }
}