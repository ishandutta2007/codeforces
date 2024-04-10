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
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    if (2 * a.back() > sum) {
      cout << "T\n";
      continue;
    }
    if (sum % 2)
      cout << "T\n";
    else
      cout << "HL\n";
  }
  return 0;
}