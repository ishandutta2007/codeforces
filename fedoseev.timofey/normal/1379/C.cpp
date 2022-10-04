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
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> have(m);
    for (int i = 0; i < m; ++i) cin >> have[i].first >> have[i].second;
    sort(have.rbegin(), have.rend());
    vector <ll> pref(m + 1);
    for (int i = 0; i < m; ++i) {
      pref[i + 1] = pref[i] + have[i].first;
    }
    ll ans = 0;
    for (int who = 0; who < m; ++who) {
      int cb = have[who].second;
      int l = -1, r = m;
      while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (have[mid].first >= cb) {
          l = mid;
        } else {
          r = mid;
        }
      }
      int cnt = l + 1;
      cnt = min(cnt, n - 1);
      if (cnt <= who) {
        ans = max(ans, pref[cnt] + have[who].first + (ll)have[who].second * (n - 1 - cnt));
      }
    }
    ll sum = 0; int max_b = 0;
    for (int i = 0; i < min(n, m); ++i) {
      sum += have[i].first;
      max_b = max(max_b, have[i].second);
      ans = max(ans, sum + (ll)(n - i - 1) * max_b);
    }
    cout << ans << '\n';
  } 
}