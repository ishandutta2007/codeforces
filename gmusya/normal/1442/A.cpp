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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<ll> x(n);
    x[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
      x[i] = x[i + 1] + max(0, a[i] - a[i + 1]);
    bool flag = true;
    for (int i = 0; i < n; i++)
      if (a[i] < x[i])
        flag = false;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}