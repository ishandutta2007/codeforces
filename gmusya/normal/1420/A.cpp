#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool tf = false;
    for (int i = 0; i + 1 < n; i++)
      if (a[i] <= a[i + 1])
        tf = true;
    if (tf)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}