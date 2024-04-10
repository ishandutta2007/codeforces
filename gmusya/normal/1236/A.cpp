#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while (b && c > 1) {
      b--;
      c -= 2;
      cnt++;
    }
    while (a && b > 1) {
      a--;
      b -= 2;
      cnt++;
    }
    cout << cnt * 3 << '\n';
  }
  return 0;
}