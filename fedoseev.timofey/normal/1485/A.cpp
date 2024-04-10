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
    int a, b;
    cin >> a >> b;
    int ans = (int)1e9;
    for (int cnt = 0; cnt <= 100; ++cnt) {
      if (b + cnt == 1) continue;
      int cur = cnt;
      int ca = a;
      while (ca > 0) {
        ca = ca / (b + cnt);
        ++cur;
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}