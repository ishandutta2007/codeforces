#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    int a = 1;
    while (w % 2 == 0) {
      w /= 2;
      a *= 2;
    }
    while (h % 2 == 0) {
      h /= 2;
      a *= 2;
    }
    if (a >= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}