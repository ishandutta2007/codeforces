#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
      cin >> a[i];
    vector <bool> used(n);
    vector <int> ans;
    for (int i = 0; i < 2 * n; i++) {
      if (used[a[i] - 1]) continue;
      used[a[i] - 1] = true;
      ans.push_back(a[i]);
    }
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}