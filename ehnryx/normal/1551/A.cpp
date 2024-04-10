%:include <bits/stdc++.h>
using namespace std;

//#define FILENAME sadcactus

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (int rem = n % 3; rem == 0) {
      cout << n/3 << " " << n/3 << nl;
    } else if (rem == 1) {
      cout << n/3 + 1 << " " << n/3 << nl;
    } else {
      cout << n/3 << " " << n/3 + 1 << nl;
    }
  }

  return 0;
}