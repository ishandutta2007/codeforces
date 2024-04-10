#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (k == 1) {
      bool flag = true;
      for (int i = 0; i + 1 < n; i++)
        if (a[i] != a[i + 1])
          flag = false;
      if (flag)
        cout << 1 << '\n';
      else
        cout << -1 << '\n';
      continue;
    }
    int cnt = 0;
    for (int i = 0; i + 1 < n; i++)
      cnt += (a[i] != a[i + 1]);
    cout << max((cnt + k - 2) / (k - 1), 1) << '\n';
  }
  return 0;
}