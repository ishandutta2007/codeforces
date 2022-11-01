#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
  }
  vector <char> ans;
  for (int i = 0; i + 1 < n; i++)
    ans.push_back('U');
  for (int i = 0; i + 1 < m; i++)
    ans.push_back('L');
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      for (int j = 0; j + 1 < m; j++)
        ans.push_back('L');
    } else {
      for (int j = 0; j + 1 < m; j++)
        ans.push_back('R');
    }
    ans.push_back('D');
  }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now;
  return 0;
}