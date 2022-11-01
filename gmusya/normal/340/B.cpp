#include <iostream>
#include <vector>

using namespace std;

struct vec {
  int x, y;
  void read() {
    cin >> x >> y;
  }
  int operator%(vec p) {
    return x * p.y - y * p.x;
  }
  vec operator-(vec p) {
    return {x - p.x, y - p.y};
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vec> p(n);
  for (int i = 0; i < n; i++)
    p[i].read();
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      vector <int> left, right;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j)
          continue;
        if ((p[k] - p[i]) % (p[j] - p[i]) < 0)
          left.push_back(k);
        if ((p[k] - p[i]) % (p[j] - p[i]) > 0)
          right.push_back(k);
      }
      if (left.empty() || right.empty())
        continue;
      int s1 = 0, s2 = 0;
      for (int id : left)
        s1 = max(s1, abs((p[id] - p[i]) % (p[j] - p[i])));
      for (int id : right)
        s2 = max(s2, abs((p[id] - p[i]) % (p[j] - p[i])));
      ans = max(ans, s1 + s2);
    }
  cout << ans / 2 << '.' << ans % 2 * 5;
  return 0;
}