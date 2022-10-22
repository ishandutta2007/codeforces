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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> team(n);
    vector<vector<ll>> s(n + 1);
    for(int i=0; i<n; i++) {
      cin >> team[i];
    }
    for(int i=0; i<n; i++) {
      int v;
      cin >> v;
      s[team[i]].push_back(v);
    }

    vector<pair<int,int>> order;
    for(int i=1; i<=n; i++) {
      if(empty(s[i])) continue;
      sort(begin(s[i]), end(s[i]), greater<ll>());
      partial_sum(begin(s[i]), end(s[i]), begin(s[i]));
      order.emplace_back(size(s[i]), i);
    }
    sort(begin(order), end(order));

    vector<ll> ans;
    for(int k=1, j=0; k<=n; k++) {
      while(j < size(order) && order[j].first < k) {
        j++;
      }
      ll cur = 0;
      for(int i=j; i<size(order); i++) {
        const auto& vec = s[order[i].second];
        int num = ((int)size(vec) / k) * k;
        cur += vec[num-1];
      }
      ans.push_back(cur);
    }

    for(ll it : ans) {
      cout << it << " ";
    }
    cout << nl;
  }

  return 0;
}