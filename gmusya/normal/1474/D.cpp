#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> a(n + 2);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vector <ll> pre(n + 2, -1), suf(n + 2, -1);
    pre[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] < pre[i - 1])
        break;
      pre[i] = a[i] - pre[i - 1];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 0; i--) {
      if (a[i] < suf[i + 1])
        break;
      suf[i] = a[i] - suf[i + 1];
    }
    if (pre[n + 1] == 0) {
      cout << "YES\n";
      continue;
    }
    bool flag = false;
    for (int i = 1; i + 1 <= n; i++) {
      bool tmp = true;
      vector <ll> arr = {pre[i - 1], a[i + 1], a[i], suf[i + 2]};
      for (int j = 0; j < 4; j++)
        if (arr[j] < 0)
          tmp = false;
      for (int j = 1; j < 4; j++) {
        if (arr[j] < arr[j - 1]) {
          tmp = false;
          break;
        }
        arr[j] -= arr[j - 1];
      }
      if (arr[3])
        tmp = false;
      flag |= tmp;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}