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

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }

    unordered_set<ll> have;
    vector<vector<int>> all(1, a);
    while(!all.empty()) {
      vector<vector<int>> nxt;
      for(vector<int>& v : all) {
        have.insert(accumulate(v.begin(), v.end(), (ll)0));
        int hi = *max_element(v.begin(), v.end());
        int lo = *min_element(v.begin(), v.end());
        if(hi == lo) continue;
        auto it = stable_partition(v.begin(), v.end(), [=](int x) {
          return x <= (hi + lo) / 2;
        });
        assert(it != v.end());
        nxt.emplace_back(v.begin(), it);
        nxt.emplace_back(it, v.end());
      }
      all = move(nxt);
    }

    for(int i=0; i<m; i++) {
      int x;
      cin >> x;
      if(have.count(x)) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
    }
  }

  return 0;
}