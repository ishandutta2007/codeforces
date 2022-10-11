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
 
ll sq;
set<pii> degs;
vi edges[200005];
ll deg[100005];

bool vis[100005];
bool anc[100005];

ll dep[100005];
int targ = -1;
vi nseq;
void dfs(int v, int p, int d) {
  if (vis[v]) {
    if (anc[v] && dep[p] - dep[v] + 1 >= sq) {
      targ = v;
    }
    return;
  }
  dep[v] = d;
  vis[v] = 1;
  anc[v] = 1;
  for (int x: edges[v]) {
    dfs(x, v, d + 1);
    if (targ != -1) {
      nseq.pb(v + 1);
      if (v == targ) {
        cout << 2 << endl;
        cout << nseq.size() << endl;
        ao(nseq, nseq.size());
        exit(0);
      }
      return;
    }
  }
  anc[v] = 0;
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> n >> m;
  sq = ceil(sqrt(n)) + 1e-7;
  
  f0r(i, m) {
    cin >> x >> y;
    --x; --y;
    edges[x].pb(y);
    edges[y].pb(x);
    ++deg[x];
    ++deg[y];
  }

  bool t1 = 1;
  if (t1) {
    f0r(i, n) degs.insert(mp(deg[i], i));

    vi qset;

    ms(vis, 0);
    while (degs.size()) {
      pii v = *degs.begin();
      degs.erase(degs.begin());

      if (!vis[v.s]) {
        qset.pb(v.s + 1);
        vis[v.s] = 1;
        for (int x: edges[v.s]) {
          if (!vis[x]) {
            vis[x] = 1;
            for (int y: edges[x]) {
              if (!vis[y]) {
                degs.erase(mp(deg[y], y));
                --deg[y];
                degs.insert(mp(deg[y], y));
              }
            }
          }
        }
      }
    }

    if (qset.size() >= sq) {
      cout << 1 << endl;
      ao(qset, sq);
      exit(0);
    }

    if (n <= 16) {
      f0r(i, (1 << n)) {
        bool v[n];
        ms(v, 0);

        bool f = 1;
        f0r(j, n) {
          if (i & (1 << j)) {
            if (v[j]) {
              f = 0;
              break;
            } else {
              v[j] = 1;
              for (int x: edges[j]) v[x] = 1;
            }
          }
        }

        int c = __builtin_popcount(i);
        if (f && c >= sq) {
          cout << 1 << endl;
          f0r(j, n) if (c > 0 && (i & (1 << j))) {
            cout << j + 1 << " ";
            --c;
          }
          cout << endl;
          exit(0);
        }
      }
    }
  }

  iota(a, a + n, 0);
  f0r(i, n) {
    int j = (rng() % (n - i)) + i;
    swap(a[i], a[j]);
  }

  f0r(i, n) {
    f0r(j, n) dep[j] = mod;
    ms(vis, 0);
    int v = a[i];
    dfs(v, -1, 0);
  }
}