#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int ma = 0;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      if (a[i] > ma)
        ma = a[i];
    int ans = -2;
    for (int i = 0; i < n; i++) {
      if (a[i] != ma)
        continue;
      if (i && a[i - 1] != a[i])
        ans = i;
      if (i + 1 < n && a[i + 1] != a[i])
        ans = i;
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}