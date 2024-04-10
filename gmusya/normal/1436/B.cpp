#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> lp(100000), pr;
    for (int i = 2; i < 100000; i++) {
      if (!lp[i]) lp[i] = i, pr.push_back(i);
      for (int j = 0; j < (int)pr.size() && pr[j] * i < 100000 && pr[j] <= lp[i]; j++)
        lp[pr[j] * i] = pr[j];
    }
    vector <vector <int>> ans(n, vector<int>(n));
    for (int i = 0; i + 1 < n; i++)
      for (int j = 0; j + 1 < n; j++)
        ans[i][j] = 4;
    int x = 1;
    while (lp[4 * (n - 1) + x] != 4 * (n - 1) + x || lp[x] == x)
      x++;
    for (int i = 0; i + 1 < n; i++)
      ans[n - 1][i] = ans[i][n - 1] = x;
    int c = 1;
    while (lp[(n - 1) * x + c] != (n - 1) * x + c || lp[c] == c)
      c++;
    ans[n - 1][n - 1] = c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << ans[i][j] << ' ';
      cout << '\n';
    }
  }
  return 0;
}