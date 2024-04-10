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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      int pr = (i == 0 ? 0 : a[i - 1]);
      int nx = (i == n - 1 ? 0 : a[i + 1]);
      int mx = max(pr, nx);
      if (a[i] > mx) {
        ans += a[i] - mx;
        a[i] = mx;
      }
    } 
    for (int i = 1; i < n; ++i) {
      ans += abs(a[i] - a[i - 1]);
    } 
    ans += a[0];
    ans += a[n - 1];
    cout << ans << '\n';
  } 
}