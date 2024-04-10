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

  int n, m, k;
  cin >> n >> m >> k;
  vector<string> pats(n);
  unordered_map<string,int> remap;
  for(int i=0; i<n; i++) {
    cin >> pats[i];
    remap[pats[i]] = i;
  }

  vector<vector<int>> adj(n);
  vector<int> deg(n);

  vector<string> strs(m);
  vector<int> want(m);
  for(int i=0; i<m; i++) {
    cin >> strs[i] >> want[i];
    want[i]--;
    vector<int> match;
    for(int bm=0; bm<1<<k; bm++) {
      string tmp = strs[i];
      for(int j=0; j<k; j++) {
        if(bm & 1<<j) tmp[j] = '_';
      }
      if(remap.count(tmp)) {
        match.push_back(remap[tmp]);
      }
    }
    if(find(match.begin(), match.end(), want[i]) == match.end()) {
      cout << "NO" << nl;
      cerr << "wrong match @ " << i << nl;
      return 0;
    }
    for(int j : match) {
      if(j != want[i]) {
        adj[want[i]].push_back(j);
        deg[j]++;
      }
    }
  }

  queue<int> bfs;
  for(int i=0; i<n; i++) {
    if(deg[i] == 0) {
      bfs.push(i);
    }
  }
  vector<int> order;
  while(!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();
    order.push_back(u);
    for(int v : adj[u]) {
      if(--deg[v] == 0) {
        bfs.push(v);
      }
    }
  }

  if(order.size() < n) {
    cout << "NO" << nl;
    cerr << "not a dag" << nl;
    return 0;
  }

  cout << "YES" << nl;
  for(int it : order) {
    cout << it + 1 << " ";
  }
  cout << nl;

  return 0;
}