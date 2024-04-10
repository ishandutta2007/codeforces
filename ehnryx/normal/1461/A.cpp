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

  const int N = 1000;
  string nonpal;
  for(int i=0; i<N; i++) {
    for(int c=0; c<26; c++) {
      nonpal.push_back(c + 'a');
      bool bad = false;
      for(int j=0; j<i; j++) {
        string s = nonpal.substr(j);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) {
          bad = true;
          break;
        }
      }
      if(bad) {
        nonpal.pop_back();
      } else {
        break;
      }
    }
  }

  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    cout << string(k, 'c') << nonpal.substr(0, n-k) << nl;
  }

  return 0;
}