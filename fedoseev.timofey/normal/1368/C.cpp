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
  int n;
  cin >> n;
  int x = 0, y = 0;
  vector <pair <int, int>> ans;
  for (int i = 0; i <= n; ++i) {
    for (int xx = x; xx < x + 3; ++xx) {
      for (int yy = y; yy < y + 3; ++yy) {
        if (xx == x + 1 && yy == y + 1) continue;
        ans.push_back({xx, yy});
      }
    }
    x += 2;
    y += 2;
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
}