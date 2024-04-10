#include <iostream>
#include <vector>
#include <algorithm>

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
    ll k;
    cin >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll g = 0;
    for (int i = 0; i + 1 < n; i++)
      g = __gcd(g, a[i + 1] - a[i]);
    if ((k - a[0]) % g == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}