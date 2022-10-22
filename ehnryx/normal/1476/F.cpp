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

struct SegmentTree {
  int N;
  vector<int> st;
  SegmentTree(int n) {
    N = 1 << (32 - __builtin_clz(n));
    st.resize(2*N);
  }
  void insert(int i, int v) {
    st[i+=N] = v;
    for(i/=2; i; i/=2) {
      st[i] = max(st[2*i], st[2*i+1]);
    }
  }
  int query(int l, int r) {
    int res = 0;
    for(l+=N, r+=N; l<r; l/=2, r/=2) {
      if(l&1) res = max(res, st[l++]);
      if(r&1) res = max(res, st[--r]);
    }
    return res;
  }
};

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
    SegmentTree st(n);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) {
      cin >> v[i];
      if(v[i]) {
        st.insert(i, i + v[i]);
      }
    }

    vector<int> dp(n+1), pre(n+1);
    vector<char> put(n+1);
    set<pair<int,int>> have;
    have.insert(pair(0, 0));
    for(int i=1; i<=n; i++) {
      // right
      auto [dpr, r] = *have.rbegin();
      if(dpr >= i) {
        dp[i] = max(dpr, i + v[i]);
        pre[i] = r;
        put[i] = 'R';
      }
      // left
      auto jt = have.lower_bound(pair(i-v[i]-1, 0));
      if(jt != have.end()) {
        auto [dpj, j] = *jt;
        int rb = max(i-1, max(dpj, st.query(j+1, i)));
        if(rb > dp[i]) {
          dp[i] = rb;
          pre[i] = j;
          put[i] = 'L';
        }
      }
      // add
      have.insert(pair(dp[i], i));
    }

    if(dp[n] < n) {
      cout << "NO" << nl;
    } else {
      string ans(n, 'R');
      for(int i=n; i>0; i=pre[i]) {
        ans[i-1] = put[i];
      }
      cout << "YES" << nl;
      cout << ans << nl;
    }
  }

  return 0;
}