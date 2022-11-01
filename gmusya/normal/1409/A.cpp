#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (abs(a - b) + 9) / 10 << '\n';
  }
  return 0;
}