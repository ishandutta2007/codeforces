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

struct Segment {
  int len, start;
  Segment(int l, int s): len(l), start(s) {}
  bool operator < (const Segment& o) const {
    if(len != o.len) return len < o.len;
    return start > o.start;
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
    vector<int> ans(n);
    priority_queue<Segment> segs;
    segs.emplace(n, 0);
    for(int i=1; i<=n; i++) {
      auto [len, s] = segs.top();
      segs.pop();
      int t = s + (len-1) / 2;
      ans[t] = i;
      if(t > s) {
        segs.emplace(t-s, s);
      }
      if(s + len-1 > t) {
        segs.emplace(s + len-1 - t, t + 1);
      }
    }
    for(int i=0; i<n; i++) {
      cout << ans[i] << " ";
    }
    cout << nl;
  }

  return 0;
}