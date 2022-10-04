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
  int n; ll k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll l = -4e18, r = 4e18;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    ll have = 0;
    for (int i = 0; i < n; ++i) {
      int low = -1, high = a[i]; 
      while (high - low > 1) {
        int mid = (low + high) / 2;
        if (a[i] - 3LL * mid - 3LL * mid * mid - 1 >= m) {
          low = mid;
        } else {
          high = mid;
        }
      }
      have += low + 1; 
    }
    if (have <= k) {
      r = m;
    } else {
      l = m;
    }
  }
  vector <int> ans(n);
  for (int i = 0; i < n; ++i) {
    int low = -1, high = a[i]; 
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (a[i] - 3LL * mid - 3LL * mid * mid - 1 >= r) {
        low = mid;
      } else {
        high = mid;
      }
    }
    ans[i] = low + 1;
  }
  ll rem = k;
  for (int i = 0; i < n; ++i) rem -= ans[i];
  vector <pair <ll, int>> go;
  for (int i = 0; i < n; ++i) {
    if (ans[i] < a[i]) {
      go.emplace_back(a[i] - 3LL * ans[i] - 3LL * ans[i] * ans[i] - 1, i);
    } 
  }
  sort(go.rbegin(), go.rend());
  for (int i = 0; i < rem; ++i) {
    ++ans[go[i].second];
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}