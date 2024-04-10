/*
 * author:  ADMathNoob
 * created: 07/27/21 14:01:29
 * problem: https://codeforces.com/contest/1394/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> xx(n);
  vector<int> yy(n);
  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    xx[i] = count(s.begin(), s.end(), 'B');
    yy[i] = (int) s.size() - xx[i];
    diff[i] = yy[i] - xx[i];
  }
  int maxX = *max_element(xx.begin(), xx.end());
  int minX = *min_element(xx.begin(), xx.end());
  int maxY = *max_element(yy.begin(), yy.end());
  int minY = *min_element(yy.begin(), yy.end());
  int max_diff = *max_element(diff.begin(), diff.end());
  int min_diff = *min_element(diff.begin(), diff.end());
  auto Works = [&](int dist) -> pair<int, int> {
    int x1 = maxX - dist;
    int x2 = minX + dist;
    int y1 = maxY - dist;
    int y2 = minY + dist;
    int d1 = max_diff - dist;
    int d2 = min_diff + dist;
    auto Inside = [&](int x, int y) {
      int d = y - x;
      return (x1 <= x && x <= x2 && y1 <= y && y <= y2 && d1 <= d && d <= d2 && x + y >= 1);
    };
    {
      int x = x2;
      int y = d1 + x;
      y = max(y, y1);
      y = min(y, y2);
      if (Inside(x, y)) {
        return {x, y};
      }
    }
    {
      int y = y2;
      int x = y - d1;
      x = max(x, x1);
      x = min(x, x2);
      if (Inside(x, y)) {
        return {x, y};
      }
    }
    return {-1, -1};
  };
  int low = 0, high = 5e5;
  while (low < high) {
    int mid = (low + high) / 2;
    if (Works(mid).first != -1) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  auto [k0, k1] = Works(low);
  cout << low << '\n';
  cout << string(k0, 'B') + string(k1, 'N') << '\n';
  return 0;
}