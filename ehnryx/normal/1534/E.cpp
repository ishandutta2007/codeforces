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
random_device _rd; mt19937 rng(_rd());



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

  int n, k;
  cin >> n >> k;

  vector<int> pre(n+1, -1);
  pre[0] = 0;
  queue<int> bfs;
  bfs.push(0);
  while (!empty(bfs)) {
    int u = bfs.front();
    bfs.pop();
    for(int share=0; share<=k; share++) {
      int v = u + k - 2 * share;
      if(share > u || u + k - share > n || pre[v] != -1) continue;
      pre[v] = u;
      bfs.push(v);
    }
  }

  if(pre[n] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  deque<int> have(n);
  iota(begin(have), end(have), 1);
  for(int u=n, cur=1; u>0; u=pre[u]) {
    cout << "? ";
    int share = (pre[u] - u + k) / 2;
    for(int i=0; i<share; i++) {
      cout << have.front() << " ";
      have.pop_front();
    }
    for(int i=0; i<k-share; i++) {
      have.push_back(cur++);
      if(cur > n) cur -= n;
      cout << have.back() << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    ans ^= res;
  }
  cout << "! " << ans << endl;

  return 0;
}