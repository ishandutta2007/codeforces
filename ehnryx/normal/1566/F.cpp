#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
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

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;

    vector<ll> ev;
    map<ll, ll> match;
    set<ll> is_point;
    vector<int> pts(n);
    for(int i=0; i<n; i++) {
      cin >> pts[i];
      ev.push_back(pts[i]);
      is_point.insert(pts[i]);
    }
    vector<pair<int, int>> segs(m);
    for(int i=0; i<m; i++) {
      cin >> segs[i].first >> segs[i].second;
      ev.push_back(segs[i].first);
      ev.push_back(segs[i].second);
      if(match.count(segs[i].first)) {
        match[segs[i].first] = min(match[segs[i].first], (ll)segs[i].second);
      } else {
        match[segs[i].first] = segs[i].second;
      }
    }

    ev.push_back(-INFLL); // start
    ev.push_back(INFLL); // end
    is_point.insert(-INFLL);
    is_point.insert(INFLL);
    match[-INFLL] = -INFLL;
    match[INFLL] = INFLL;

    sort(begin(ev), end(ev));
    ev.resize(unique(begin(ev), end(ev)) - begin(ev));

    int len = size(ev);
    map<ll, int> remap;
    for(int i=0; i<len; i++) {
      remap[ev[i]] = i;
    }

    vector<int> s(len);
    for(int i=len-1, to=len, last=len; i>=0; i--) {
      s[i] = min(to, last);
      if(match.count(ev[i])) {
        to = min(to, remap[match[ev[i]]]);
      }
      if(is_point.count(ev[i])) {
        last = i;
      }
    }

    vector<int> d(len);
    for(int i=0, to=-1; i<len; i++) {
      if(is_point.count(ev[i])) {
        to = remap[ev[i]];
      }
      d[i] = to;
    }

    vector<ll> dp(len, 0);
    vector<ll> pa(len, INFLL), pb(len, INFLL);;
    pa[0] = 0 - ev[s[0]];
    pb[0] = 0 - 2*ev[s[0]];
    for(int i=1; i<len; i++) {
      pa[i] = pa[i-1];
      pb[i] = pb[i-1];
      if(d[i] <= 0) continue; // can't
      dp[i] = min(pa[d[i] - 1] + 2*ev[i] - ev[d[i]], pb[d[i] - 1] + ev[i] + ev[d[i]]);
      if(s[i] < len) {
        pa[i] = min(pa[i], dp[i] - ev[s[i]]);
        pb[i] = min(pb[i], dp[i] - 2*ev[s[i]]);
      }
    }
    cout << dp[len - 1] << nl;
  }

  return 0;
}