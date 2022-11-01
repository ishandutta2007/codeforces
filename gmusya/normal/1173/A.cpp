#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int bal = x - y;
  int mx = bal + z;
  int mi = bal - z;
  if (mi < 0 && mx < 0) {
    cout << "-";
    return 0;
  }
  if (mi == 0 && mx == 0) {
    cout << "0";
    return 0;
  }
  if (mi > 0 && mx > 0) {
    cout << "+";
    return 0;
  }
  cout << "?";
  return 0;
}