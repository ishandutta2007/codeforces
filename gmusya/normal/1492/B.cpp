#include <iostream>
#include <vector>

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
    vector <int> ans;
    vector <bool> used(n + 1);
    int mx = n;
    int pos = n;
    for (int i = n - 1; i >= 0; i--) {
      while (used[mx])
        mx--;
      if (a[i] == mx) {
        for (int j = i; j < pos; j++)
          ans.push_back(a[j]);
        pos = i;
      }
      used[a[i]] = true;
    }
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
  return 0;
}