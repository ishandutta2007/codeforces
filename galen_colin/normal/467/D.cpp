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
const ll mod = 1000000007;
// const ll mod = 998244353;

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

string ss[100005];
vi edges[200005];
pii stats[200005];
set<string> sos;
map<string, int> rev;
pair<string, string> rep[100005];
pii stor[200005];
bool vis[200005];
int ord[200005];
int cnum = 0;

int targ = -1;
pii dfs(int x) {
  if (stor[x] != mp(-1, -1)) return stor[x];
  if (vis[x]) return stats[x];
  vis[x] = 1;
  ord[cnum++] = x;

  pii y = stats[x];

  for (int z: edges[x]) y = min(y, dfs(z));

  return y;
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> m;
  ai(ss, m);
  f0r(i, m) f0r(j, ss[i].length()) ss[i][j] = tolower(ss[i][j]);
  cin >> n;
  f0r(i, n) {
    cin >> s >> t;
    f0r(j, s.length()) s[j] = tolower(s[j]);
    f0r(j, t.length()) t[j] = tolower(t[j]);
    sos.insert(s);
    sos.insert(t);
    rep[i] = mp(s, t);
  }

  int c = 0;
  for (string x: sos) rev[x] = c++;
  f0r(i, n) {
    int a = rev[rep[i].f], b = rev[rep[i].s];

    edges[a].pb(b);

    int c = 0;
    f0r(j, rep[i].f.length()) if (rep[i].f[j] == 'r') c++;
    stats[a] = mp(c, rep[i].f.length());
    c = 0;
    f0r(j, rep[i].s.length()) if (rep[i].s[j] == 'r') c++;
    stats[b] = mp(c, rep[i].s.length());
  }

  f0r(i, 200005) stor[i] = mp(-1, -1);

  ms(vis, 0);

  ll alen = 0;
  iota(b, b + m, 0LL);
  f0r(i, m) swap(b[i], b[i + rng() % (m - i)]);
  f0r(i, m) {
    int x = b[i];

    if (rev.find(ss[x]) == rev.end()) {
      int c = 0;
      f0r(i, ss[x].length()) if (ss[x][i] == 'r') ++c;
      ans += c;
      alen += ss[x].length();
      continue;
    }

    int z = rev[ss[x]];

    cnum = 0;
    pii y = dfs(z);
    f0r(i, cnum) vis[ord[i]] = 0;

    stor[z] = y;
    ans += y.f;
    alen += y.s;
  }

  cout << ans << " " << alen << endl;
}