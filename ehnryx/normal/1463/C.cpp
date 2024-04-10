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

int sgn(int x) {
  return x < 0 ? -1 : x > 0 ? 1 : 0;
}

bool in_range(int l, int r, int v) {
  return (l <= v && v <= r) || (r <= v && v <= l);
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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<ll> t(n+1), x(n+1);
    int ans = 0;
    ll lb = 0;
    ll pos = 0;
    int dir = 0;
    for(int i=0; i<=n; i++) {
      if(i < n) {
        cin >> t[i] >> x[i];
      } else {
        t[i] = lb;
      }
      if(i > 0) {
        int len = min(lb, t[i]) - t[i-1];
        int nxt = pos + dir*len;
        ans += in_range(pos, nxt, x[i-1]);
        pos = nxt;
      }
      if(t[i] >= lb) {
        lb = t[i] + abs(x[i] - pos);
        dir = sgn(x[i] - pos);
      }
    }
    cout << ans << nl;
  }

  return 0;
}