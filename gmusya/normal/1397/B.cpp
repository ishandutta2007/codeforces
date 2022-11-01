#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 1e18;
  for (ll val = 1; val <= 1e5; val++) {
    bool tf = true;
    vector <ll> b(n);
    b[0] = 1;
    for (int i = 1; i < n; i++) {
      b[i] = b[i - 1] * val;
      if (b[i] > 1e13) {
        tf = false;
        break;
      }
    }
    if (!tf) break;
    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum += abs(a[i] - b[i]);
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}