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
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
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
 
// mt19937 rng(steady_clock::now().time_since_epoch().count());
mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
void cyc(ll pos) {
  b[pos + 1] = a[pos];
  b[pos + 2] = a[pos + 1];
  b[pos] = a[pos + 2];
  f1r(i, pos, pos + 3) a[i] = b[i];
}
 
void solve(int tc) {
  cin >> n;
  ai(a, n);
 
  vl ops;
 
  f0r(i, n + 5) {
    if (i == n + 1) {
      ll p = -1;
      f1r(i, 3, n - 1) if (a[i] == a[i + 1]) {
        p = i;
        break;
      }
      if (p != -1) {
        --p;
        while (p >= 3) {
          f0r(i, 2) {
            ops.pb(p + 1);
            cyc(p);
          }
          --p;
        }
        f0r(i, 2) {
          ops.pb(2);
          cyc(1);
        }
        f0r(i, 2) {
          ops.pb(3);
          cyc(2);
        }
        p = 3;
        while (p + 2 < n) {
          if (a[p + 1] <= a[p + 2]) break;
          ops.pb(p + 1);
          cyc(p);
          ++p;
        }
      } else {
        if (n > 3) {
          f0r(i, 3) if (a[i] == a[3]) {
            // cout << i << endl;
            f0r(j, 2 - i) {
              ops.pb(1);
              cyc(0);
            }

            f0r(i, 2) {
              ops.pb(1);
              cyc(0);
              // ao(a, n);
            }

            f0r(i, 2) {
              ops.pb(2);
              cyc(1);
              // ao(a, n);
            }

            break;
          }
        }
      }
    }
    ll wpos = -1;
    f0rd(j, n - 2) {
      if (a[j] > a[j + 1]) {
        if (wpos == -1 || a[j] > a[wpos]) wpos = j;
      }
    }
    if (wpos == -1) break;
 
    ll st = wpos - 1;
    if (st == -1) {
      ops.pb(1);
      cyc(0);
      st = 0;
      // ao(a, n);
    }
    while (st + 1 < n - 1) {
      if (a[st + 1] <= a[st + 2]) break;
      ops.pb(st + 1);
      cyc(st);
      ++st;
      // ao(a, n);
    }
    // cout << wpos << endl;
    // ao(a, n);
  }
  
  if (vsz(ops) > n * n) {
    cout << -1 << '\n';
    return;
  }
  bool is = 1;
  f0r(i, n - 1) if (a[i] > a[i + 1]) is = 0;
  if (!is) {
    cout << -1 << '\n';
  } else {
    cout << ops.size() << '\n';
    ao(ops, ops.size());
  }
}
 
int main() {
  send help
 
  // usaco("cowland");
 
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}