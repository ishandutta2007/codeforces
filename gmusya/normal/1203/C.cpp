#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll g = a[0];
  for (int i = 1; i < n; i++)
    g = __gcd(g, a[i]);
  int ans = 0;
  for (ll x = 1; x * x <= g; x++) {
    if (x * x == g) {
      ans++;
      break;
    }
    if (g % x == 0)
      ans += 2;
  }
  cout << ans;
  return 0;
}