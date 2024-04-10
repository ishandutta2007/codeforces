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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = count(begin(s), end(s), '1');
    int zeros = count(begin(s), end(s), '0');
    if(ones % 2 || zeros % 2 || s.front() == '0' || s.back() == '0') {
      cout << "NO" << nl;
      continue;
    }

    string a(n, 0), b(n, 0);
    for(int i=0, o=0, z=0; i<n; i++) {
      if(s[i] == '0') {
        a[i] = (z % 2 ? ')' : '(');
        b[i] = (z % 2 ? '(' : ')');
      } else {
        a[i] = (o < ones/2 ? '(' : ')');
        b[i] = (o < ones/2 ? '(' : ')');
      }
      o += (s[i] == '1');
      z += (s[i] == '0');
    }
    cout << "YES" << nl;
    cout << a << nl;
    cout << b << nl;
  }

  return 0;
}