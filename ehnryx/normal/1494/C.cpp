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

int solve(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<bool> good;
  for(int x : b) {
    auto it = lower_bound(a.begin(), a.end(), x);
    good.push_back(it != a.end() && *it == x);
  }

  int ans = 0;
  int other = accumulate(good.begin(), good.end(), 0);
  for(int i=0, j=0; i<b.size(); i++) {
    while(j<a.size() && a[j]<=b[i]) {
      j++;
    }
    int first = upper_bound(b.begin(), b.end(), b[i] - j) - b.begin();
    other -= good[i];
    ans = max(ans, i - first + 1 + other);
  }
  return ans;
}

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
    vector<int> la, ra, lb, rb;
    for(int i=0; i<n; i++) {
      int a;
      cin >> a;
      if(a < 0) la.push_back(-a);
      else ra.push_back(a);
    }
    for(int i=0; i<m; i++) {
      int b;
      cin >> b;
      if(b < 0) lb.push_back(-b);
      else rb.push_back(b);
    }
    cout << solve(la, lb) + solve(ra, rb) << nl;
  }

  return 0;
}