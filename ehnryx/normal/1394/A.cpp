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

  int n, d, m;
  cin >> n >> d >> m;
  vector<ll> small, big;
  for(int i=0; i<n; i++) {
    int v;
    cin >> v;
    if(v <= m) {
      small.push_back(v);
    } else {
      big.push_back(v);
    }
  }
  sort(small.begin(), small.end());
  sort(big.begin(), big.end());

  int sn = small.size();
  int bn = big.size();
  vector<ll> spref(sn + 1), bpref(bn + 1);
  partial_sum(small.begin(), small.end(), spref.begin() + 1);
  partial_sum(big.begin(), big.end(), bpref.begin() + 1);

  ll ans = 0;
  for(int i=0; i<=bn && (i-1)*(d+1)+1<=n; i++) {
    int over = max(0, (i-1)*(d+1)+1 - bn);
    ll cur = bpref[bn] - bpref[bn-i] + spref[sn] - spref[over];
    ans = max(ans, cur);
  }
  cout << ans << nl;

  return 0;
}