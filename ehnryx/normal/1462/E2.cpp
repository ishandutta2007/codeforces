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
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
ll fact[N], invf[N];
ll ncr(int n, int r) {
  if(r<0 || r>n) return 0;
  return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}
ll inverse(ll n) {
  ll r = 1;
  for(int e=MOD-2; e; e/=2) {
    if(e&1) r = r*n % MOD;
    n = n*n % MOD;
  }
  return r;
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

  fact[0] = invf[0] = 1;
  for(int i=1; i<N; i++) {
    fact[i] = i * fact[i-1] % MOD;
    invf[i] = inverse(fact[i]);
  }

  int T;
  cin >> T;
  while(T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for(int i=0; i<n; i++) {
      int j = prev(upper_bound(a.begin(), a.end(), a[i] + k)) - a.begin();
      ans += ncr(j-i, m-1);
    }
    cout << ans % MOD << nl;
  }

  return 0;
}