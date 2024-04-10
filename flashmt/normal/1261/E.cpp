#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<pair<int, int>> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i});
  }

  sort(a.begin(), a.end(), greater<pair<int, int>>());
  int numRow = a[0].first + 1;
  vector<vector<int>> ans(numRow, vector<int>(n, 0));
  for (int i = 0; i < a[0].first; i++)
    ans[i][a[0].second] = 1;
  int row = 0;
  for (int i = 1; i < n; i++)
  {
    auto [block, col] = a[i];
    for (int i = 1; i <= block; i++)
      ans[(row + i) % numRow][col] = 1;
    if (row < numRow - 2)
      row++;
  }

  if (!accumulate(ans[numRow - 1].begin(), ans[numRow - 1].end(), 0))
    numRow--;
  cout << numRow << endl;
  for (int i = 0; i < numRow; i++)
  {
    for (auto x : ans[i])
      cout << x;
    cout << endl;
  }
}