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
    int max_len = -1, cost_one = -1;
    int max_r = -1, cost_r = -1;
    int min_l = (int)1e9 + 7, cost_l = -1;
    for (int i = 0; i < n; ++i) {
      int l, r, c;
      cin >> l >> r >> c;
      if (r - l + 1 > max_len || (r - l + 1 == max_len && c < cost_one)) {
        max_len = r - l + 1;
        cost_one = c;
      }
      if (r > max_r || (r == max_r && c < cost_r)) {
        max_r = r;
        cost_r = c;
      }
      if (l < min_l || (l == min_l && c < cost_l)) {
        min_l = l;
        cost_l = c;
      }
      int len = max_r - min_l + 1, cost = cost_r + cost_l;
      if (len > max_len || (len == max_len && cost < cost_one)) {
        cout << cost << '\n';
      } else {
        cout << cost_one << '\n';
      }
    }
  }
}