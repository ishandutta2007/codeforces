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
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (sum % x) ans = max(ans, i + 1);
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += a[i];
      if (sum % x) ans = max(ans, n - i);
    }
    if (ans == 0) ans = -1;
    cout << ans << '\n';
  }
}