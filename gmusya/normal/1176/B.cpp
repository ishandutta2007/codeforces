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
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x % 3 == 0)
        cnt0++;
      if (x % 3 == 1)
        cnt1++;
      if (x % 3 == 2)
        cnt2++;
    }
    int x = min(cnt1, cnt2);
    int ans = cnt0 + x;
    cnt1 -= x, cnt2 -= x;
    ans += cnt1 / 3 + cnt2 / 3;
    cout << ans << '\n';
  }
  return 0;
}