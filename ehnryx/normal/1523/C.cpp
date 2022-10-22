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

void print(const vector<int>& stk) {
  for(int i=0; i<stk.size(); i++) {
    if(i>0) cout << '.';
    cout << stk[i];
  }
  cout << nl;
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
    int n;
    cin >> n;
    vector<int> stk;
    for(int i=0; i<n; i++) {
      int v;
      cin >> v;
      if(v == 1) {
        stk.push_back(v);
      } else {
        while(!empty(stk) && stk.back() != v - 1) {
          stk.pop_back();
        }
        if(!empty(stk) && stk.back() == v - 1) {
          stk.back() = v;
        } else {
          assert(false);
        }
      }
      print(stk);
    }
  }

  return 0;
}