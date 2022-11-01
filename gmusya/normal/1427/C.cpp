#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector <int> t(n + 1), x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> t[i] >> x[i] >> y[i];
  x[0] = y[0] = 1;
  vector <int> ans(n + 1, -INF);
  ans[0] = 0;
  int answer = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = max(i - 2000, 0); j < i; j++)
      if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
        ans[i] = max(ans[i], ans[j] + 1);
    answer = max(answer, ans[i]);
  }
  cout << answer;
  return 0;
}