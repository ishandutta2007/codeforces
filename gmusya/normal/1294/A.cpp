#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if ((a + b + c + n) % 3) {
      cout << "NO\n";
      continue;
    }
    int k = (a + b + c + n) / 3;
    if (a > k || b > k || c > k)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}