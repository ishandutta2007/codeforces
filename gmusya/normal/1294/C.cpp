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
    bool flag = false;
    int a = -1, b = -1;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) {
        a = i, b = n / i;
        break;
      }
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        if (flag)
          break;
        int c = i, d = a / i;
        if (b != c && b != d && c != d) {
          flag = true;
          cout << "YES\n";
          cout << b << ' ' << c << ' ' << d << '\n';
        }
      }
    }
    swap(a, b);
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        if (flag)
          break;
        int c = i, d = a / i;
        if (b != c && b != d && c != d) {
          flag = true;
          cout << "YES\n";
          cout << b << ' ' << c << ' ' << d << '\n';
        }
      }
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}