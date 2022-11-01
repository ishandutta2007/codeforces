#include <iostream>
#include <vector>

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
    int ans = 0;
    int id = 0;
    while (id < n) {
      if (a[id]) ans++;
      id++;
      if (id + 2 >= n) break;
      if (!a[id + 1]) {
        id++;
        continue;
      }
      if (!a[id + 2]) {
        id += 2;
        continue;
      }
      if (!a[id]) {
        id += 3;
        continue;
      }
      id += 2;
    }
    cout << ans << '\n';
  }
  return 0;
}