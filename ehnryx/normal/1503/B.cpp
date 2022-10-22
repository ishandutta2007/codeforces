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

  vector<pair<int,int>> even, odd;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if((i + j) % 2) {
        odd.emplace_back(i, j);
      } else {
        even.emplace_back(i, j);
      }
    }
  }

  for(int i=0; i<n*n; i++) {
    int c;
    cin >> c;
    if(c != 1 && !odd.empty()) {
      cout << 1 << " " << odd.back().first << " " << odd.back().second << nl;
      odd.pop_back();
    } else if(c != 2 && !even.empty()) {
      cout << 2 << " " << even.back().first << " " << even.back().second << nl;
      even.pop_back();
    } else if(!odd.empty()) {
      cout << 3 << " " << odd.back().first << " " << odd.back().second << nl;
      odd.pop_back();
    } else {
      cout << 3 << " " << even.back().first << " " << even.back().second << nl;
      even.pop_back();
    }
    cout.flush();
  }

  return 0;
}