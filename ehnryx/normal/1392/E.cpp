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

  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int s = i/2 * 2;
    for(int j=0; j<n; j++) {
      cout << (1LL << (s+j)) << " ";
    }
    cout << endl;
  }

  int T;
  cin >> T;
  while(T--) {
    ll v;
    cin >> v;
    vector<char> ans;
    for(int i=0, j=0; j<n+n-2; i++) {
      while(j<n+n-2 && (v >> j & 1)) {
        ans.push_back('R');
        j++;
      }
      ans.push_back('D');
      j++;
      if(j >= n+n-2) break;
      while(j<n+n-2 && !(v >> j & 1)) {
        ans.push_back('R');
        j++;
      }
      ans.push_back('D');
      j++;
      if(j >= n+n-2) break;
    }
    assert(ans.size() >= n+n-2);
    int x = 1, y = 1;
    cout << x << " " << y << endl;
    for(int i=0; i<n+n-2; i++) {
      x += (ans[i] == 'D');
      y += (ans[i] == 'R');
      cout << x << " " << y << endl;
    }
  }

  return 0;
}