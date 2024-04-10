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
    int n;
    cin >> n;
    vector<int> v(4);
    for(int i=0; i<4; i++) {
      cin >> v[i];
    }
    bool good = false;
    for(int bm=0; bm<1<<4; bm++) {
      vector<int> cur = v;
      for(int i=0; i<4; i++) {
        if(bm & 1<<i) {
          cur[i]--;
          cur[(i+1)%4]--;
        }
      }
      sort(cur.begin(), cur.end());
      good |= (cur.front() >= 0 && cur.back() <= n-2);
    }
    if(good) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}