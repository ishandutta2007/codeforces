#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  for (int i = 0; i < m; i++)
    cin >> c[i] >> d[i];
  vector<int> ans(1e6 + 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (c[j] - a[i] >= 0)
        ans[c[j] - a[i]] = max(ans[c[j] - a[i]], d[j] - b[i] + 1);
  for (int i = 1e6 - 1; i >= 0; i--)
    ans[i] = max(ans[i], ans[i + 1]);
  int answer = 1e9;
  for (int i = 0; i <= 1e6; i++)
    answer = min(ans[i] + i, answer);
  cout << answer;
  return 0;
}