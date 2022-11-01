#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ans = -1;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; j < n; j++)
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
          flag = false;
      if (flag)
        ans = 1;
    }
    cout << ans << '\n';
  }
  return 0;
}