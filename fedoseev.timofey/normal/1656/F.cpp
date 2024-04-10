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

const ll Inf = 1e18;

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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + a[i];
    }
    auto get_cost = [&](int t) {
      ll cost = 0;
      if (a[0] + t >= 0) {
        ll sm = pref[n] + (ll)t * n - (a[0] + t);   
        cost = sm * (a[0] + t) - (ll)t * t * (n - 1);
      } else if (a[n - 1] + t <= 0) {
        ll sm = pref[n] + (ll)t * n - (a[n - 1] + t);   
        cost = sm * (a[n - 1] + t) - (ll)t * t * (n - 1);
      } else {
        int id = lower_bound(a.begin(), a.end(), -t) - a.begin();
        ll sum_l = pref[id] + (ll)id * t;
        ll sum_r = pref[n] + (ll)n * t - sum_l;
        cost = sum_r * (a[0] + t) + (sum_l - (a[0] + t)) * (a[n - 1] + t) - (ll)t * t * (n - 1);
      }
      return cost;
    };  
    ll ans = -Inf;
    for (int i = 0; i < n; ++i) ans = max(ans, get_cost(-a[i]));
    if (get_cost(-a[n - 1] - 1) > get_cost(-a[n - 1])) {
      cout << "INF\n";
      continue;
    }
    if (get_cost(-a[0] + 1) > get_cost(-a[0])) {
      cout << "INF\n";
      continue;
    }
    cout << ans << '\n';
  }
}