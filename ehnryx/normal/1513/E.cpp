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

ll modpow(ll n, ll e, ll m) {
  ll r = 1;
  for(;e;e/=2, n = n*n % m) {
    if(e&1) r = r*n % m;
  } return r;
}

const int N = 1e5 + 1;
ll fact[N], invf[N];
ll ncr(int n, int r) {
  if(r < 0 || n < r) return 0;
  return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}

ll solve(vector<int> a) {
  map<int,int> f;
  for(auto x : a) {
    f[x]++;
  }
  ll res = fact[size(a)];
  for(auto [_, c] : f) {
    res = res * invf[c] % MOD;
  }
  return res;
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

  fact[0] = invf[0] = 1;
  for(int i=1; i<N; i++) {
    fact[i] = fact[i-1] * i % MOD;
    invf[i] = modpow(fact[i], MOD - 2, MOD);
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  ll sum = accumulate(begin(a), end(a), (ll)0);
  if(sum % n) {
    cout << 0 << nl;
    return 0;
  }

  int want = sum / n;
  vector<int> smaller, larger;
  for(int i=0; i<n; i++) {
    if(a[i] < want) {
      smaller.push_back(a[i]);
    } else if(a[i] > want) {
      larger.push_back(a[i]);
    }
  }
  int equal = n - size(smaller) - size(larger);
  if(equal == n) {
    cout << 1 << nl;
    return 0;
  }

  if(min(size(smaller), size(larger)) == 1) {
    cout << solve(a) << nl;
  } else {
    ll ans = 2 * solve(smaller) * solve(larger) % MOD;
    ans = ans * ncr(n, equal) % MOD;
    cout << ans << nl;
  }

  return 0;
}