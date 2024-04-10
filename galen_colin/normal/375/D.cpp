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
// const ll mod = 1000000007;
const ll mod = 998244353;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

vi edges[100005];
int res[100005], sz[100005];
vector<pii> query[100005];
ordered_set<pii>* sets[100005];
map<int, int>* cnt[100005];

void dfs(int x, int p) {
  sz[x] = 1;
  if (edges[x].size() == 1 && x) {
    sets[x] = new ordered_set<pii>();
    cnt[x] = new map<int, int>();
  } else {
    int bigc = -1, bigv = -1;
    for (int y: edges[x]) {
      if (y != p) {
        dfs(y, x);
        sz[x] += sz[y];
        if (sz[y] > bigv) {
          bigv = sz[y];
          bigc = y;
        }
      }
    }

    sets[x] = sets[bigc];
    cnt[x] = cnt[bigc];

    for (int y: edges[x]) {
      if (y != p && y != bigc) {
        for (const pii& z: *cnt[y]) {
          int& v = (*cnt[x])[z.f];
          if (v > 0) {
            sets[x]->erase(mp(v, z.f));
          }
          v += z.s;
          sets[x]->insert(mp(v, z.f));
        }
      }
    }
  }

  int& v = (*cnt[x])[a[x]];
  if (v > 0) {
    sets[x]->erase(mp(v, a[x]));
  }
  ++v;
  sets[x]->insert(mp(v, a[x]));

  for (pii& y: query[x]) {
    int v = sets[x]->order_of_key(mp(y.f, -1));
    res[y.s] = sets[x]->size() - v;
  }
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> n >> Q;
  ai(a, n);
  readgraph(edges, n - 1);
  
  f0r(i, Q) {
    cin >> x >> y;
    --x;

    query[x].pb(mp(y, i));
  }

  dfs(0, -1);

  f0r(i, Q) cout << res[i] << '\n';
}