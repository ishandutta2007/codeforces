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
constexpr ll MOD = 1e9 + 7;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

int add(int a, int b) {
  return a+b < MOD ? a+b : a+b - MOD;
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

  const int M = 2e5 + 1;
  vector length(M, vector<int>(10));
  fill(begin(length[0]), end(length[0]), 1);
  for(int i=1; i<M; i++) {
    for(int j=0; j<9; j++) {
      length[i][j] = length[i-1][j+1];
    }
    length[i][9] = add(length[i-1][0], length[i-1][1]);
  }

  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int ans = 0;
    for(char c : s) {
      ans = add(ans, length[m][c-'0']);
    }
    cout << ans << nl;
  }

  return 0;
}