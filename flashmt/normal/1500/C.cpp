#include <bits/stdc++.h>
using namespace std;
const int N = 1515;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, a[N][N], b[N][N];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  vector<int> cntBad(n);
  for (int j = 0; j < n; j++)
    for (int i = 0; i + 1 < m; i++)
      if (b[i][j] > b[i + 1][j])
        cntBad[j]++;

  vector<int> goodCols, doneRow(m);
  for (int i = 0; i < n; i++)
    if (!cntBad[i])
      goodCols.push_back(i);

  for (int i = 0; i < goodCols.size(); i++)
  {
    int curCol = goodCols[i];
    for (int row = 0; row + 1 < m; row++)
      if (!doneRow[row] && b[row][curCol] < b[row + 1][curCol])
      {
        doneRow[row] = 1;
        for (int col = 0; col < n; col++)
          if (b[row][col] > b[row + 1][col])
          {
            cntBad[col]--;
            if (!cntBad[col])
              goodCols.push_back(col);
          }
      }
  }

  vector<int> id;
  for (int i = 0; i < m; i++)
    id.push_back(i);

  auto compRow = [&](int u, int v)
  {
    for (int col : goodCols)
      if (a[u][col] != a[v][col])
        return a[u][col] < a[v][col];
    return u < v;
  };

  sort(id.begin(), id.end(), compRow);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[id[i]][j] != b[i][j])
      {
        cout << -1 << endl;
        return 0;
      }

  cout << goodCols.size() << endl;
  reverse(goodCols.begin(), goodCols.end());
  for (int col : goodCols)
    cout << col + 1 << ' ';
}