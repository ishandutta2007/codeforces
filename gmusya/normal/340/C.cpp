#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * (2 * i - 1) - 2 * sum;
    sum += a[i];
  }
  ll g = __gcd(ans, (ll)n);
  cout << ans / g << ' ' << n / g;
  return 0;
}