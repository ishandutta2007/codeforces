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
// ll ans = 0;
 
vi have[1005];
ll pos[1005];
ll res[13];
ll ans[1005];

ll query(vl v) {
  cout << "? " << vsz(v);
  for (ll x: v) cout << " " << x + 1;
  cout << endl;
  cin >> x;
  return x;
}

void solve(int tc) {
  cin >> n >> k;

  ms(pos, 0);

  f0r(i, k) {
    have[i].clear();
    cin >> x;
    f0r(j, x) {
      cin >> y; --y;
      have[i].pb(y);
      pos[y] = i + 1;
    }
  }

  ms(res, 0);
  ms(ans, 0);
  
  vl cur;
  f0r(i, n) cur.pb(i);
  ll mx = query(cur);
  ll val = 0;
  f0r(i, 10) {
    vl cur;
    val += (1 << i);
    f0r(j, n) if ((pos[j] & val) == val) cur.pb(j);
    ll ov = 0;
    if (cur.size()) ov = query(cur);
    if (ov != mx) val -= (1 << i);
  }

  ll rem;
  cur.clear();
  f0r(i, n) {
    if (pos[i] != val) cur.pb(i);
  }
  rem = query(cur);

  f0r(i, k) ans[i] = ((i + 1 == val) ? rem : mx);
  cout << "!";
  f0r(i, k) cout << " " << ans[i];
  cout << endl;

  cin >> s;
  if (s == "Incorrect") exit(0);
}
 
int main() {
  send help
 
  // usaco("cowland");
 
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}