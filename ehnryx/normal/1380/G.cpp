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

ll power(ll n, ll e) {
  ll r = 1;
  for(;e;e/=2) {
    if(e&1) r = r*n % MOD;
    n = n*n % MOD;
  }
  return r;
}

ll inverse(ll n) {
  return power(n, MOD-2);
}

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

  int n;
  cin >> n;
  vector<ll> a(2*n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  vector<ll> s(2*n+1);
  partial_sum(a.begin(), a.end(), s.begin() + 1);

  for(int k=1; k<=n; k++) {
    //cerr<<"DO "<<k<<nl;
    ll ans = 0;
    for(int i=0; i*k<n; i++) {
      ans = (ans + i * ((s[i*k+k] - s[i*k]) % MOD)) % MOD;
      //cerr<<"add "<<i<<" * "<<s[i*k+k]-s[i*k]<<nl;
    }
    //cerr << ans << nl;
    ans = ans * inverse(n) % MOD;
    cout << ans << " ";
  }
  cout << nl;

  return 0;
}