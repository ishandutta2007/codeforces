#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
          if (i + j == n + 1) {
            cout << 0 << ' ';
            continue;
          }
          if (j == n) {
            if (i <= n / 2)
              cout << 1 << ' ';
            else
              cout << -1 << ' ';
            continue;
          }
          if ((i + j) % 2)
            cout << 1 << ' ';
          else
            cout << -1 << ' ';
        }
    } else {
      for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
          if ((i + j) % 2)
            cout << 1 << ' ';
          else
            cout << -1 << ' ';
        }
    }
    cout << '\n';
  }
  return 0;
}