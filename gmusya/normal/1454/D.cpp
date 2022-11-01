#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector <ll> val(50, 1);
    for (ll i = 2; i * i <= n; i++) {
      int cnt = 0;
      while (n % i == 0) {
        val[cnt] *= i;
        cnt++;
        n /= i;
      }
    }
    val[0] *= n;
    while (val.back() == 1)
      val.pop_back();
    reverse(val.begin(), val.end());
    cout << val.size() << '\n';
    for (auto &now : val)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}