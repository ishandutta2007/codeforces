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
    int g = 0;
    for (int it = 0; it < n; it++) {
      int id = it;
      for (int i = it; i < n; i++)
        if (__gcd(g, a[i]) > __gcd(g, a[id]))
          id = i;
      g = __gcd(g, a[id]);
      swap(a[id], a[it]);
    }
    for (auto &now : a)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}