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

  int n, m;
  cin >> n >> m;

  int same = 0;
  int loop = 0;
  map<pair<int,int>,char> g;
  for(int i=0; i<m; i++) {
    char t;
    cin >> t;
    if(t == '+') {
      int a, b;
      char c;
      cin >> a >> b >> c;
      g[pair(a, b)] = c;
      if(g.count(pair(b, a))) {
        loop++;
        if(g[pair(b, a)] == c) {
          same++;
        }
      }
    } else if(t == '-') {
      int a, b;
      cin >> a >> b;
      if(g.count(pair(b, a))) {
        loop--;
        if(g[pair(b, a)] == g[pair(a, b)]) {
          same--;
        }
      }
      g.erase(pair(a, b));
    } else {
      int k;
      cin >> k;
      if(k % 2 == 0) {
        cout << (same ? "YES" : "NO") << nl;
      } else {
        cout << (loop ? "YES" : "NO") << nl;
      }
    }
  }

  return 0;
}