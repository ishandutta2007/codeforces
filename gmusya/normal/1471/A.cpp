#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll mi = 0, ma = 0;
    for (int i = 0; i < n; i++)
      mi += a[i], ma += (a[i] + x - 1) / x;
    mi = (mi + x - 1) / x;
    cout << mi << ' ' << ma << '\n';
  }
  return 0;
}