#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a * b >= 6 * n) {
    cout << a * b << '\n' << a << ' ' << b << '\n';
    return 0;
  }
  bool flag = false;
  if (a > b) {
    swap(a, b);
    flag = true;
  }
  pair <ll, pll> ans = {1e10, {-1, -1}};
  for (ll i = a; i <= 1e5; i++) {
    ll k = (6 * n + i - 1) / i;
    if (k < b)
      k = b;
    ans = min(ans, {i * k, {i, k}});
  }
  if (flag)
    swap(ans.second.first, ans.second.second);
  cout << ans.first << '\n' << ans.second.first << ' ' << ans.second.second;
  return 0;
}