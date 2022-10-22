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

  int n;
  cin >> n;
  vector<int> a(n), c(n);
  vector<pair<int,int>> order;
  ll ans = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i] >> c[i];
    ans += c[i];
    order.emplace_back(a[i], i);
  }
  sort(begin(order), end(order));

  vector<ll> dp(n, INF);
  dp[0] = 0;
  multiset<ll> free, line;
  set<pair<ll,int>> rem;
  rem.insert(pair(order[0].first + c[order[0].second], 0));
  free.insert(0);
  for(int j=1; j<n; j++) {
    int i = order[j].second;
    while(!rem.empty() && begin(rem)->first < a[i]) {
      int k = begin(rem)->second;
      line.insert(dp[k] - a[order[k].second] - c[order[k].second]);
      free.erase(free.find(dp[k]));
      rem.erase(begin(rem));
    }
    if(!free.empty()) {
      dp[j] = min(dp[j], *free.begin());
    }
    if(!line.empty()) {
      dp[j] = min(dp[j], *line.begin() + a[i]);
    }
    assert(dp[j] >= 0);
    free.insert(dp[j]);
    rem.insert(pair(a[i] + c[i], j));
  }
  cout << ans + dp[n-1] << nl;

  return 0;
}