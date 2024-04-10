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
    int n, l, r;
    cin >> n >> l >> r;
    map <int, int> bal;
    for (int i = 0; i < l; ++i) {
      int x;
      cin >> x;
      ++bal[x];
    }
    for (int i = 0; i < r; ++i) {
      int x;
      cin >> x;
      --bal[x];
    }
    int ans = 0;
    int all = 0;
    for (auto p : bal) {
      all += p.second;
    }

    for (auto &p : bal) {
      if (all > 0 && p.second > 0) {
        int tk = min(all / 2, p.second / 2); 
        p.second -= 2 * tk;
        all -= 2 * tk;
        ans += tk;
      }
      if (all < 0 && p.second < 0) {
        int tk = min(-all / 2, -p.second / 2); 
        p.second += 2 * tk;
        all += 2 * tk;
        ans += tk;
      }
    } 
    int cl = 0, cr = 0;
    for (auto &p : bal) {
      if (p.second > 0) cl += p.second;
      else cr -= p.second;
    }
    ans += max(cl, cr);
    cout << ans << '\n';
  } 
}