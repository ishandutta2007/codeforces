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
    bool flag = false;
    for (int i = 0; i + 1 < n; i++)
      if (a[i] == a[i + 1])
        flag = true;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}