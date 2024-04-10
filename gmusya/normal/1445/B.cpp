#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a + b, c + d) << '\n';
  }
  return 0;
}