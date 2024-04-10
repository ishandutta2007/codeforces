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
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, (100 * p[i] + k - 1) / k - p[i - 1]);
      p[i] += p[i - 1];
    }
    cout << ans << '\n';
  }
  return 0;
}