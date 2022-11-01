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
    int n;
    cin >> n;
    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    ll L = 0, R = 1e9;
    while (L != R) {
      ll M = (L + R) / 2;
      ll ans = 0;
      for (int j = 0; j < n; j++)
        if (a[j] > M)
          ans += b[j];
      if (ans > M)
        L = M + 1;
      else
        R = M;
    }
    cout << L << '\n';
  }
  return 0;
}