#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if (b == c)
        flag = true;
    }
    if (flag && m % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}