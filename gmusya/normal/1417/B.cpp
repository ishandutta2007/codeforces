#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (a[i] * 2 == x) {
        if (flag)
          cout << 1 << ' ';
        else
          cout << 0 << ' ';
        flag = !flag;
        continue;
      }
      if (a[i] * 2 > x)
        cout << 1 << ' ';
      else
        cout << 0 << ' ';
    }
    cout << '\n';
  }
  return 0;
}