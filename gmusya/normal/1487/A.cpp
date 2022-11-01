#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    sort(a.begin(), a.end());
    int pos = n;
    for (int i = 1; i < n; i++)
      if (a[i] != a[i - 1]) {
        pos = i;
        break;
      }
    cout << n - pos << '\n';
  }
  return 0;
}