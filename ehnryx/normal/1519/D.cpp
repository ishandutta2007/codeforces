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
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }

  vector<ll> dot(n+1);
  for(int i=0; i<n; i++) {
    dot[i+1] = dot[i] + (ll)a[i] * b[i];
  }
  reverse(begin(b), end(b));

  ll ans = 0;
  for(int offset = -n+1; offset <= n-1; offset++) {
    vector<ll> conv(n+1);
    for(int i=0; i<n; i++) {
      int j = i + offset;
      if(j < 0 || n <= j) continue;
      conv[i+1] = conv[i] + (ll)a[j] * b[i];
    }
    int s = offset + n-1;
    for(int i=0; i<n; i++) {
      int j = s - i;
      if(j < i || n <= j) continue;
      ll cur = dot[i] + dot[n] - dot[j+1] + conv[n-i] - conv[n-j-1];
      ans = max(ans, cur);
    }
  }
  cout << ans << nl;

  return 0;
}