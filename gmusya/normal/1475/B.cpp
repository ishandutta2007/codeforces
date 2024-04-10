#include <iostream>

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
    for (int i = 0; i <= 1000; i++) {
      if (n - 2020 * i < 0)
        break;
      if ((n - 2020 * i) % 2021 == 0)
        flag = true;
    }
    if (flag)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}