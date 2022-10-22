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

int solve(int n, int s, int t, vector<int> a) {
  a[0] ^= s;
  a[1] ^= t;
  a.push_back(a[0]);
  a.push_back(a[1]);

  int dp[n+2][4];
  memset(dp, INF, sizeof dp);
  dp[1][a[0]<<1|a[1]] = 0;
  for(int i=2; i<=n+1; i++) {
    for(int bm=0; bm<1<<2; bm++) {
      for(int o=0; o<2; o++) {
        int pm = bm >> 1 | o << 1;
        if(pm == 3 && (bm & 1)) continue;
        if(pm == 0 && !(bm & 1)) continue;
        dp[i][bm] = min(dp[i][bm], dp[i-1][pm] + (a[i] ^ (bm & 1)));
      }
    }
  }
  return dp[n+1][a[0]<<1|a[1]];
}

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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a;
    for(char c : s) {
      if(c == 'R') a.push_back(1);
      else a.push_back(0);
    }

    int ans = INF;
    for(int i=0; i<2; i++) {
      for(int j=0; j<2; j++) {
        ans = min(ans, i + j + solve(n, i, j, a));
      }
    }
    cout << ans << nl;
  }

  return 0;
}