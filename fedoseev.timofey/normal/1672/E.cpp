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

const int L = 2000;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  auto ask = [&](int w) {
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
  };
  int low = 0, high = L * n + n - 1; 
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (ask(mid) != 1) {
      low = mid;
    } else {
      high = mid;
    }
  }
  int sum = high - (n - 1);
  int ans = high;
  
  for (int k = 2; k <= n; ++k) {
    int min_w = (sum + n - k + k - 1) / k;
    if (1 <= min_w) {
      int h = ask(min_w);
      if (h != 0) {
        ans = min((ll)ans, (ll)min_w * h);
      }
    } 
  }
  cout << "! " << ans << endl;
}