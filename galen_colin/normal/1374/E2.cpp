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

vl cnts[2][2];
vl sums[2][2];
vpl byv[2][2];

ll gsum(ll a, ll b, ll l, ll r) {
  if (sums[a][b].size() == 0 || l > r) return 0;
  ll s = sums[a][b][r];
  if (l > 0) s -= sums[a][b][l - 1];
  return s;
}

ll getge(ll a, ll b, ll val) {
  ll l = 0, r = cnts[a][b].size();
  while (l < r) {
    ll m = (l + r) / 2;

    if (cnts[a][b][m] > val) r = m;
    else l = m + 1;
  }
  return l - 1;
}

const ll mx = 3e4;
ll findk(ll c0, ll c1) {
  ll l = 0, r = mx;
  while (l < r) {
    ll mi = (l + r) / 2;

    ll v1 = max(c1, getge(0, 1, mi) + 1);
    ll v2 = max(c1, getge(1, 0, mi) + 1);
    ll v3 = max(c0, getge(1, 1, mi) + 1);
    ll v4 = getge(0, 0, mi) + 1;
    // cout << mi << " " << v1 << " " << v2 << " " << v3 << " " << v4 << endl;

    if (v1 + v2 + v3 + v4 < m) l = mi + 1;
    else r = mi;
  }
  return l;
}

ll gunder(ll c0, ll c1, ll k) {
  ll cur = c0 + c1 * 2;
  ll s = 0;
  f0r(i, 2) f0r(j, 2) {
    ll v = getge(i, j, k);
    ll mn = 0;
    if (i ^ j) mn = c1;
    else if (i && j) mn = c0;
    if (v >= mn) {
      s += gsum(i, j, mn, v);
      cur += v - mn + 1;
    }
  }
  s -= max(0LL, cur - m) * k;
  return s;
}

void solve(int tc) {
  cin >> n >> m >> k;

  f0r(i, n) {
    cin >> x >> y >> z;
    cnts[y][z].pb(x);
    byv[y][z].pb(mp(x, i + 1));
  }

  f0r(i, 2) f0r(j, 2) {
    sort(all(cnts[i][j]));
    sort(all(byv[i][j]));
  }

  f0r(i, 2) f0r(j, 2) {
    ll run = 0;
    for (ll x: cnts[i][j]) {
      run += x;
      sums[i][j].pb(run);
    }
  }

  ll ans = mod * mod;
  pll best = mp(-1, -1);
  
  ll mx1 = min(cnts[0][1].size(), cnts[1][0].size());
  ll mx2 = cnts[1][1].size();

  ll pt = mx1 - 1;
  ll run = gsum(0, 1, 0, mx1 - 1) + gsum(1, 0, 0, mx1 - 1);
  while (pt >= 0 && ((pt + 1) * 2 > m || pt + 1 > k)) {
    run -= cnts[0][1][pt] + cnts[1][0][pt];
    --pt;
  }

  // vl cancer;

  f0r(i, mx2 + 1) {
    ll v = findk(i, pt + 1);

    ll rest = gunder(i, pt + 1, v);

    // if (m == 164121 && k == 10220) {
    //   cancer.pb(run + rest);
    // }

    ll cv = run + rest;

    if (v < mx && i + (pt + 1) >= k && i + 2 * (pt + 1) <= m && cv < ans) {
      ans = cv;
      best = mp(i, pt + 1);
    }

    if (i == mx2) break;
    run += cnts[1][1][i];
    while (pt >= 0 && ((pt + 1) * 2 + (i + 1) > m || (i + 1) + (pt + 1) > k)) {
      run -= cnts[0][1][pt] + cnts[1][0][pt];
      --pt;
    }
  }

  if (ans == mod * mod) {
    cout << -1 << '\n';
    return;
  }

  // cout << ans << '\n';
  vl take;

  ll ct = 0, cn = 0;;
  f0r(i, best.s) {
    ct += 2;
    take.pb(byv[0][1][i].s);
    take.pb(byv[1][0][i].s);
    cn += byv[0][1][i].f + byv[1][0][i].f;
    // cout << byv[1][0][i] << endl;
  }

  f0r(i, best.f) {
    ++ct;
    take.pb(byv[1][1][i].s);
    cn += byv[1][1][i].f;
  }

  ll v = findk(best.f, best.s);
  // cout << v << endl;
  f0r(i, 2) f0r(j, 2) {
    ll ov = getge(i, j, v);
    // cout << i << " " << j << " " << byv[i][j] << endl;
    ll st = 0;
    if (i ^ j) st = best.s;
    else if (i && j) st = best.f;
    f1r(k, st, ov + 1) {
      if (ct >= m) break;
      if (byv[i][j][k].f < v) {
        ++ct;
        take.pb(byv[i][j][k].s);
        cn += byv[i][j][k].f;
      }
    }
  }

  f0r(i, 2) f0r(j, 2) {
    ll ov = getge(i, j, v);
    // cout << i << " " << j << " " << byv[i][j] << endl;
    ll st = 0;
    if (i ^ j) st = best.s;
    else if (i && j) st = best.f;
    f1r(k, st, ov + 1) {
      if (ct >= m) break;
      if (byv[i][j][k].f == v) {
        ++ct;
        take.pb(byv[i][j][k].s);
        cn += byv[i][j][k].f;
      }
    }
  }

  cout << cn << '\n';

  // sort(all(cancer));
  // if (m == 164121 && k == 10220) {
  //   cout << cancer << endl;
  // }

  // cout << take << endl;
  ao(take, m);
}
 
int main() {
  send help
 
  // usaco("cowland");
 
  int tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}