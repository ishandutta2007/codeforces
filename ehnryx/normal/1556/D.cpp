#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

//#define DEBUG

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

  int n, k;
#ifndef DEBUG
  cin >> n >> k;
#else
  n = 5; k = 4;
  vector<int> ans = { 0, 5, 3, 3, 10, 1 };
#endif

  vector<int> _and(n), _or(n);
  for(int i=1; i<n; i++) {
    cout << "and " << i << " " << i+1 << endl;
#ifndef DEBUG
    cin >> _and[i];
#else
    _and[i] = ans[i] & ans[i+1];
#endif
    cout << "or " << i << " " << i+1 << endl;
#ifndef DEBUG
    cin >> _or[i];
#else
    _or[i] = ans[i] | ans[i+1];
#endif
  }

#ifdef DEBUG
  for(int i=1; i<n; i++) {
    cerr << _and[i] << " " << _or[i] << nl;
  }
#endif

  int a_and_c, a_or_c;
  cout << "and 1 3" << endl;
#ifndef DEBUG
  cin >> a_and_c;
#else
  a_and_c = ans[1] & ans[3];
#endif
  cout << "or 1 3" << endl;
#ifndef DEBUG
  cin >> a_or_c;
#else
  a_or_c = ans[1] | ans[3];
#endif

#ifdef DEBUG
  cerr << a_and_c << " " << a_or_c << nl;
#endif

  int x = _or[1] & a_or_c;
  int a = (x ^ _and[2]) | (a_and_c & _and[1]);

  vector<int> v(n+1);
  for(int i=1, _xor=0; i<=n; i++) {
    v[i] = a ^ _xor;
    _xor ^= _and[i] ^ _or[i];
  }

#ifdef DEBUG
  cerr << "v = ";
  for(int i=1; i<=n; i++) {
    cerr << v[i] << " ";
  } cerr << nl;
#endif

  sort(begin(v) + 1, end(v));

  cout << "finish " << v[k] << endl;

  return 0;
}