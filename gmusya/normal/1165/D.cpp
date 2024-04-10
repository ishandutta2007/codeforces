#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> d(n);
    for (int i = 0; i < n; i++)
      cin >> d[i];
    sort(d.begin(), d.end());
    ll val = d[0] * d[n - 1];
    vector <ll> dx;
    for (ll x = 2; x * x <= val; x++) {
      if (val % x == 0) {
        dx.push_back(x);
        if (x * x != val)
          dx.push_back(val / x);
      }
    }
    if (dx.size() != d.size()) {
      cout << -1 << '\n';
      continue;
    }
    sort(dx.begin(), dx.end());
    bool tf = true;
    for (int i = 0; i < dx.size(); i++)
      if (dx[i] != d[i])
        tf = false;
    if (tf)
      cout << val << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}