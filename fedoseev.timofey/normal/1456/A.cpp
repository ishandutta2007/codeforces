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
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    cin >> n >> p >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    int x, y;
    cin >> x >> y;
    vector <int> cnt(k);
    int ans = 2e9;
    for (int i = n - 1; i >= 0; --i) {
      if (!a[i]) {
        ++cnt[i % k];
      }
      if (i + 1 >= p) {
        ans = min(ans, x * cnt[i % k] + y * (i + 1 - p)); 
      }
    }
    cout << ans << '\n';
  }
}