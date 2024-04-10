#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int len1 = max(abs(n - x), x - 1);
    int len2 = max(abs(m - y), y - 1);
    cout << len1 + len2 << '\n';
  }
  return 0;
}