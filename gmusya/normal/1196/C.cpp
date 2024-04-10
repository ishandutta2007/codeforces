#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x1 = -INF, x2 = INF, y1 = -INF, y2 = INF;
    int n;
    cin >> n;
    while (n--) {
      int x, y;
      cin >> x >> y;
      int fl, fu, fr, fd;
      cin >> fl >> fu >> fr >> fd;
      if (!fl)
        x1 = max(x, x1);
      if (!fr)
        x2 = min(x, x2);
      if (!fd)
        y1 = max(y, y1);
      if (!fu)
        y2 = min(y, y2);
    }
    if (x1 > x2 || y1 > y2)
      cout << "0\n";
    else
      cout << "1 " << x1 << ' ' << y1 << '\n';
  }
  return 0;
}