#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> ans;
    for (int i = k + 1; i <= n; i++)
      ans.push_back(i);
    for (int it = 1, i = k - 1; it <= k / 2; it++, i--)
      ans.push_back(i);
    cout << ans.size() << '\n';
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
  return 0;
}