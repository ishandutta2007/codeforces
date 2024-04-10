#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int maxRow = 1;
  while ((maxRow + 1) * (maxRow + 1) <= n)
    maxRow++;

  map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x] = min(cnt[x] + 1, maxRow);
  }

  vector<int> sz[700];
  for (auto [x, y] : cnt)
    sz[y].push_back(x);

  int ans = 0, numRow = 0, numCol = 0;
  for (int row = 1; row <= maxRow; row++)
  {
    int total = 0;
    for (int i = 1; i <= maxRow; i++)
      total += min(i, row) * sz[i].size();
    int col = total / row;
    if (col < row || row * col <= ans)
      continue;

    ans = row * col;
    numRow = row;
    numCol = col;
  }

  cout << ans << '\n' << numRow << ' ' << numCol << '\n';
  vector<int> rows[700];
  int curRow = 0;
  for (int i = maxRow; i; i--)
    for (int v : sz[i])
      for (int j = 0; j < min(i, numRow); j++)
        if (rows[curRow].size() < numCol)
        {
          rows[curRow].push_back(v);
          curRow = (curRow + 1) % numRow;
        }

  for (int i = 0; i < numRow; i++)
    for (int j = 0; j < numCol; j++)
      cout << rows[i][(j + numCol - i) % numCol] << " \n"[j == numCol - 1];
}