#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <ll> a(n * k);
    for (int i = 0; i < n * k; i++)
      cin >> a[i];
    ll ans = 0;
    for (int i = n * k - n + (n - 1) / 2, it = 0; it < k; it++, i -= (n / 2) + 1)
      ans += a[i];
    cout << ans << '\n';
  }
  return 0;
}