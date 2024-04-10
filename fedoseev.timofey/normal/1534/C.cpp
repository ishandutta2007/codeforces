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
    vector <vector <int>> p(2, vector <int> (n));
    vector <vector <int>> where(2, vector <int> (n));
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> p[i][j];
        --p[i][j];
        where[i][p[i][j]] = j;
      }
    }
    vector <int> used(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      if (p[0][i] == p[1][i]) {
        used[i] = 1;
        continue;
      }
      ++cnt;
      int y = i;
      while (!used[y]) {
        used[y] = 1;
        y = where[0][p[1][y]];
      }
    }
    const int md = 1e9 + 7;
    int ans = 1;
    for (int i = 0; i < cnt; ++i) {
      ans = 2 * ans % md;
    }
    cout << ans << '\n';
  }
}