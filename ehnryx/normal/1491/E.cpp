#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
bool fib[N];
unordered_set<int> adj[N];

int dfs(int u, int p, vector<int>& idx, vector<int>& par, vector<int>& sz) {
  int id = idx.size();
  idx.push_back(u);
  par.push_back(p);
  sz.push_back(1);
  for(int v : adj[u]) {
    if(v == p) continue;
    sz[id] += dfs(v, u, idx, par, sz);
  }
  return sz[id];
}

bool solve(int u, int expect) {
  vector<int> idx, par, sz;
  int s = dfs(u, 0, idx, par, sz);
  //assert(s == expect);
  if(s == 1) return true;
  for(int i=1; i<idx.size(); i++) {
    if(fib[sz[i]] && fib[s-sz[i]]) {
      vector<int> _idx, _par, _sz;
      assert(dfs(idx[i], 0, _idx, _par, _sz) == s);
      adj[idx[i]].erase(par[i]);
      adj[par[i]].erase(idx[i]);
      //assert(dfs(idx[i], 0, _idx, _par, _sz) == sz[i]);
      //assert(dfs(par[i], 0, _idx, _par, _sz) == s-sz[i]);
      if(solve(idx[i], sz[i]) && solve(par[i], s-sz[i])) {
        return true;
      }
      break;
      adj[idx[i]].insert(par[i]);
      adj[par[i]].insert(idx[i]);
    }
  }
  return false;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  for(int a=0, b=1; a+b<N; ) {
    //cerr << a+b << nl;
    fib[a+b] = true;
    a += b;
    swap(a, b);
  }

  int n;
  cin >> n;
  if(!fib[n]) {
    cout << "NO" << nl;
    return 0;
  }

  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  if(solve(1, n)) {
    cout << "YES" << nl;
  } else {
    cout << "NO" << nl;
  }

  return 0;
}