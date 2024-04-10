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
    int n, d;
    cin >> n >> d;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    if (a.back() <= d || a[0] + a[1] <= d)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}