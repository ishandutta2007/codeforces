//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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

const int M = 1e5;
int cnt[M], sum[M+1];

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  for(int i=0; i<M; i++) {
    for(int v=i; v>0; v/=10) {
      cnt[i] += v % 10;
    }
    sum[i+1] = sum[i] + cnt[i];
  }

  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    if(n < k*(k+1)/2) {
      cout << -1 << nl;
      continue;
    }

    ll ans = -1;
    for(int i=0; i+k<M; i++) {
      int cur = sum[i+k+1] - sum[i];
      if(cur == n) {
        ans = i;
        break;
      }
    }
    if(ans != -1) {
      cout << ans << nl;
      continue;
    }

    for(int len=2; len<=18 && ans<0; len++) {
      for(int a=1; a<=9 && ans<0; a++) {
        for(int b=9; b>=0 && ans<0; b--) {
          ll num = llround((a+1) * powl(10, len-1)) - 1 - b;
          int cur = 0;
          for(int j=0; j<=k; j++) {
            for(ll v=num-j; v>0; v/=10) {
              cur += v % 10;
            }
          }
          if(cur == n) {
            ans = num - k;
            break;
          }
        }
      }
    }
    cout << ans << nl;
  }

  return 0;
}