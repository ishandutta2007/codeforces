#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
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
    ll k = (sum + n - 2) / (n - 1);
    for (int i = 0; i < n; i++)
      k = max(k, a[i]);
    cout << k * (n - 1) - sum << '\n';
  }
  return 0;
}