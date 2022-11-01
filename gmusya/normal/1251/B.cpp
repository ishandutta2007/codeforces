#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
      for (char c : s[i]) {
        if (c == '0')
          cnt0++;
        else
          cnt1++;
      }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int k = (int) s[i].size();
      if (k % 2)
        continue;
      while (k > 1 && cnt0 > 1) {
        k -= 2;
        cnt0 -= 2;
      }
      while (k > 1 && cnt1 > 1) {
        k -= 2;
        cnt1 -= 2;
      }
      if (k == 0)
        ans++;
      if (k == 1) {
        ans++;
        if (cnt0 == 0)
          cnt1--;
        else
          cnt0--;
      }
    }
    for (int i = 0; i < n; i++) {
      int k = (int) s[i].size();
      if (k % 2 == 0)
        continue;
      while (k > 1 && cnt0 > 1) {
        k -= 2;
        cnt0 -= 2;
      }
      while (k > 1 && cnt1 > 1) {
        k -= 2;
        cnt1 -= 2;
      }
      if (k == 0)
        ans++;
      if (k == 1) {
        ans++;
        if (cnt0 == 0)
          cnt1--;
        else
          cnt0--;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}