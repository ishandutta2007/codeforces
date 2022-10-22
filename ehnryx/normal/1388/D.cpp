//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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
ll a[N], b[N];
int in[N];

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  for(int i=1; i<=n; i++) {
    cin >> b[i];
    if(b[i] != -1) {
      in[b[i]]++;
    }
  }

  queue<int> bfs;
  for(int i=1; i<=n; i++) {
    if(in[i] == 0) {
      bfs.push(i);
    }
  }

  ll ans = 0;
  vector<int> order, last;
  while(!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();
    order.push_back(u);
    ans += a[u];
    if(b[u] != -1) {
      if(a[u] > 0) {
        a[b[u]] += a[u];
      } else {
        order.pop_back();
        last.push_back(u);
      }
      if(--in[b[u]] == 0) {
        bfs.push(b[u]);
      }
    }
  }
  order.insert(order.end(), last.rbegin(), last.rend());

  cout << ans << nl;
  for(int v : order) {
    cout << v << " ";
  }
  cout << nl;

  return 0;
}