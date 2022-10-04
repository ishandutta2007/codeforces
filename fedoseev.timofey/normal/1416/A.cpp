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
    vector <vector <int>> where(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      where[a[i]].push_back(i);
    }
    vector <int> ans(n + 1, n);
    for (int x = 0; x < n; ++x) {
      if (where[x].empty()) continue;
      int cur = 0;
      cur = max(cur, where[x][0]);
      cur = max(cur, n - where[x].back() - 1);
      for (int i = 0; i + 1 < (int)where[x].size(); ++i) {
        cur = max(cur, where[x][i + 1] - where[x][i] - 1);
      }
      ans[cur + 1] = min(ans[cur + 1], x);
    }
    for (int i = 2; i <= n; ++i) {
      ans[i] = min(ans[i], ans[i - 1]);
    }
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == n) {
        cout << "-1 ";
      } else {
        cout << ans[i] + 1 << ' ';
      }
    }
    cout << '\n';
  }
}