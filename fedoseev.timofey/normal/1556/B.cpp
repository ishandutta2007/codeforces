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
    vector <vector <int>> pos(2);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      pos[x % 2].push_back(i);
    }
    if (pos[0].size() > (n + 1) / 2 || pos[1].size() > (n + 1) / 2) {
      cout << "-1\n";
      continue;
    }
    ll ans = 1e18;
    for (int t = 0; t < 2; ++t) {
      if (pos[t].size() == (n + 1) / 2) {
        ll cur = 0;
        for (int i = 0; i < (int)pos[t].size(); ++i) {
          cur += abs(pos[t][i] - 2 * i);
        }
        ans = min(ans, cur);
      }
    }
    cout << ans << '\n';
  } 
}