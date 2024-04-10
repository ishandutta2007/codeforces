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
    int x, y;
    cin >> x >> y;
    ll ans = 0;
    /*for (int b = 1; b <= y; ++b) {
      for (int k = 1; k < b; ++k) {
        if ((b + 1) * k <= x) {
          ++ans;
        }
      }
    }*/
    for (int k = 1; k * (k + 1) <= x; ++k) {
      int max_good = min(y, x / k - 1);
      int min_good = (k + 1);
      ans += max(0, max_good - min_good + 1);
    }
    cout << ans << '\n';
  }   
}