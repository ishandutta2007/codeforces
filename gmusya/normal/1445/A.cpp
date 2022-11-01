#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(a.begin(), a.end());
    sort(a.rbegin(), a.rend());
    bool flag = true;
    for (int i = 0; i < n; i++)
      if (a[i] + b[i] > x)
        flag = false;
    if (flag)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}