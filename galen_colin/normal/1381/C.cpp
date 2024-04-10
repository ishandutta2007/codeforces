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



ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;



void solve(int tc) {
  cin >> n >> x >> y;
  ai(a, n);
  f0r(i, n) --a[i];

  vl byc[n + 1];
  bool has[n + 1];
  ms(has, 0);
  f0r(i, n) has[a[i]] = 1;

  ll targ = -1;
  f0r(i, n + 1) if (!has[i]) targ = i;

  f0r(i, n) b[i] = -1;

  pll cnt[n + 1];
  f0r(i, n) {
    byc[a[i]].pb(i);
  }
  f0r(i, n + 1) cnt[i] = mp(byc[i].size(), i);

  sort(cnt, cnt + (n + 1));
  set<pll> vals;

  ll rem = y - x;

  ll cur = 0;
  f0r(i, n + 1) if (cnt[i].f > 0) {
    vals.insert(cnt[i]);
    cur += cnt[i].f;

    // if (cur >= y && min(cur - x, 2 * (cur - cnt[i].f + x)) >= rem && (rem != 1 || cur - x != 1)) break;
  }

  f0r(i, x) {
    if (!vals.size()) {
      cout << "NO\n";
      return;
    }
    auto it = --vals.end();

    pll v = *it;
    vals.erase(it);
    --v.f;
    if (v.f > 0) vals.insert(v);

    ll pos = byc[v.s].back();
    byc[v.s].pop_back();
    b[pos] = v.s;
  }

  if (rem > 0) {
    ll msz = (--vals.end())->f;

    ll cx = cur - x;

    ll pos[cx];

    ll pt = 0;
    for (pll x: vals) {
      f0r(i, x.f) {
        pos[pt] = x.s;
        ++pt;
      }
    }

    f0r(i, rem) {
      ll c = pos[(i + msz) % cx];
      ll vp = byc[c].back();
      byc[c].pop_back();
      b[vp] = pos[i];
    }
  }
  
  f0r(i, n) if (b[i] == -1) b[i] = targ;

  // sanity check
  ll c1 = 0, c2 = 0;
  f0r(i, n) c[i] = b[i];
  f0r(i, n) if (c[i] == a[i]) ++c1;
  
  multiset<ll> mv;
  f0r(i, n) mv.insert(a[i]);
  f0r(i, n) {
    if (mv.find(c[i]) != mv.end()) {
      ++c2;
      mv.erase(mv.find(c[i]));
    }
  }

  if (c1 != x || c2 != y) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  f0r(i, n) ++b[i];
  ao(b, n);
}
 
int main() {
  send help
 
  // usaco("cowland");
 
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}