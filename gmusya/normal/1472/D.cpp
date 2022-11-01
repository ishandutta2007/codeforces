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
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll sum = 0;
    for (int i = 0; i < n; i++)
      if (a[i] % 2 == 1)
        sum -= a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i += 2)
      sum += a[i];
    if (sum > 0)
      cout << "Alice\n";
    if (sum == 0)
      cout << "Tie\n";
    if (sum < 0)
      cout << "Bob\n";
  }
  return 0;
}