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
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;



ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

void ask(int i1, int i2) {
  i1 %= n;
  i2 %= n;

  cout << "? " << (i1 + 1) << endl;
  cin >> x;
  cout << "? " << (i2 + 1) << endl;
  cin >> y;
  if (x == y) {
    cout << "! " << (i1 + 1) << endl;
    exit(0);
  }
  a[i1] = x;
  a[i2] = y;
}

pii isect(pii a, pii b) {
  pii c = mp(min(a.f, a.s), max(a.f, a.s));
  pii d = mp(min(b.f, b.s), max(b.f, b.s));
  return mp(max(c.f, d.f), min(c.s, d.s));
}

bool valid(pii a, pii b) {
  if (a.f > a.s) {
    swap(a.f, a.s);
    swap(b.f, b.s);
  }

  pii r = isect(a, b);
  if (b.f >= b.s) {
    return (r.f <= r.s);
  } else {
    if (r.f > r.s) return false;
    pii c = mp(min(a.f, a.s), max(a.f, a.s));
    pii d = mp(min(b.f, b.s), max(b.f, b.s));
    return (r == c || r == d);
  }
}

ll& get(int i) {
  if (a[i] == mod) ask(i, (i + n / 2) % n);
  return a[i % n];
}

void solve(pii i, int d) {
  if (get(i.f) == mod) ask(i.f, (i.f + n / 2) % n);
  if (get(i.s) == mod) ask(i.s, (i.s + n / 2) % n);
  if (i.f == i.s) return;
  int m1 = ((i.f + i.s) / 2) % n;
  int m2 = (m1 + n / 2) % n;
  int if2 = (i.f + n / 2) % n;
  int is2 = (i.s + n / 2) % n;

  ask(m1, m2);
  pii t1 = mp(get(is2), get(m2)), t2 = mp(get(i.s), get(m1));
  pii s1 = mp(get(i.f), get(m1)), s2 = mp(get(if2), get(m2));
  // cout << t1 << " " << t2 << " " << s1 << " " << s2 << endl;
  if (valid(t1, t2)) solve(mp(m1 + 1, i.s), d + 1);
  else if (valid(s1, s2)) solve(mp(i.f, m1), d + 1);
  else {
    //timeout
    // ll x = 50;
    // f0r(i, 100) {
    //   x *= i;
    //   cout << x << endl;
    //   f0r(j, i * i * i * i * i) {
    //     cout << ++x << endl;
    //   }
    // }
  }
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n;

  if ((n / 2) % 2 != 0) {
    cout << "! -1" << endl;
    exit(0);
  }

  f0r(i, n) a[i] = mod;
  pii lint = mp(0, n / 2);
  solve(mp(0, n / 2 - 1), 0);
}