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
 
const int md = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    const int k = 60;
    vector <int> cnt(k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        if (x[i] & (1LL << j)) ++cnt[j];
      }
    }
    int res = 0;
    for (int j = 0; j < n; ++j) {
      int s1 = 0, s2 = 0;
      for (int b = 0; b < k; ++b) {
        if (x[j] & (1LL << b)) {
          s1 = (s1 + ((ll)((1LL << b) % md) * cnt[b]) % md) % md;
          s2 = (s2 + ((ll)((1LL << b) % md) * n) % md) % md;
        } else {
          s2 = (s2 + ((ll)((1LL << b) % md) * cnt[b]) % md) % md;
        }
      }
      res = (res + ((ll)s1 * s2) % md) % md;
    }
    cout << res << '\n';
  }
}