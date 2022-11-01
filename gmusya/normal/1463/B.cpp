#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    ll sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i & 1)
        sum1 += a[i];
      else
        sum0 += a[i];
    }
    if (sum0 > sum1)
      for (int i = 1; i < n; i += 2)
        a[i] = 1;
    else
      for (int i = 0; i < n; i += 2)
        a[i] = 1;
    for (auto &now : a)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}