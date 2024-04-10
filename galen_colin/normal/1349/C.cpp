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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

const int dr[4] = {0, 0, -1, 1};
const int dc[4] = {1, -1, 0, 0};
bool mat[1005][1005];
bool vis[1005][1005];
ll turn[1005][1005];

bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

void solve(int tc) {
  ll Q;
  cin >> n >> m >> Q;

  f0r(i, n) {
    cin >> s;
    f0r(j, m) mat[i][j] = s[j] - '0';
  }

  f0r(i, n) f0r(j, m) turn[i][j] = mod * mod;

  queue<pair<pii, pair<ll, bool> > > q;

  ms(vis, 0);

  f0r(i, n) f0r(j, m) {
    f0r(k, 4) {
      ll ni = i + dr[k], nj = j + dc[k];
      if (valid(ni, nj)) {
        if (mat[i][j] == mat[ni][nj]) {
          turn[i][j] = 0;
          q.push(mp(mp(i, j), mp(0, mat[i][j])));
        }
      }
    }
  }

  while (!q.empty()) {
    pair<pii, pair<ll, bool> > x = q.front();
    q.pop();

    pii pos = x.f;
    pair<ll, bool> st = x.s;

    if (vis[pos.f][pos.s]) continue;
    vis[pos.f][pos.s] = 1;

    turn[pos.f][pos.s] = min(turn[pos.f][pos.s], st.f);

    f0r(k, 4) {
      ll ni = pos.f + dr[k], nj = pos.s + dc[k];

      if (valid(ni, nj) && !vis[ni][nj]) {
        pll nst = mp(st.f + 1, !st.s);
        // cout << mp(ni, nj) << " " << nst << endl;
        if (mat[ni][nj] == nst.s) {
          q.push(mp(mp(ni, nj), nst));
        }
      }
    }
  }

  // f0r(i, n) ao(turn[i], m);

  f0r(i, Q) {
    cin >> x >> y >> z; --x; --y;
    ll v = mat[x][y];
    if (z >= turn[x][y]) v ^= (z - turn[x][y]) % 2;
    cout << v << '\n';
  }
}
 
int main() {
  send help
 
  // usaco("file");

  ms(c, 0);
 
  int tc;
  tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}