#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k = 1;
    int pos = 0;
    int x = 0;
    int cnt = 0;
    cin >> x;
    while (pos < x) {
      pos += k;
      k++;
      cnt++;
    }
    if (pos == x + 1)
      cnt++;
    cout << cnt << '\n';
  }
  return 0;
}