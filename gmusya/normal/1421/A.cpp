#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (a ^ b) << '\n';
  }
  return 0;
}