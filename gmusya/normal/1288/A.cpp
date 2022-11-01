#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int ans = n + 1;
    for (int x = 0; x <= 100'000; x++)
      ans = min(ans, x + (d + x) / (x + 1));
    if (ans <= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}