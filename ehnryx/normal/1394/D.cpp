//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
int t[N], h[N], par[N];
vector<int> adj[N];

ll dp[N], up[N], ndp[N], nup[N], nbp[N];

void build(int u, int p) {
  par[u] = p;
  if(p) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
  for(int v : adj[u]) {
    build(v, u);
  }
}

ll solve_node(int);
ll solve_node_up(int);
ll solve_node_down(int);

ll solve_down(int u) {
  if(dp[u] != -1) return dp[u];
  if(h[par[u]] > h[u]) return dp[u] = -INF;
  // h[par[u]] <= h[u]
  return dp[u] = max(solve_node(u), solve_node_down(u) + t[u]);
}

ll solve_up(int u) {
  if(up[u] != -1) return up[u];
  if(h[par[u]] < h[u]) return up[u] = -INF;
  // h[par[u]] >= h[u]
  return up[u] = max(solve_node(u), solve_node_up(u) + t[u]);
}

ll solve_node_up(int u) {
  solve_node(u);
  if(nup[u] < 0) nup[u] = -INF;
  return nup[u];
}

ll solve_node_down(int u) {
  solve_node(u);
  if(ndp[u] < 0) ndp[u] = -INF;
  return ndp[u];
}

ll solve_node(int u) {
  if(nbp[u] != -1) return nbp[u];

  vector<ll> inits(2);
  vector<vector<ll>> values(2);
  for(int v : adj[u]) {
    ll upval = solve_up(v);
    ll downval = solve_down(v);
    assert(max(upval, downval) >= 0);
    inits[0] += downval;
    values[0].push_back(upval - downval);
    inits[1] += upval;
    values[1].push_back(downval - upval);
  }

  for(int bs=0; bs<2; bs++) {
    vector<ll>& val = values[bs];
    ll& init = inits[bs];

    sort(val.begin(), val.end());

    ll res = 0;
    for(int l=0, r=(int)val.size()-1; l<r && val[r]+t[u]>0; r--, l++) {
      res += val[r] + t[u];
    }
    nbp[u] = max(nbp[u], init + res);

    if(!val.empty()) {
      res = val.back() * (bs == 0);
      for(int l=0+bs, r=(int)val.size()-2+bs; l<r && val[r]+t[u]>0; r--, l++) {
        res += val[r] + t[u];
      }
      nup[u] = max(nup[u], init + res);

      res = val.front() * (bs == 1);
      for(int l=1-bs, r=(int)val.size()-1-bs; l<r && val[r]+t[u]>0; r--, l++) {
        res += val[r] + t[u];
      }
      ndp[u] = max(ndp[u], init + res);
    }
  }

  return nbp[u];
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> t[i];
  }
  for(int i=1; i<=n; i++) {
    cin >> h[i];
  }

  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ll init = 0;
  for(int i=1; i<=n; i++) {
    init += t[i] * adj[i].size();
    //cerr<<"@ "<<i<<" "<<t[i]<<" * "<<adj[i].size()<<nl;
  }

  build(1, 0);

  memset(dp, -1, sizeof dp);
  memset(up, -1, sizeof up);
  memset(ndp, -1, sizeof ndp);
  memset(nup, -1, sizeof nup);
  memset(nbp, -1, sizeof nbp);
  ll ans = init - solve_node(1);
  cout << ans << nl;

  return 0;
}