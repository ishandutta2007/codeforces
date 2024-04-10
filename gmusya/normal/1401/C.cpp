#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <int> b = a;
    sort(b.begin(), b.end());
    bool tf = true;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i] && a[i] % b[0])
        tf = false;
    if (tf) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}