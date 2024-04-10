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
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;

using implicit_segtree = struct implicit_segtree;
struct implicit_segtree {
  ll v, sz;
  implicit_segtree* child[2];
 
  implicit_segtree() {
 
  }
 
  implicit_segtree(ll n) {
    v = 0;
    child[0] = nullptr;
    child[1] = nullptr;
    sz = n;
  }
 
  implicit_segtree* ch(int x) {
    if (!child[x]) child[x] = new implicit_segtree(sz);
    return child[x];
  }
 
  void add(ll loc, ll val) {
    add(loc, val, 0, sz - 1);
  }
 
  ll add(ll loc, ll val, ll l, ll r) {
    if (l > loc || r < loc) return v;
    if (l == r) return v = max(v, val);
    ll m = (l + r) / 2;
    ll a = 0, b = 0;
    if (loc <= m) {
      a = ch(0)->add(loc, val, l, m);
      if (child[1]) b = ch(1)->v;
    } else {
      if (child[0]) a = ch(0)->v;
      b = ch(1)->add(loc, val, m + 1, r);
    }
    
    return v = max(a, b);
  }
 
  ll query(ll ql, ll qr) {
    return query(ql, qr, 0, sz - 1);
  }
 
  ll query(ll ql, ll qr, ll tl, ll tr) {
    if (qr < tl || ql > tr || tl > tr) return 0;
    if (ql <= tl && tr <= qr) return v;
    ll a = 0, b = 0, m = (tl + tr) / 2;
    if (child[0]) a = ch(0)->query(ql, qr, tl, m);
    if (child[1]) b = ch(1)->query(ql, qr, m + 1, tr);
    return max(a, b);
  }
};

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

implicit_segtree st;
const ll mx = 1LL << 50;
ll lv[100005];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n >> k;
  st = implicit_segtree(mx);

  ll m = 0;
  f0r(i, n) {
    cin >> a[i];
    x = a[i];
    ll v1 = max(x - k, 0LL);
    ll v2 = min(x + k, mx - 1);
    ll res = st.query(0, v1);
    res = max(res, st.query(v2, mx - 1));
    lv[i] = res + 1;
    st.add(x, lv[i]);
    m = max(m, lv[i]);
  }

  cout << m << endl;
  vi seq;
  ll targ = m, last;
  f0rd(i, n - 1) {
    if (lv[i] == targ) {
      if (targ == m) {
        last = a[i];
      } else {
        if (abs(a[i] - last) < k) continue;
        last = a[i];
      }

      --targ;
      seq.pb(i + 1);
    }
  }

  reverse(all(seq));
  ao(seq, m);
}