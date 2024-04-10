#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string a[2222];
    cin >> n;
    vector<int> minX(10, n), maxX(10, -1), minY(10, n), maxY(10, -1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      for (int j = 0; j < n; j++)
      {
        int v = a[i][j] - '0';
        minX[v] = min(minX[v], i);
        maxX[v] = max(maxX[v], i);
        minY[v] = min(minY[v], j);
        maxY[v] = max(maxY[v], j);
      }
    }

    vector<int> ans(10, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        int v = a[i][j] - '0';
        ans[v] = max(ans[v], max(i, n - i - 1) * max(j - minY[v], maxY[v] - j));
        ans[v] = max(ans[v], max(j, n - j - 1) * max(i - minX[v], maxX[v] - i));
      }

    for (int i = 0; i < 10; i++)
      cout << ans[i] << " \n"[i == 9];
  }
}