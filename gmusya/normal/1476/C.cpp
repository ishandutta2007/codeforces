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
    vector <ll> c(n), a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++)
      if (a[i] < b[i])
        swap(a[i], b[i]);
    ll ans = 0, cur = 0;
    for (int i = 1; i < n; i++) {
      ll len = a[i] - b[i];
      if (!len)
        cur = c[i] + 1;
      else
        cur = max(cur + c[i] - len + 1, c[i] + 1 + len);
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}