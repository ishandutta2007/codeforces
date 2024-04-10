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
    int n;
    cin >> n;
    vector <int> a(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i % 2 == 0) res += a[i];
    }
    ll ans = res;
    for (int tt = 0; tt <= 1; ++tt) {
      vector <int> b;
      for (int i = tt; i + 1 < n; i += 2) {
        int cur = 0;
        cur += a[i] * (i % 2 == 0 ? -1 : 1);
        cur += a[i + 1] * ((i + 1) % 2 == 0 ? -1 : 1);
        b.push_back(cur);
      }
      ll mn = 0, sm = 0;
      for (int x : b) {
        sm += x;
        ans = max(ans, res + sm - mn);
        mn = min(mn, sm);
      }
    }    
    cout << ans << '\n';
  }
}