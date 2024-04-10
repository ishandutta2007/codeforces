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
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
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
    int n, m, k;
    cin >> n >> m >> k;
    --m;
    k = min(k, m);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int cl = 0; cl <= k; ++cl) {
      int cr = k - cl;
      int cur = 1e9;
      for (int l = cl; l <= m; ++l) {
        int cnt = m - l;
        if (cnt < cr) continue;
        int r = n - cnt - 1;
        cur = min(cur, max(a[l], a[r]));
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}