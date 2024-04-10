#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (b == 1)
      b++, ans++;
    int tmp = 100;
    for (int k = 0; k < 25; k++) {
      int _b = b + k;
      int curans = k;
      int _a = a;
      while (_a) {
        _a /= _b;
        curans++;
      }
      tmp = min(tmp, curans);
    }
    cout << tmp + ans << '\n';
  }
  return 0;
}