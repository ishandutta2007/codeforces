#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    for (ll ost = n; ost >= 1; ost--) {
      if (sum % ost)
        continue;
      ll need = sum / ost;
      bool flag = true;
      ll cursum = 0;
      for (int i = 0; i < n; i++) {
        if (cursum > need)
          flag = false;
        if (cursum == need)
          cursum -= need;
        cursum += a[i];
      }
      if (cursum != need)
        flag = false;
      if (flag) {
        cout << n - ost << '\n';
        break;
      }
    }
  }
  return 0;
}