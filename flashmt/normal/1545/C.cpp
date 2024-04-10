#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, a[1010][555], cntCol[555][555], isRemoved[1010];
set<pair<int, int>> colValues[555];
vector<int> rowIds[555][555];

void removeRow(int row)
{
  isRemoved[row] = 1;
  for (int j = 0; j < n; j++)
  {
    int v = a[row][j];
    colValues[j].erase({cntCol[j][v]--, v});
    if (cntCol[j][v])
      colValues[j].insert({cntCol[j][v], v});
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n * 2; i++)
      for (int j = 0; j < n; j++)
      {
        cin >> a[i][j];
        cntCol[j][--a[i][j]]++;
        rowIds[j][a[i][j]].push_back(i);
      }

    for (int j = 0; j < n; j++)
      for (int i = 0; i < n; i++)
        colValues[j].insert({cntCol[j][i], i});

    long long ans = 1;
    vector<int> goodRows;
    for (int turn = 0; turn < n; turn++)
    {
      int col = -1;
      for (int j = 0; j < n; j++)
        if (colValues[j].begin()->first == 1)
        {
          col = j;
          break;
        }

      if (col < 0)
        col = 0;

      int value = colValues[col].begin()->second;
      vector<int> rows;
      for (int i = 0; i < n * 2; i++)
        if (!isRemoved[i] && a[i][col] == value)
          rows.push_back(i);

      assert(!empty(rows) && size(rows) <= 2);

      removeRow(rows[0]);
      for (int j = 0; j < n; j++)
      {
        int v = a[rows[0]][j];
        for (int i : rowIds[j][v])
          if (!isRemoved[i])
            removeRow(i);
      }

      goodRows.push_back(rows[0]);
      ans = ans * size(rows) % BASE;
    }

    cout << ans << '\n';
    for (int x : goodRows)
      cout << x + 1 << ' ';
    cout << '\n';

    memset(isRemoved, 0, sizeof isRemoved);
    for (int i = 0; i < n; i++)
    {
      colValues[i].clear();
      for (int j = 0; j < n; j++)
      {
        cntCol[i][j] = 0;
        rowIds[i][j].clear();
      }
    }
  }
}