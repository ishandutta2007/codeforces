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

int calc(int len, int base, const vector<int>& v) {
  int i = 0;
  while(size(to_string(base * v[i])) < len) {
    i++;
  }
  return base * v[i];
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

  vector<int> twos, threes, fives;
  twos.push_back(1);
  while(size(to_string(twos.back())) < 9) {
    twos.push_back(2 * twos.back());
  }
  threes.push_back(1);
  while(size(to_string(threes.back())) < 9) {
    threes.push_back(3 * threes.back());
  }
  fives.push_back(1);
  while(size(to_string(fives.back())) < 9) {
    fives.push_back(3 * fives.back());
  }

  int T;
  cin >> T;
  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int g = calc(c, 1, fives);
    int x = calc(a, g, twos);
    int y = calc(b, g, threes);
    cout << x << " " << y << nl;
  }

  return 0;
}