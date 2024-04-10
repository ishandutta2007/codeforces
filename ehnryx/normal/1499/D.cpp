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

namespace Sieve {
  const int N = 2e7 + 1;
  vector<int> ps; bool isc[N]; int f[N], e[N];
  void sieve() { f[1] = 0;
    for (int i = 2; i < N; i++) { if (!isc[i]) {
        ps.push_back(i); f[i] = 1; e[i] = 1; }
      for (int ip, j = 0; j < ps.size() && (ip=i*ps[j]) < N; j++) {
        isc[ip] = 1;
        if (i % ps[j] == 0) {
          f[ip] = f[i];
          e[ip] = e[i] + 1; break;
        } else { f[ip] = f[i] + 1; e[ip] = 1; }
      } } }
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

  Sieve::sieve();

  int T;
  cin >> T;
  while(T--) {
    int c, d, x;
    cin >> c >> d >> x;
    vector<int> div;
    for(int i=1; i*i<=x; i++) {
      if(x % i == 0) {
        div.push_back(i);
        if(i*i < x) div.push_back(x/i);
      }
    }
    ll ans = 0;
    for(int g : div) { // gcd
      if((x/g + d) % c == 0) {
        ll mog = (x/g + d) / c; // lcm/gcd
        ans += 1 << Sieve::f[mog];
      }
    }
    cout << ans << nl;
  }

  return 0;
}