#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = n - 2; i >= 0 && k > 0; i--, k--)
      a[n - 1] += a[i];
    cout << a[n - 1] << '\n';
  }
  return 0;
}