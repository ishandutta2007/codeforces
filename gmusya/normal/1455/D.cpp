#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      bool tmp = true;
      for (int j = 0; j + 1 < n; j++)
        if (a[j] > a[j + 1])
          tmp = false;
      if (tmp)
        break;
      if (a[i] <= x)
        continue;
      swap(x, a[i]);
      cnt++;
    }
    for (int i = 0; i + 1 < n; i++)
      if (a[i] > a[i + 1])
        flag = false;
    if (!flag)
      cout << -1 << '\n';
    else
      cout << cnt << '\n';
  }
  return 0;
}