#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  vector <int> c(n);
  ll x = 0;
  for (int b = 30; b >= 0; --b) {
    vector <int> p(n); 
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return (c[i] < c[j] || (c[i] == c[j] && i < j));
    });
    ll ff = 0, ss = 0;
    for (int l = 0; l < n; ++l) {
      int r = l;
      while (r < n && c[p[l]] == c[p[r]]) {
        ++r;
      }
      --r;
      ll f = 0, s = 0, c1 = 0, c0 = 0;
      for (int i = l; i <= r; ++i) {
        if (a[p[i]] & (1 << b)) {
          f += c0;
          ++c1;
        } else {
          s += c1;
          ++c0;
        }
      }
      ff += f;
      ss += s;
      l = r;
    }
    ans += min(ff, ss);
    if (ff < ss) {
      x |= (1 << b);
    }
    for (int i = 0; i < n; ++i) {
      c[i] |= (a[i] & (1 << b));
    }
  }   
  cout << ans << ' ' << x << '\n';
}