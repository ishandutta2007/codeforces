#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> c(3);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      c[x % 3]++;
    }
    int k = n / 3;
    int ans = 0;
    while (true) {
      if (c[0] == c[1] && c[0] == c[2])
        break;
      ans++;
      if (c[0] > k) {
        c[0]--;
        c[1]++;
        continue;
      }
      if (c[1] > k) {
        c[1]--;
        c[2]++;
        continue;
      }
      c[2]--;
      c[0]++;
      continue;
    }
    cout << ans << '\n';
  }
  return 0;
}